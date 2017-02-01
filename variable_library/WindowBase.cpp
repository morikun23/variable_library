#include "WindowBase.h"

////////////////////////////////
//�E�B���h�E��o�^����
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
//�E�B���h�E�𐶐�����
//////////////////////////////
bool WindowBase::Create(HINSTANCE arg_hInstance) {
	_handle = CreateWindowEx(
		_windowStyle,				//�g���E�B���h�E�X�^�C��
		_name.c_str(),				//�N���X��
		_name.c_str(),				//�E�B���h�E��
		WS_OVERLAPPEDWINDOW,		//�E�B���h�E�X�^�C��
		(int)_position._x,			//�E�B���h�E��x���W
		(int)_position._y,			//�E�B���h�E��y���W
		_width,					//�E�B���h�E�̕�
		_height,					//�E�B���h�E�̍���
		(HWND)NULL,					//�e�E�B���h�E�̃n���h��
		(HMENU)NULL,				//���j���[�n���h��
		arg_hInstance,		//�A�v���P�[�V�����C���X�^���X�̃n���h��
		this						//�E�B���h�E�쐬�f�[�^
		);
	
	if (_handle) {
		std::cout << ">-- window created" << std::endl;
	}

	return _handle;
}

//////////////////////////////////////
//�E�B���h�E���J���ĕ\������
//////////////////////////////////////
void WindowBase::Open() {
	ShowWindow(_handle, SW_SHOW);
	UpdateWindow(_handle);
	std::cout << ">-- window opend" << std::endl;
}

/////////////////////////////////////
//�E�B���h�E�����
/////////////////////////////////////
void WindowBase::Close() {
	DestroyWindow(_handle);
	UnregisterClass(_name.c_str(), GetModuleHandle(NULL));
	std::cout << ">-- window closed" << std::endl;
}
///////////////////////////////////////
//�E�B���h�E�v���V�[�W��
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
//�E�B���h�E�v���V�[�W�����擾
///////////////////////////////////////
LRESULT CALLBACK WindowBase::GetWindowProcedure(HWND arg_hWnd, UINT arg_uMsg, WPARAM arg_wParam, LPARAM arg_lParam) {
	
	WindowBase* window = (WindowBase*)GetWindowLong(arg_hWnd,GWLP_USERDATA);
	if (window) {
		return window->WindowProcedure(arg_hWnd, arg_uMsg, arg_wParam, arg_lParam);
	}
	return DefWindowProc(arg_hWnd, arg_uMsg, arg_wParam, arg_lParam);
}

//////////////////////////////////////
//�E�B���h�E�n���h�����擾
//////////////////////////////////////
HWND WindowBase::GetHandle() {
	return _handle;
}

//////////////////////////////////////
//�E�B���h�E�̕����擾
//////////////////////////////////////
int WindowBase::GetWidth() {
	return _width;
}

//////////////////////////////////////
//�E�B���h�E�̍������擾
//////////////////////////////////////
int WindowBase::GetHeight() {
	return _height;
}