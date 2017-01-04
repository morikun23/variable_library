#include "WindowBase.h"
using namespace variableNS;

bool WindowBase::Register() {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW; 
	wcex.lpfnWndProc = this->WinProc; 
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(NULL);
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = m_name.c_str;
	wcex.hIconSm = NULL;

	return RegisterClassEx(&wcex);
}

bool WindowBase::Create() {
	this->m_handle = CreateWindowEx(
		m_windowStyle,				//拡張ウィンドウスタイル
		m_name.c_str,				//クラス名
		m_name.c_str,				//ウィンドウ名
		WS_OVERLAPPEDWINDOW,		//ウィンドウスタイル
		CW_USEDEFAULT,				//ウィンドウのx座標
		CW_USEDEFAULT,				//ウィンドウのy座標
		m_width,					//ウィンドウの幅
		m_height,					//ウィンドウの高さ
		(HWND)NULL,					//親ウィンドウのハンドル
		(HMENU)NULL,				//メニューハンドル
		GetModuleHandle(NULL),		//アプリケーションインスタンスのハンドル
		(LPVOID)NULL				//ウィンドウ作成データ
		);

	return m_handle != NULL;
}

void WindowBase::Open() {
	ShowWindow(m_handle, 0);
	UpdateWindow(m_handle);
}

void WindowBase::Close() {
	DestroyWindow(m_handle);
	UnregisterClass(m_name.c_str, GetModuleHandle(NULL));
}


LRESULT CALLBACK WindowBase::WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
