#include "WindowBase.h"
using namespace variableNS;

////////////////////////////////
//ウィンドウを登録する
////////////////////////////////
bool WindowBase::Register() {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW; 
	wcex.lpfnWndProc = GetWindowProcedure;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(NULL);
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = m_name.c_str();
	wcex.hIconSm = NULL;

	return RegisterClassEx(&wcex) == 1;
}

//////////////////////////////
//ウィンドウを生成する
//////////////////////////////
bool WindowBase::Create() {
	m_handle = CreateWindowEx(
		m_windowStyle,				//拡張ウィンドウスタイル
		m_name.c_str(),				//クラス名
		m_name.c_str(),				//ウィンドウ名
		WS_OVERLAPPEDWINDOW,		//ウィンドウスタイル
		(int)m_position.x,			//ウィンドウのx座標
		(int)m_position.y,			//ウィンドウのy座標
		m_width,					//ウィンドウの幅
		m_height,					//ウィンドウの高さ
		(HWND)NULL,					//親ウィンドウのハンドル
		(HMENU)NULL,				//メニューハンドル
		GetModuleHandle(NULL),		//アプリケーションインスタンスのハンドル
		this						//ウィンドウ作成データ
		);

	
	return m_handle != NULL;
}

//////////////////////////////////////
//ウィンドウを開いて表示する
//////////////////////////////////////
void WindowBase::Open() {
	ShowWindow(m_handle, 0);
	UpdateWindow(m_handle);
}

/////////////////////////////////////
//ウィンドウを閉じる
/////////////////////////////////////
void WindowBase::Close() {
	DestroyWindow(m_handle);
	UnregisterClass(m_name.c_str(), GetModuleHandle(NULL));
}
///////////////////////////////////////
//ウィンドウプロシージャ
///////////////////////////////////////
LRESULT CALLBACK WindowBase::WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(m_handle, uMsg, wParam, lParam);
}
///////////////////////////////////////
//ウィンドウプロシージャを取得
///////////////////////////////////////
LRESULT CALLBACK WindowBase::GetWindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	
	WindowBase* window = (WindowBase*)GetWindowLong(hwnd,GWLP_USERDATA);
	if (window) {
		return window->WindowProcedure(hwnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}