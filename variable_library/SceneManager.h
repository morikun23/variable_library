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
//H29/01/11：Singleton構成に修正
//H29/01/12：SceneUpdate関数と
//			 SceneEnd関数を追加
//			 また、同時にSceneTransition関数のリファクタリングを行い、
//			 メンバ関数を使用して、二重管理を防ぎました。
//////////////////////////////////////

#include <Windows.h>
#include <iostream>
#include "Scene.h"
#include "DefaultScene.h"

namespace variableNS {
	class SceneManager {
	private:
		//現在のシーン
		Scene *m_currentScene;

	public:
		
		//////////////////////////////////
		//Singleton構造
		//用意されているインスタンスを取得
		//return：唯一のインスタンス
		//////////////////////////////////
		static SceneManager& Instance() {
			static SceneManager instance;
			return instance;
		}

		///////////////////////////////
		//シーンの再生(初回のみ)
		///////////////////////////////
		void ScenePlay(Scene*);
		
		///////////////////////////////
		//シーンの更新
		///////////////////////////////
		void SceneUpdate();
		
		//////////////////////////////
		//シーンの再初期化を行う
		//////////////////////////////
		void SceneReLoad();

		//////////////////////////////
		//シーンの終了処理を行う
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