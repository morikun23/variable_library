#include "MainWindow.h"
using namespace variableNS;

/////////////////////////////////////////
//�f�t�H���g�R���X�g���N�^
//�E�B���h�E�̃T�C�Y�͎����Ō��܂�܂�
/////////////////////////////////////////
MainWindow::MainWindow(){
	
	m_width = m_DEFAULT_WIDTH;
	m_height = m_DEFAULT_HEIGHT;
	m_windowStyle = WS_ACTIVECAPTION;
	Register(this);
	Create();
	Open();
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
LRESULT CALLBACK MainWindow::WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg){
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
