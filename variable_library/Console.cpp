#include "Console.h"
using namespace variableNS;
using namespace std;

Console::Console() {
	//コンソールハンドルの初期化
	m_consoleHandle = 0;
	this->Open();
}

Console::~Console() {
	//ウィンドウを閉じて初期化
	this->Close();
	m_consoleHandle = 0;
}

void Console::Open() {
	if (isOpened) return;
	isOpened = true;
	::AllocConsole();
	freopen_s(&m_consoleHandle, "CON", "w", stdout);    // 標準出力の割り当て
	
}

void Console::Close() {
	//コンソールのウィンドウ
	fclose(m_consoleHandle);
	::FreeConsole();
}