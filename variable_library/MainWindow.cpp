#include "MainWindow.h"

/////////////////////////////////////////
//デフォルトコンストラクタ
//ウィンドウのサイズは自動で決まります
/////////////////////////////////////////
MainWindow::MainWindow(HINSTANCE arg_hInstance){
	_width = DEFAULT_WIDTH;
	_height = DEFAULT_HEIGHT;
	_position = Vector2(200, 100);
	_windowStyle = WS_ACTIVECAPTION;
	_name = "MainWindow";
	if (Register(arg_hInstance)) {
		Create(arg_hInstance);
		Open();
	}
}

////////////////////////////////////////
//
////////////////////////////////////////
MainWindow::~MainWindow(){
	Close();
}

///////////////////////////////////////
//ウィンドウプロシージャ―
///////////////////////////////////////
LRESULT CALLBACK MainWindow::WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg){
	case WM_CREATE:
		std::cout << "created" << std::endl;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}