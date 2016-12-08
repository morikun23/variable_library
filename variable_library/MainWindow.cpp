#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include "Main.h"
#include "Console.h"

using namespace variableNS;

// �E�B���h�E�v���V�[�W���A�E�B���h�E�ɑ΂��郁�b�Z�[�W�������s��
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
		// �E�B���h�E���j�����ꂽ�Ƃ�
	case WM_DESTROY:
		PostQuitMessage(0);	// WM_QUIT���b�Z�[�W�����b�Z�[�W�L���[�ɑ���
		return 0;
	}
	// �f�t�H���g�̃��b�Z�[�W�������s��
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

bool CreateMainWindow(HINSTANCE hInstance,int nCmdShow) {
	const TCHAR* WC_BASIC = _T("BASIC_WINDOW");
	WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,WndProc, 0,0,hInstance,
		(HICON)LoadImage(NULL,MAKEINTRESOURCE(IDI_APPLICATION),IMAGE_ICON,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HCURSOR)LoadImage(NULL,MAKEINTRESOURCE(IDC_ARROW),IMAGE_CURSOR,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HBRUSH)GetStockObject(WHITE_BRUSH), NULL, WC_BASIC , NULL };
	// �V���v���E�B���h�E�N���X�ݒ�

	// �V���v���E�B���h�E�N���X�o�^
	if (!RegisterClassEx(&wcex))	return false;

	// �E�B���h�E���A�����̓f�B�X�v���C�Ɉˑ�����B���ʂ�4:3
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;

	// �E�B���h�E�̍쐬
	HWND hWnd = CreateWindowEx(0, WC_BASIC,
		_T("Application"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);


	return true;

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	if (!CreateMainWindow(hInstance, nCmdShow)) { return false; }

	Main main;

	bool doing = true;
	
	// ���b�Z�[�W���[�v
	MSG msg = {};
	
	while (doing) {
		// �A�v���P�[�V�����ɑ����Ă��郁�b�Z�[�W�����b�Z�[�W�L���[����擾����
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				doing = false;
			}
			//���b�Z�[�W���f�R�[�h����WinProc�ɓn��
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		main.Update();
	}

	main.UnLoad();
	return msg.wParam;
}