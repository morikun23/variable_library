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
//H29/01/16�FWinMain�֐���Main.cpp�Ɉړ�
//H29/01/16�Fhwnd�AhInstance�̃n���h���Q������ꂼ��ǉ�
///////////////////////////////////////////
#include <Windows.h>

#include "Direct3DManager.h"
#include "MainWindow.h"
#include "Console.h"
#include "SceneManager.h"

using namespace variableNS;

class MainSystem {

private:
	//�C���X�^���X�n���h��
	HINSTANCE _hInstance;
	
	//�g�p����E�B���h�E�̃|�C���^
	MainWindow* _window;
	
public:

	MainSystem(HINSTANCE arg_hInstance) { _hInstance = arg_hInstance; }
	virtual ~MainSystem() {};
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