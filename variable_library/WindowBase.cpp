#include "WindowBase.h"
using namespace variableNS;

////////////////////////////////
//�E�B���h�E��o�^����
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
//�E�B���h�E�𐶐�����
//////////////////////////////
bool WindowBase::Create() {
	m_handle = CreateWindowEx(
		m_windowStyle,				//�g���E�B���h�E�X�^�C��
		m_name.c_str(),				//�N���X��
		m_name.c_str(),				//�E�B���h�E��
		WS_OVERLAPPEDWINDOW,		//�E�B���h�E�X�^�C��
		(int)m_position.x,			//�E�B���h�E��x���W
		(int)m_position.y,			//�E�B���h�E��y���W
		m_width,					//�E�B���h�E�̕�
		m_height,					//�E�B���h�E�̍���
		(HWND)NULL,					//�e�E�B���h�E�̃n���h��
		(HMENU)NULL,				//���j���[�n���h��
		GetModuleHandle(NULL),		//�A�v���P�[�V�����C���X�^���X�̃n���h��
		this						//�E�B���h�E�쐬�f�[�^
		);

	
	return m_handle != NULL;
}

//////////////////////////////////////
//�E�B���h�E���J���ĕ\������
//////////////////////////////////////
void WindowBase::Open() {
	ShowWindow(m_handle, 0);
	UpdateWindow(m_handle);
}

/////////////////////////////////////
//�E�B���h�E�����
/////////////////////////////////////
void WindowBase::Close() {
	DestroyWindow(m_handle);
	UnregisterClass(m_name.c_str(), GetModuleHandle(NULL));
}
///////////////////////////////////////
//�E�B���h�E�v���V�[�W��
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
//�E�B���h�E�v���V�[�W�����擾
///////////////////////////////////////
LRESULT CALLBACK WindowBase::GetWindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	
	WindowBase* window = (WindowBase*)GetWindowLong(hwnd,GWLP_USERDATA);
	if (window) {
		return window->WindowProcedure(hwnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}