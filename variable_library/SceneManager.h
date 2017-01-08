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
//H29/01/04：クラスの作成
//H29/01/08：GetCurrentScene関数を修正
//			 ※再生中のSceneクラスを取得
//			 　→再生中のSceneクラスのアドレスを取得
//////////////////////////////////////

#include <Windows.h>
#include <iostream>
#include "Scene.h"

using namespace variableNS;

namespace variableNS {
	class SceneManager {
	private:
		//登録されたシーン
		Scene *scene;
		//現在のシーン
		int currentScene;

	public:
		///////////////////////////////
		//シーンの登録
		///////////////////////////////
		void SceneRegister(Scene*);

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
		void SceneTransition(Scene*);

		/////////////////////////////
		//現在のシーンを取得する
		/////////////////////////////
		Scene& GetCurrentScene();
	};
}
#endif // !SCENE_MANAGER