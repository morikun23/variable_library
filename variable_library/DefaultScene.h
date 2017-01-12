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
//H29/01/11�F�p���������J�����o�ɂ��܂����B
//			 ����ɂ���āA�O�����璊�ۃC���^�[�t�F�C�X��
//			 �Q�Ƃł���悤�ɂȂ�܂����B
////////////////////////////////////////
#include "Scene.h"
#include <iostream>

using namespace variableNS;

class DefaultScene : public Scene {
	
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