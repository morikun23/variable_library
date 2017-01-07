#ifndef CONSOLE
#define CONSOLE


////////////////////////////////////
//クラス名：Console
//作成者　：森田　勝
//概要　　：デバッグ用のコンソールウィンドウを表示します。
//更新　　：
//H28/12/05：クラスの作成
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

		Console(){}
		~Console(){};
	public:
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