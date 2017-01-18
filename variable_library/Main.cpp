#include <Windows.h>
#include"MainSystem.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	MainSystem system(hInstance);

	///////////////////////////////
	//システム起動
	//各APIなどを初期化
	/////////////-//////////////////
	system.Load();

	///////////////////////////////
	//ゲーム再生
	//メッセージループによって
	//毎フレーム更新される
	///////////////////////////////
	MSG msg;

	while (true) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			system.Update();
			if (msg.message == WM_QUIT) break;
		}
	}

	//////////////////////////////
	//システム終了
	//各APIなどを解放する
	//////////////////////////////
	system.UnLoad();

	return 0;
}