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
	Register();
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
//
///////////////////////////////////////
LRESULT CALLBACK WindowBase::WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
