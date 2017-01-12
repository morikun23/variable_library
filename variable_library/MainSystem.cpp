#include"MainSystem.h"

void MainSystem::Load() {
	//�f�o�b�O�p�R���\�[���̕\��
	Console::Instance().Open();
	std::cout << ">-- System start up" << std::endl;
	
	//�E�B���h�E�̐���
	window = new MainWindow();
	
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
	delete window;
	Console::Instance().Close();
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {
	
	MainSystem system;

	///////////////////////////////
	//�V�X�e���N��
	//�eAPI�Ȃǂ�������
	/////////////-//////////////////
	system.Load();

	///////////////////////////////
	//�Q�[���Đ�
	//���b�Z�[�W���[�v�ɂ����
	//���t���[���X�V�����
	///////////////////////////////
	MSG msg;

	while (true) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			system.Update();
			if (msg.message == WM_QUIT) break;
		}
	}

	//////////////////////////////
	//�V�X�e���I��
	//�eAPI�Ȃǂ��������
	//////////////////////////////
	system.UnLoad();

	return 0;
}
