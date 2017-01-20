#ifndef INPUT
#define INPUT

//////////////////////////////////////////////////////////////////

//クラス名: Input

//作成者：小野瑛七勢

//参考にしたサイト等 : http://www.tnksoft.com/reading/classgame/engine/02/026.php

//概要 :キーボードなどによる各入力機能をもったクラス

//更新 :


/////////////////////////////////////////////////////////////////

//利用するDirectInputバージョンの宣言  
#define DIRECTINPUT_VERSION 0x0800  
#include <dinput.h>  
#include <dxerr.h>
#include <tchar.h>
//DirectInputに関連するライブラリのリンクを宣言  
#pragma comment(lib, "dinput8.lib")  
#pragma comment(lib, "dxguid.lib")  
//DirectInputに関連するライブラリのリンクを宣言  
#pragma comment(lib, "DxErr.lib")  

namespace variableNS {

	//インプットクラス
	class Input {
	private:
		static LPDIRECTINPUT8 pInput;
		static LPDIRECTINPUTDEVICE8 pKeyDevice;
		static BYTE keydata[256];
	public:

		//DirectInputの初期化処理(コンストラクタ)
		Input() {
			pInput = nullptr;
			pKeyDevice = nullptr;
		}
		//DirectInputの解放処理(デストラクタ)
		~Input();

		///////////////////////////// 
		//キーボード等の入力デバイスの登録
		/////////////////////////////
		static void Init(HINSTANCE, HWND);

		///////////////////////////// 
		//DirectInputや入力デバイスの解放処理
		/////////////////////////////
		static void Unregister();

		/////////////////////////////
		//入力情報の取得
		/////////////////////////////
		static void Exec();

		/////////////////////////////////////
		//指定したキーが押されたかの判定を返す//
		/////////////////////////////////////
		static BOOL IsKeyDown(int key);
	};
}
#endif