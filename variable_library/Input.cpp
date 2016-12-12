#include "Input.h"

using namespace variableNS;

Input::Input() {
	for (int i = 0; i < KEY_LENGTH; i++) {
		//キーの入力状態を初期化させる
		keyIsDown[i] = false;
		keyIsPressed[i] = false;
	}
}
Input::~Input() {
	for (int i = 0; i < KEY_LENGTH; i++) {
		//キーの状態を全て元に戻す
		keyIsDown[i] = false;
		keyIsPressed[i] = false;
	}
}


void Input::InputKeyCode(int key) {

}

bool Input::GetKeyDown(KeyCode keycode) {

}