#ifndef MAIN_WINDOW
#define MAIN_WINDOW

////////////////////////////////////////
//�N���X���FMainWindow
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�F�N�����ɍ쐬�����E�B���h�E���܂Ƃ߂܂����B
//�@�@�@�@�@�ȍ~�A�����Ő��������E�B���h�E�����C���Ƃ���
//�@�@�@�@�@�����܂��B
//H29/01/04�F�N���X�̍쐬
//H29/01/05�F�E�B���h�E�v���V�[�W����ǉ�
//H29/01/16�FWindowBase��public �ɂ��āA
//			 �O���N���X����A�N�Z�X�ł���悤�ɂ��܂����B
////////////////////////////////////////

#include <Windows.h>
#include "WindowBase.h"

using namespace variableNS;

namespace variableNS {
	class MainWindow : public WindowBase {
	private:
	public:
		//////////////////////////////////
		//�R���X�g���N�^
		//////////////////////////////////
		MainWindow(HINSTANCE);
		virtual ~MainWindow();

		LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM) override;

	};
}
#endif // !MAIN_WINDOW
