#ifndef MAINWINDOW
#define MAINWINDOW

////////////////////////////////////////
//�N���X���FMainWindow
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�F�N�����ɍ쐬�����E�B���h�E���܂Ƃ߂܂����B
//�@�@�@�@�@�ȍ~�A�����Ő��������E�B���h�E�����C���Ƃ���
//�@�@�@�@�@�����܂��B
////////////////////////////////////////

#include <Windows.h>
#include "WindowBase.h"

namespace variableNS {
	class MainWindow : WindowBase {
	private:
		
	public:
		//////////////////////////////////
		//�R���X�g���N�^
		//////////////////////////////////
		MainWindow();
		~MainWindow();

		 LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM) override;

	};
}
#endif // !MAINWINDOW
