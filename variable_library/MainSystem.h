#ifndef MAINSYSTEM
#define MAINSYSTEM
///////////////////////////////////////////
//�N���X���FMainSystem
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�FDirectX�Ȃǃv���O�����̏������Ȃ�
//			�����\�z���Ă���N���X�ł��B
//�X�V�@�@�F
///////////////////////////////////////////
#include <Windows.h>
#include "MainWindow.h"
#include"MainWindow.h"

class MainSystem {
	public:
		static void Load();
		static void Update();
		static void UnLoad();

};
#endif // !MAINSYSTEM