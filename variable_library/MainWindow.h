#ifndef MAINWINDOW
#define MAINWINDOW

////////////////////////////////////////
//�N���X���FMainWindow
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�F�N�����ɍ쐬�����E�B���h�E���܂Ƃ߂܂����B
//�@�@�@�@�@�ȍ~�A�����Ő��������E�B���h�E�����C���Ƃ���
//�@�@�@�@�@�����܂��B
//H29/01/04�F�N���X�̍쐬
//H29/01/05�F�E�B���h�E�v���V�[�W����ǉ�
////////////////////////////////////////

#include <Windows.h>
#include "WindowBase.h"

using namespace variableNS;

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
