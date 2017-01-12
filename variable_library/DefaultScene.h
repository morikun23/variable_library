#ifndef DEFAULT_SCENE
#define DEFAULT_SCENE

////////////////////////////////////////
//クラス名：DefaultScene
//作成者　：森田　勝
//概要	　：設定なしの場合、デフォルトで
//			用意されるシーン。
//			ひな形としても使用できます。
//更新	　：
//H29/01/08：クラスの作成
//H29/01/11：継承元を公開メンバにしました。
//			 これによって、外部から抽象インターフェイスを
//			 参照できるようになりました。
////////////////////////////////////////
#include "Scene.h"
#include <iostream>

using namespace variableNS;

class DefaultScene : public Scene {
	
	//////////////////////////////
	//シーン開始
	//////////////////////////////
	void OnEnter() override;

	//////////////////////////////
	//シーン再生中
	//////////////////////////////
	void OnUpdate() override;

	//////////////////////////////
	//シーン終了
	//////////////////////////////
	void OnExit() override;
};

#endif DEFAULT_SCENE