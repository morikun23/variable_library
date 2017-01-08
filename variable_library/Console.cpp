#include "Console.h"

using namespace variableNS;

////////////////////////////////
//�R���\�[���E�B���h�E�̕\��
////////////////////////////////
void Console::Open() {
	if (isOpened) return;
	::AllocConsole();
	// �W���o�͂̊��蓖��
	freopen_s(&m_consoleHandle, "CON", "w", stdout);
	isOpened = true;
	std::cout << ">-- Console start up" << std::endl;
}

////////////////////////////////
//�R���\�[���E�B���h�E�̔�\��
////////////////////////////////
void Console::Close() {
	if (!isOpened) return;
	//�R���\�[���̃E�B���h�E
	fclose(m_consoleHandle);
	::FreeConsole();
	isOpened = false;
}