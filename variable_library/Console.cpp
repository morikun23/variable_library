#include "Console.h"
using namespace variableNS;
using namespace std;

Console::Console() {
	//�R���\�[���n���h���̏�����
	m_consoleHandle = 0;
	this->Open();
}

Console::~Console() {
	//�E�B���h�E����ď�����
	this->Close();
	m_consoleHandle = 0;
}

void Console::Open() {
	if (isOpened) return;
	isOpened = true;
	::AllocConsole();
	freopen_s(&m_consoleHandle, "CON", "w", stdout);    // �W���o�͂̊��蓖��
	
}

void Console::Close() {
	//�R���\�[���̃E�B���h�E
	fclose(m_consoleHandle);
	::FreeConsole();
}