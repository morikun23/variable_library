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
//H29/01/16：WinMain関数をMain.cppに移動
//H29/01/16：hwnd、hInstanceのハンドル２種をそれぞれ追加
///////////////////////////////////////////
#include <Windows.h>

#include "Direct3DManager.h"
#include "MainWindow.h"
#include "Console.h"
#include "SceneManager.h"

using namespace variableNS;

class MainSystem {

private:
	//インスタンスハンドル
	HINSTANCE _hInstance;
	
	//使用するウィンドウのポインタ
	MainWindow* _window;
	
public:

	MainSystem(HINSTANCE arg_hInstance) { _hInstance = arg_hInstance; }
	virtual ~MainSystem() {};
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