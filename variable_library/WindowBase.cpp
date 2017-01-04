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
		m_windowStyle,				//�g���E�B���h�E�X�^�C��
		m_name.c_str,				//�N���X��
		m_name.c_str,				//�E�B���h�E��
		WS_OVERLAPPEDWINDOW,		//�E�B���h�E�X�^�C��
		CW_USEDEFAULT,				//�E�B���h�E��x���W
		CW_USEDEFAULT,				//�E�B���h�E��y���W
		m_width,					//�E�B���h�E�̕�
		m_height,					//�E�B���h�E�̍���
		(HWND)NULL,					//�e�E�B���h�E�̃n���h��
		(HMENU)NULL,				//���j���[�n���h��
		GetModuleHandle(NULL),		//�A�v���P�[�V�����C���X�^���X�̃n���h��
		(LPVOID)NULL				//�E�B���h�E�쐬�f�[�^
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
