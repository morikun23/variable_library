#include "DefaultScene.h"
#include "Input.h"
/////////////////////////////////
//�V�[���˓����ɌĂ΂��
/////////////////////////////////
void DefaultScene::OnEnter() {
	std::cout << ">-- \"default scene\" entered..." << std::endl;
}

/////////////////////////////////
//�V�[���Đ����A���t���[���Ă΂��
/////////////////////////////////
void DefaultScene::OnUpdate() {
	if (Input::IsKeyDown(0x39)) {
		std::cout << "�X�y�[�X�������ꂽ��" << std::endl;
	}
}

/////////////////////////////////
//�V�[���I�����ɌĂ΂��
/////////////////////////////////
void DefaultScene::OnExit() {
	std::cout << ">-- \"default scene\" exited..." << std::endl;
}
