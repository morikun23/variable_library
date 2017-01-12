#ifndef MAINSYSTEM
#define MAINSYSTEM
///////////////////////////////////////////
//�N���X���FMainSystem
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�FDirectX�Ȃǃv���O�����̏������Ȃ�
//			�����\�z���Ă���N���X�ł��B
//�X�V�@�@�F
//H29/01/04�F�N���X�̍쐬
//H29/01/05�F�E�B���h�E�̐���
//H29/01/07�F�R���\�[���̕\����ǉ�
///////////////////////////////////////////
#include <Windows.h>
#include "MainWindow.h"
#include "Console.h"
#include "SceneManager.h"

using namespace variableNS;

class MainSystem {

private:
	//�g�p����E�B���h�E�̃|�C���^
	MainWindow* window;

public:
	
	MainSystem() {}
	~MainSystem() {}

	///////////////////////////////
	//������
	///////////////////////////////
	void Load();
	
	///////////////////////////////
	//���t���[���X�V
	///////////////////////////////
	void Update();

	///////////////////////////////
	//�I��
	///////////////////////////////
	void UnLoad();
};
#endif // !MAINSYSTEM