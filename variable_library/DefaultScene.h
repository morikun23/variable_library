#ifndef DEFAULT_SCENE
#define DEFAULT_SCENE

////////////////////////////////////////
//�N���X���FDefaultScene
//�쐬�ҁ@�F�X�c�@��
//�T�v	�@�F�ݒ�Ȃ��̏ꍇ�A�f�t�H���g��
//			�p�ӂ����V�[���B
//			�ЂȌ`�Ƃ��Ă��g�p�ł��܂��B
//�X�V	�@�F
//H29/01/08�F�N���X�̍쐬
////////////////////////////////////////
#include "Scene.h"

using namespace variableNS;

class DefaultScene : Scene {
	
	//////////////////////////////
	//�V�[���J�n
	//////////////////////////////
	void OnEnter() override;

	//////////////////////////////
	//�V�[���Đ���
	//////////////////////////////
	void OnUpdate() override;

	//////////////////////////////
	//�V�[���I��
	//////////////////////////////
	void OnExit() override;
};

#endif DEFAULT_SCENE