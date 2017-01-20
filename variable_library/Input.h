#ifndef INPUT
#define INPUT

//////////////////////////////////////////////////////////////////

//�N���X��: Input

//�쐬�ҁF����l����

//�Q�l�ɂ����T�C�g�� : http://www.tnksoft.com/reading/classgame/engine/02/026.php

//�T�v :�L�[�{�[�h�Ȃǂɂ��e���͋@�\���������N���X

//�X�V :


/////////////////////////////////////////////////////////////////

//���p����DirectInput�o�[�W�����̐錾  
#define DIRECTINPUT_VERSION 0x0800  
#include <dinput.h>  
#include <dxerr.h>
#include <tchar.h>
//DirectInput�Ɋ֘A���郉�C�u�����̃����N��錾  
#pragma comment(lib, "dinput8.lib")  
#pragma comment(lib, "dxguid.lib")  
//DirectInput�Ɋ֘A���郉�C�u�����̃����N��錾  
#pragma comment(lib, "DxErr.lib")  

namespace variableNS {

	//�C���v�b�g�N���X
	class Input {
	private:
		static LPDIRECTINPUT8 pInput;
		static LPDIRECTINPUTDEVICE8 pKeyDevice;
		static BYTE keydata[256];
	public:

		//DirectInput�̏���������(�R���X�g���N�^)
		Input() {
			pInput = nullptr;
			pKeyDevice = nullptr;
		}
		//DirectInput�̉������(�f�X�g���N�^)
		~Input();

		///////////////////////////// 
		//�L�[�{�[�h���̓��̓f�o�C�X�̓o�^
		/////////////////////////////
		static void Init(HINSTANCE, HWND);

		///////////////////////////// 
		//DirectInput����̓f�o�C�X�̉������
		/////////////////////////////
		static void Unregister();

		/////////////////////////////
		//���͏��̎擾
		/////////////////////////////
		static void Exec();

		/////////////////////////////////////
		//�w�肵���L�[�������ꂽ���̔����Ԃ�//
		/////////////////////////////////////
		static BOOL IsKeyDown(int key);
	};
}
#endif