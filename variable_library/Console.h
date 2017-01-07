#ifndef CONSOLE
#define CONSOLE


////////////////////////////////////
//�N���X���FConsole
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�F�f�o�b�O�p�̃R���\�[���E�B���h�E��\�����܂��B
//�X�V�@�@�F
//H28/12/05�F�N���X�̍쐬
///////////////////////////////////
#include<iostream>
#include <Windows.h>

namespace variableNS {
	class Console {
	private:
		//�R���\�[���E�B���h�E�̃n���h��
		FILE *m_consoleHandle;
		//�E�B���h�E���J���Ă��邩
		bool isOpened;

		Console(){}
		~Console(){};
	public:
		static Console& Instance() {
			static Console instance;
			return instance;
		}

		//////////////////////////////////
		//�R���\�[���̕\��
		//////////////////////////////////
		void Open();

		//////////////////////////////////
		//�R���\�[���̔�\��
		//////////////////////////////////
		void Close();

	};

}
#endif // !CONSOLE