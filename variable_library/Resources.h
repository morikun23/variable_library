#ifndef RESOURCES
#define RESOURCES


//////////////////////////////////////

//�N���X��:�@NMath

//�쐬��  :�@��{�@�^��

//�T�v    :�@�t�@�C���Q�ƃN���X

//�X�V	�@:
//H29/1/4	�N���X�쐬
//H29/1/11  Load�֐��̍쐬
//			pointer�n���͂ł��邪�ׂ����w�肪�ł��Ȃ�
//			static�����o�Ɋi�[�������̂Ȃ�ł��Ă���


///////////////////////////////////////

#include <stdio.h>
#include <string>
#include <vector>



namespace variableNS {

	class Resources {

	private:


	public:

		

		//pointer�Ŏ擾����text�t�@�C����ǂݍ��ނ��߂̕ϐ�
		static char text[256];


		//texture�i�[�p�̕ϐ��������\��
		//Actor�i�[�p�̕ϐ��������\��
		//Sound�i�[�p�̕ϐ��������\��
		//Effect�i�[�p�̕ϐ��������\��
		//Font�i�[�p�̕ϐ��������\��

		
		///////////////////////////////
		//�@�p�X�w�肵���t�@�C����ǂݍ��ފ֐�
		//�@�����@:pass�@c:����n�܂�p�X���w�肷��@��jc:root/Reources/Textures/2D/test.txt
		//�@�߂�l:�Ȃ�(����Ă��Ƃ��Ăق���static�����o�Ɋi�[����)
		//			����(���̂Ƃ����filepoint��߂�l�Ƃ���)
		///////////////////////////////
		static void *Load(char pass[]);

		///////////////////////////////
		//�@�p�X�w�肵���t�@�C����ǂݍ��ފ֐�
		//�@�����@:pass�@c:����n�܂�p�X���w�肷��@��jc:root/Reources/Textures/2D/test.txt
		//�@�߂�l:fp 
		///////////////////////////////
		static FILE *FilePointLoad(char pass[]);

		//�������i
		/*template<template T>
		static T *Load(char pass[]);
		*/
 		
		///////////////////////////////
		//�@�ǂݍ���filepoint�����߂�֐�
		//�@�����@:filepoint
		//�@�߂�l:Error�Ȃ�false��Ԃ��@������Ə����ŗ�����true��Ԃ�
		///////////////////////////////
		static bool Close(FILE *fp);
		

	};

}


#endif // !RESOURCES