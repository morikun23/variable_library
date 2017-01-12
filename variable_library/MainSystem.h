#ifndef MAINSYSTEM
#define MAINSYSTEM
///////////////////////////////////////////
//クラス名：MainSystem
//作成者　：森田　勝
//概要　　：DirectXなどプログラムの初期化など
//			環境を構築しているクラスです。
//更新　　：
//H29/01/04：クラスの作成
//H29/01/05：ウィンドウの生成
//H29/01/07：コンソールの表示を追加
///////////////////////////////////////////
#include <Windows.h>
#include "MainWindow.h"
#include "Console.h"
#include "SceneManager.h"

using namespace variableNS;

class MainSystem {

private:
	//使用するウィンドウのポインタ
	MainWindow* window;

public:
	
	MainSystem() {}
	~MainSystem() {}

	///////////////////////////////
	//初期化
	///////////////////////////////
	void Load();
	
	///////////////////////////////
	//毎フレーム更新
	///////////////////////////////
	void Update();

	///////////////////////////////
	//終了
	///////////////////////////////
	void UnLoad();
};
#endif // !MAINSYSTEM