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
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <Windows.h>
#include <sstream>
#include <vector>



namespace variableNS {

	template<typename T>
	class Resources {

	private:


	public:

		

		//texture�i�[�p�̕ϐ��������\��
		//Sound�i�[�p�̕ϐ��������\��
		//Effect�i�[�p�̕ϐ��������\��
		//Font�i�[�p�̕ϐ��������\��

		
		///////////////////////////////
		//�@�p�X�w�肵���t�@�C����ǂݍ��ފ֐�
		//�@�����@:pass�@c:����n�܂�p�X���w�肷��@��jc:root/Reources/�������܂ł͏ȗ��@�@��������p�X�w��FTextures/2D/test.txt
		//�@�߂�l:�w�肵���^�̃t�@�C������Ԃ�
		//		�@��)string��.txt��������@���̕���������ׂĕԂ��@�Ȃ�
		///////////////////////////////
		static T Load(char pass[]);
		

		static T Loads(char pass[]);

		///////////////////////////////
		//�@�p�X�w�肵���t�@�C����ǂݍ��ފ֐�
		//�@�����@:pass�@c:����n�܂�p�X���w�肷��@��jc:root/Reources/Textures/2D/test.txt
		//�@�߂�l:fp 
		///////////////////////////////
		//static FILE *FilePointLoad(char pass[]);

		

	};

}

#endif // !RESOURCES