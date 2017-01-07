#include"MainSystem.h"

void MainSystem::Load() {
	//////////////////////////////////
	//�E�B���h�E�̐���
	//////////////////////////////////
	window = new MainWindow();
	
	//////////////////////////////////
	//Direct3D�̏�����
	//////////////////////////////////


	//////////////////////////////////
	//DirectInput�̏�����
	//////////////////////////////////

	//////////////////////////////////
	//DirectSound�̏�����
	//////////////////////////////////

	
}

void MainSystem::Update() {
	

	return;
}

void MainSystem::UnLoad() {
	delete window;
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