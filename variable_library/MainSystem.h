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

using namespace variableNS;
class MainSystem {

private:
	MainWindow *window;

public:
	void Load();
	void Update();
	void UnLoad();
};
#endif // !MAINSYSTEM