#include"InputV.h"
using namespace variableNS;
using namespace std;

//DirectInputに関連するライブラリのリンクを宣言  


//入力デバイス登録の処理
void InputV::Init(HINSTANCE hInstance,HWND hwnd) {
	if (pInput == NULL) {
		//インターフェイスの取得
		HRESULT hr;
		hr = DirectInput8Create(
		
			hInstance,         // ソフトのインスタンスハンドル  
			DIRECTINPUT_VERSION,    // DirectInputのバージョン  
			IID_IDirectInput8,      // 取得するインターフェイスのタイプ  
			(LPVOID*)&pInput,       // インターフェイスの格納先  
			NULL                    // COM集成の制御オブジェクト（使わないのでNULL）  
		);
		if (FAILED(hr)) {
			DXTRACE_MSG(_T("DirectInputの初期化に失敗しました"));
			return;
		}

		hr = pInput->CreateDevice(
			GUID_SysKeyboard,   // 受け付ける入力デバイス  
			&pKeyDevice,        // IDirectInputDevice8格納先  
			NULL                // COM集成の制御オブジェクト（使わないのでNULL）  
		);

		if (FAILED(hr)) {
			DXTRACE_MSG(_T("DirectInputDeviceの初期化に失敗しました"));
			return;
		}
		// データフォーマットの設定  
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);

		////////////////////////////////////////////////////////////////
		//取得するタイミング
	    //DISCL_BACKGROUND	ウィンドウがアクティブになっていなくても常に取得
		//DISCL_FOREGROUND	ウィンドウがアクティブになっているときのみ取得
		//取得データの提供先
		//DISCL_EXCLUSIVE	DirectInputを呼び出したアプリのみに限定
		//DISCL_NONEXCLUSIVE	すべてのアプリケーションに提供
		//Windowsキーのロック
		//DISCL_NOWINKEY	ウィンドウズキーをロックして無効にする
		////////////////////////////////////////////////////////////////

		pKeyDevice->SetCooperativeLevel(hwnd,DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

		// キーバッファの初期化  
		ZeroMemory(keydata, 256);
	}
}

void InputV::Unregister() {
	if (pKeyDevice)
	{
		pKeyDevice->Unacquire();
		pKeyDevice->Release();
		pKeyDevice = 0;
	}

	if (pInput)
	{
		pInput->Release();
		pInput = 0;
	}
}

//デバイスからの入力情報の取得の処理
void InputV::Exec()
{
	if (pKeyDevice) {
		// 入力の受け付け開始  
		pKeyDevice->Acquire();

		// データを取得（256は取得するデータのサイズ）  
		pKeyDevice->GetDeviceState(256, keydata);
	}
}

//指定したキーが押されたか判定を返す
BOOL InputV::IsKeyDown(int key)
{
	if (pKeyDevice == NULL) return FALSE;

	return (keydata[key] & 0x80) ? TRUE : FALSE;
}
