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
		//キーの長さ(一般的に256)
		static const int KEY_LENGTH = 256;
		//キーが押されていることを格納（継続）
		bool keyIsDown[KEY_LENGTH];
		bool keyIsPressed[KEY_LENGTH];
		
		//ユーザーが入力したテキスト
		std::string text;

	public:
		Input();
		~Input();
		static void InputKeyCode(int);
		bool GetKeyDown(KeyCode);
	};
}
#endif // ! INPUT
