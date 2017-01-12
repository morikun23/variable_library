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
//H29/01/11�FSingleton�\���ɏC��
//H29/01/12�FSceneUpdate�֐���
//			 SceneEnd�֐���ǉ�
//			 �܂��A������SceneTransition�֐��̃��t�@�N�^�����O���s���A
//			 �����o�֐����g�p���āA��d�Ǘ���h���܂����B
//////////////////////////////////////

#include <Windows.h>
#include <iostream>
#include "Scene.h"
#include "DefaultScene.h"

namespace variableNS {
	class SceneManager {
	private:
		//���݂̃V�[��
		Scene *m_currentScene;

	public:
		
		//////////////////////////////////
		//Singleton�\��
		//�p�ӂ���Ă���C���X�^���X���擾
		//return�F�B��̃C���X�^���X
		//////////////////////////////////
		static SceneManager& Instance() {
			static SceneManager instance;
			return instance;
		}

		///////////////////////////////
		//�V�[���̍Đ�(����̂�)
		///////////////////////////////
		void ScenePlay(Scene*);
		
		///////////////////////////////
		//�V�[���̍X�V
		///////////////////////////////
		void SceneUpdate();
		
		//////////////////////////////
		//�V�[���̍ď��������s��
		//////////////////////////////
		void SceneReLoad();

		//////////////////////////////
		//�V�[���̏I���������s��
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