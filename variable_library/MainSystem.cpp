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
	MSG msg;

	while (true) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT) break;
		}
	}

	return;
}

void MainSystem::UnLoad() {

}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {
	
	///////////////////////////////
	//�V�X�e���N��
	//�eAPI�Ȃǂ�������
	///////////////////////////////
	MainSystem::Load();

	///////////////////////////////
	//�Q�[���Đ�
	//���b�Z�[�W���[�v�ɂ����
	//���t���[���X�V�����
	///////////////////////////////
	MainSystem::Update();

	//////////////////////////////
	//�V�X�e���I��
	//�eAPI�Ȃǂ��������
	//////////////////////////////
	MainSystem::UnLoad();

	return 0;
}