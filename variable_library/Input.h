#ifndef  INPUT
#define INPUT

#include<iostream>

namespace variableNS {
	
	enum KeyCode {
		A = 0x41,
		B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z
	};
	
	class Input {
	private:
		//�L�[�̒���(��ʓI��256)
		static const int KEY_LENGTH = 256;
		//�L�[��������Ă��邱�Ƃ��i�[�i�p���j
		bool keyIsDown[KEY_LENGTH];
		bool keyIsPressed[KEY_LENGTH];
		
		//���[�U�[�����͂����e�L�X�g
		std::string text;

	public:
		Input();
		~Input();
		static void InputKeyCode(int);
		bool GetKeyDown(KeyCode);
	};
}
#endif // ! INPUT
