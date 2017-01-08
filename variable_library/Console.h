#ifndef CONSOLE
#define CONSOLE

////////////////////////////////////
//クラス名：Console
//作成者　：森田　勝
//概要　　：デバッグ用のコンソールウィンドウを表示します。
//更新　　：
//H28/12/05：クラスの作成
//H29/01/07：Sindleton構造に修正
//			 デフォルトコンストラクタ、デストラクタを削除
///////////////////////////////////
#include<iostream>
#include <Windows.h>

namespace variableNS {
	class Console {
	private:
		//コンソールウィンドウのハンドル
		FILE *m_consoleHandle;
		//ウィンドウが開いているか
		bool isOpened;

	public:
		//////////////////////////////////
		//Singleton構造
		//用意されているインスタンスを取得
		//return：唯一のインスタンス
		//////////////////////////////////
		static Console& Instance() {
			static Console instance;
			return instance;
		}

		//////////////////////////////////
		//コンソールの表示
		//////////////////////////////////
		void Open();

		//////////////////////////////////
		//コンソールの非表示
		//////////////////////////////////
		void Close();

	};

}
#endif // !CONSOLE