#include "Input.h"

using namespace variableNS;

Input::Input() {
	for (int i = 0; i < KEY_LENGTH; i++) {
		//�L�[�̓��͏�Ԃ�������������
		keyIsDown[i] = false;
		keyIsPressed[i] = false;
	}
}
Input::~Input() {
	for (int i = 0; i < KEY_LENGTH; i++) {
		//�L�[�̏�Ԃ�S�Č��ɖ߂�
		keyIsDown[i] = false;
		keyIsPressed[i] = false;
	}
}


void Input::InputKeyCode(int key) {

}

bool Input::GetKeyDown(KeyCode keycode) {

}