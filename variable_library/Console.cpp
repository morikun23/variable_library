#include "Console.h"

using namespace variableNS;

////////////////////////////////
//コンソールウィンドウの表示
////////////////////////////////
void Console::Open() {
	if (isOpened) return;
	::AllocConsole();
	// 標準出力の割り当て
	freopen_s(&m_consoleHandle, "CON", "w", stdout);
	isOpened = true;
	std::cout << ">-- Console start up" << std::endl;
}

////////////////////////////////
//コンソールウィンドウの非表示
////////////////////////////////
void Console::Close() {
	if (!isOpened) return;
	//コンソールのウィンドウ
	fclose(m_consoleHandle);
	::FreeConsole();
	isOpened = false;
}