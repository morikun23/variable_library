#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include "Main.h"
#include "Console.h"

using namespace variableNS;

// ウィンドウプロシージャ、ウィンドウに対するメッセージ処理を行う
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
		// ウィンドウが破棄されたとき
	case WM_DESTROY:
		PostQuitMessage(0);	// WM_QUITメッセージをメッセージキューに送る
		return 0;
	}
	// デフォルトのメッセージ処理を行う
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

bool CreateMainWindow(HINSTANCE hInstance,int nCmdShow) {
	const TCHAR* WC_BASIC = _T("BASIC_WINDOW");
	WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,WndProc, 0,0,hInstance,
		(HICON)LoadImage(NULL,MAKEINTRESOURCE(IDI_APPLICATION),IMAGE_ICON,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HCURSOR)LoadImage(NULL,MAKEINTRESOURCE(IDC_ARROW),IMAGE_CURSOR,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HBRUSH)GetStockObject(WHITE_BRUSH), NULL, WC_BASIC , NULL };
	// シンプルウィンドウクラス設定

	// シンプルウィンドウクラス登録
	if (!RegisterClassEx(&wcex))	return false;

	// ウィンドウ幅、高さはディスプレイに依存する。普通は4:3
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;

	// ウィンドウの作成
	HWND hWnd = CreateWindowEx(0, WC_BASIC,
		_T("Application"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);


	return true;

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	if (!CreateMainWindow(hInstance, nCmdShow)) { return false; }

	Main main;

	bool doing = true;
	
	// メッセージループ
	MSG msg = {};
	
	while (doing) {
		// アプリケーションに送られてくるメッセージをメッセージキューから取得する
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				doing = false;
			}
			//メッセージをデコードしてWinProcに渡す
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		main.Update();
	}

	main.UnLoad();
	return msg.wParam;
}