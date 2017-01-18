#include "MainWindow.h"

/////////////////////////////////////////
//�f�t�H���g�R���X�g���N�^
//�E�B���h�E�̃T�C�Y�͎����Ō��܂�܂�
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
//�E�B���h�E�v���V�[�W���\
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