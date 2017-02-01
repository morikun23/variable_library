#include"MainSystem.h"

void MainSystem::Load() {
	
	//�f�o�b�O�p�R���\�[���̕\��
	Console::Instance().Open();
	std::cout << ">-- System start up" << std::endl;
	
	//�E�B���h�E�̐���
	_window = new MainWindow(_hInstance);
	
	//Direct3D�̏�����
	//������A�X�c�������\��

	//DirectInput�̏�����
	//����A����̃N���X����ꕔ�����\��

	//DirectSound�̏�����
	//����A�b��̃N���X���瓝���\��

	//�V�[���̍Đ�
	SceneManager::Instance().ScenePlay(new DefaultScene());
}

void MainSystem::Update() {
	//���ݍĐ����̃V�[�����X�V
	SceneManager::Instance().SceneUpdate();
}

void MainSystem::UnLoad() {
	//�V�[���̏I��
	SceneManager::Instance().SceneEnd();
	delete _window;
	Console::Instance().Close();
}