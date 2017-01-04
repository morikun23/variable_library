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
namespace variableNS {
	class WindowBase {
	
	private:
		
	protected:
		/////////////////////////////////////
		//�E�B���h�E�̓o�^
		////////////////////////////////////
		virtual bool Register();
		//�f�t�H���g�l
		const int m_DEFAULT_WIDTH = 640;
		const int m_DEFAULT_HEIGHT = 480;

	public:
		std::wstring m_name;
		float m_width;
		float m_height;
		HWND m_handle;
		DWORD m_windowStyle;
		
		///////////////////////////////////
		//�E�B���h�E�v���V�[�W��
		//////////////////////////////////
		virtual LRESULT CALLBACK WinProc(HWND,UINT,WPARAM,LPARAM);

		virtual bool Create();
		virtual void Open();
		virtual void Close();
	};
}
#endif // !WindowBase