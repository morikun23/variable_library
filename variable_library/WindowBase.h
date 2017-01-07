#ifndef WindowBase
#define WINDOWBASE

/////////////////////////////////////
//�N���X���FWindowBase
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�F�E�B���h�E�̊�ՂƂȂ�v���p�e�B
//�X�V�@�@�F
//H28/12/22�F�N���X�̍쐬
////////////////////////////////////
#include <Windows.h>
#include <iostream>
#include"Vector2.h"
namespace variableNS {
	class WindowBase {
	
	private:
		
	protected:
		//�E�B���h�E�̍��W
		Vector2 m_position;

		//�E�B���h�E�̕�
		int m_width;

		//�E�B���h�E�̍���
		int m_height;

		//�E�B���h�E��
		std::string m_name;

		//�E�B���h�E�n���h��
		HWND m_handle;

		//�E�B���h�E�X�^�C��
		DWORD m_windowStyle;

		//�f�t�H���g�l
		const int m_DEFAULT_WIDTH = 640;
		const int m_DEFAULT_HEIGHT = 480;

		
		/////////////////////////////////////
		//�E�B���h�E�̓o�^
		////////////////////////////////////
		virtual bool Register();
		
		////////////////////////////////////
		//�E�B���h�E�̐���
		////////////////////////////////////
		virtual bool Create();

		////////////////////////////////////
		//�E�B���h�E�̕\��
		////////////////////////////////////
		virtual void Open();

		////////////////////////////////////
		//�E�B���h�E�̔�\��
		////////////////////////////////////
		virtual void Close();

	public:
		
		///////////////////////////////////
		//�E�B���h�E�v���V�[�W��
		//////////////////////////////////
		virtual LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);
		
		//////////////////////////////////
		//�E�B���h�E�v���V�[�W�����擾����
		//////////////////////////////////
		static LRESULT CALLBACK GetWindowProcedure(HWND, UINT, WPARAM, LPARAM);
		
	};
}
#endif // !WindowBase