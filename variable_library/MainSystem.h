#ifndef MAINSYSTEM
#define MAINSYSTEM
///////////////////////////////////////////
//クラス名：MainSystem
//作成者　：森田　勝
//概要　　：DirectXなどプログラムの初期化など
//			環境を構築しているクラスです。
//更新　　：
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