#ifndef WINDOW_BASE
#define WINDOW_BASE

/////////////////////////////////////
//�N���X���FWindowBase
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�F�E�B���h�E�̊�ՂƂȂ�v���p�e�B
//�X�V�@�@�F
//H28/12/22�F�N���X�̍쐬
//H29/01/05�FWindowProcedure��ǉ�
//H29/01/08�FGetHandle�֐���ǉ�
//H29/01/18�FRegister�ACreate�֐����C��
//H29/01/19�FGetWidth�AGetHeight�֐���ǉ�
////////////////////////////////////

#include <Windows.h>
#include <iostream>
#include"Vector2.h"

using namespace variableNS;

namespace variableNS {
	class WindowBase {
	
	private:
		
	protected:
		//�E�B���h�E�̍��W
		Vector2 _position;

		//�E�B���h�E�̕�
		int _width;

		//�E�B���h�E�̍���
		int _height;

		//�E�B���h�E��
		std::string _name;

		//�E�B���h�E�n���h��
		HWND _handle;

		//�E�B���h�E�X�^�C��
		DWORD _windowStyle;

		//�f�t�H���g�l
		const int DEFAULT_WIDTH = 640;
		const int DEFAULT_HEIGHT = 480;

		/////////////////////////////////////
		//�E�B���h�E�̓o�^
		////////////////////////////////////
		bool Register(HINSTANCE);
		
		////////////////////////////////////
		//�E�B���h�E�̐���
		////////////////////////////////////
		bool Create(HINSTANCE);

		////////////////////////////////////
		//�E�B���h�E�̕\��
		////////////////////////////////////
		void Open();

		////////////////////////////////////
		//�E�B���h�E�̔�\��
		////////////////////////////////////
		void Close();

	public:
		
		///////////////////////////////////
		//�E�B���h�E�v���V�[�W��
		//////////////////////////////////
		virtual LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);
		
		//////////////////////////////////
		//�E�B���h�E�v���V�[�W�����擾����
		//////////////////////////////////
		static LRESULT CALLBACK GetWindowProcedure(HWND, UINT, WPARAM, LPARAM);
		
		//////////////////////////////////
		//�E�B���h�E�n���h�����擾
		//////////////////////////////////
		HWND GetHandle();
		
		//////////////////////////////////
		//�E�B���h�E�̕����擾
		//////////////////////////////////
		int GetWidth();

		//////////////////////////////////
		//�E�B���h�E�̍������擾
		//////////////////////////////////
		int GetHeight();
	};
}
#endif // !WINDOW_BASE