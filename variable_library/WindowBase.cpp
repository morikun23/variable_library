#include "WindowBase.h"

////////////////////////////////
//ウィンドウを登録する
////////////////////////////////
bool WindowBase::Register(HINSTANCE arg_hInstance) {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW; 
	wcex.lpfnWndProc = GetWindowProcedure;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = arg_hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _name.c_str();
	wcex.hIconSm = NULL;
	
	int result = RegisterClassEx(&wcex);
	
	if (result) {
		std::cout << ">-- window registered" << std::endl;
	}
	return result;
}

//////////////////////////////
//ウィンドウを生成する
//////////////////////////////
bool WindowBase::Create(HINSTANCE arg_hInstance) {
	_handle = CreateWindowEx(
		_windowStyle,				//拡張ウィンドウスタイル
		_name.c_str(),				//クラス名
		_name.c_str(),				//ウィンドウ名
		WS_OVERLAPPEDWINDOW,		//ウィンドウスタイル
		(int)_position._x,			//ウィンドウのx座標
		(int)_position._y,			//ウィンドウのy座標
		_width,					//ウィンドウの幅
		_height,					//ウィンドウの高さ
		(HWND)NULL,					//親ウィンドウのハンドル
		(HMENU)NULL,				//メニューハンドル
		arg_hInstance,		//アプリケーションインスタンスのハンドル
		this						//ウィンドウ作成データ
		);
	
	if (_handle) {
		std::cout << ">-- window created" << std::endl;
	}

	return _handle;
}

//////////////////////////////////////
//ウィンドウを開いて表示する
//////////////////////////////////////
void WindowBase::Open() {
	ShowWindow(_handle, SW_SHOW);
	UpdateWindow(_handle);
	std::cout << ">-- window opend" << std::endl;
}

/////////////////////////////////////
//ウィンドウを閉じる
/////////////////////////////////////
void WindowBase::Close() {
	DestroyWindow(_handle);
	UnregisterClass(_name.c_str(), GetModuleHandle(NULL));
	std::cout << ">-- window closed" << std::endl;
}
///////////////////////////////////////
//ウィンドウプロシージャ
///////////////////////////////////////
LRESULT CALLBACK WindowBase::WindowProcedure(HWND arg_hWnd, UINT arg_uMsg, WPARAM arg_wParam, LPARAM arg_lParam) {
	switch (arg_uMsg){
	case WM_CREATE:
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(_handle, arg_uMsg, arg_wParam, arg_lParam);
}
///////////////////////////////////////
//ウィンドウプロシージャを取得
///////////////////////////////////////
LRESULT CALLBACK WindowBase::GetWindowProcedure(HWND arg_hWnd, UINT arg_uMsg, WPARAM arg_wParam, LPARAM arg_lParam) {
	
	WindowBase* window = (WindowBase*)GetWindowLong(arg_hWnd,GWLP_USERDATA);
	if (window) {
		return window->WindowProcedure(arg_hWnd, arg_uMsg, arg_wParam, arg_lParam);
	}
	return DefWindowProc(arg_hWnd, arg_uMsg, arg_wParam, arg_lParam);
}

//////////////////////////////////////
//ウィンドウハンドルを取得
//////////////////////////////////////
HWND WindowBase::GetHandle() {
	return _handle;
}

//////////////////////////////////////
//ウィンドウの幅を取得
//////////////////////////////////////
int WindowBase::GetWidth() {
	return _width;
}

//////////////////////////////////////
//ウィンドウの高さを取得
//////////////////////////////////////
int WindowBase::GetHeight() {
	return _height;
}