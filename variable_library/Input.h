#ifndef  INPUT
#define INPUT
//////////////////////////////////////////
//�N���X���FInput
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�F�f�o�C�X�̓��͏�ԂȂǂ������Ă��܂��B
//			�Ή��f�o�C�X�͈ȉ��̒ʂ�ł��B
//			�E�}�E�X
//			�E�L�[�{�[�h
//			�E�W���C�X�e�B�b�N
//�X�V�@�@�F
//
//////////////////////////////////////////

#include<dinput.h>
namespace variableNS {

	//�L�[�R�[�h�ꗗ
	enum KeyCode {
		A = DIK_A, B = DIK_B, C = DIK_C, D = DIK_D, E = DIK_E,
		F = DIK_F, G = DIK_G, H = DIK_H, I = DIK_I, J = DIK_J,
		K = DIK_K, L = DIK_L, M = DIK_M, N = DIK_N, O = DIK_O,
		P = DIK_P, Q = DIK_Q, R = DIK_R, S = DIK_S, T = DIK_T,
		U = DIK_U, V = DIK_V, W = DIK_W, X = DIK_X, Y = DIK_Y,
		Z = DIK_Z, Space = DIK_SPACE,
		LeftAlt = DIK_LALT, RightAlt = DIK_RALT,
	};

	class Input {
	private:

		//�L�[�̒���(��ʓI��256)
		static const int KEY_LENGTH = 256;
		//�L�[��������Ă��邱�Ƃ��i�[�i�p���j
		static bool keyIsDown[KEY_LENGTH];
		static bool keyIsPressed[KEY_LENGTH];
		
		
	public:

		//////////////////////////////////////
		//������
		/////////////////////////////////////
		void Initialize();
		void GetDeviceState();
		
		static void InputKeyCode(int);
		static bool GetKeyDown(KeyCode);
	};
}
#endif // ! INPUT
