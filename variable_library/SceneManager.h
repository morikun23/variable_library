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
//H29/01/04�F�N���X�̍쐬
//H29/01/08�FGetCurrentScene�֐����C��
//			 ���Đ�����Scene�N���X���擾
//			 �@���Đ�����Scene�N���X�̃A�h���X���擾
//////////////////////////////////////

#include <Windows.h>
#include <iostream>
#include "Scene.h"

using namespace variableNS;

namespace variableNS {
	class SceneManager {
	private:
		//�o�^���ꂽ�V�[��
		Scene *scene;
		//���݂̃V�[��
		int currentScene;

	public:
		///////////////////////////////
		//�V�[���̓o�^
		///////////////////////////////
		void SceneRegister(Scene*);

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
		void SceneTransition(Scene*);

		/////////////////////////////
		//���݂̃V�[�����擾����
		/////////////////////////////
		Scene& GetCurrentScene();
	};
}
#endif // !SCENE_MANAGER