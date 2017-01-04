#ifndef SCENE_MANAGER
#define SCENE_MANAGER

///////////////////////////////////////
//�N���X���FSceceManager
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�F�Q�[�����̕����̃V�[���̊Ǘ����s���܂��B
//			�E�V�[���Đ�
//			�E�V�[���J��
//			�E�V�[���I��
//			�Ƃ������V�[���̓����ɂ��Ďd�����܂��B
//�X�V	�@�F
//////////////////////////////////////

#include <Windows.h>
#include <iostream>
#include "Scene.h"

namespace variableNS {
	class SceneManager {
	private:
		//�o�^���ꂽ�V�[��
		variableNS::Scene *scene;
		//���݂̃V�[��
		int currentScene;

	public:
		///////////////////////////////
		//�V�[���̓o�^
		///////////////////////////////
		void SceneRegister(variableNS::Scene *scene);

		///////////////////////////////
		//�V�[���̍Đ�
		///////////////////////////////
		void ScenePlay();
		
		//////////////////////////////
		//�V�[���̏I��
		//////////////////////////////
		void SceneEnd();

		//////////////////////////////
		//�V�[���J��
		//////////////////////////////
		void SceneTransition(variableNS::Scene *scene);

		/////////////////////////////
		//���݂̃V�[�����擾����
		/////////////////////////////
		variableNS::Scene GetcurrentScene();
	};
}
#endif // !SCENE_MANAGER