#ifndef SCENE_MANAGER
#define SCENE_MANAGER

///////////////////////////////////////
//クラス名：SceceManager
//作成者　：森田　勝
//概要　　：ゲーム内の複数のシーンの管理を行います。
//			・シーン再生
//			・シーン遷移
//			・シーン終了
//			といったシーンの動きについて仕事します。
//更新	　：
//////////////////////////////////////

#include <Windows.h>
#include <iostream>
#include "Scene.h"

namespace variableNS {
	class SceneManager {
	private:
		//登録されたシーン
		variableNS::Scene *scene;
		//現在のシーン
		int currentScene;

	public:
		///////////////////////////////
		//シーンの登録
		///////////////////////////////
		void SceneRegister(variableNS::Scene *scene);

		///////////////////////////////
		//シーンの再生
		///////////////////////////////
		void ScenePlay();
		
		//////////////////////////////
		//シーンの終了
		//////////////////////////////
		void SceneEnd();

		//////////////////////////////
		//シーン遷移
		//////////////////////////////
		void SceneTransition(variableNS::Scene *scene);

		/////////////////////////////
		//現在のシーンを取得する
		/////////////////////////////
		variableNS::Scene GetcurrentScene();
	};
}
#endif // !SCENE_MANAGER