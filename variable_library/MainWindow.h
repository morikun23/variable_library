#ifndef MAIN_WINDOW
#define MAIN_WINDOW

////////////////////////////////////////
//クラス名：MainWindow
//作成者　：森田　勝
//概要　　：起動時に作成されるウィンドウをまとめました。
//　　　　　以降、ここで生成されるウィンドウがメインとして
//　　　　　扱われます。
//H29/01/04：クラスの作成
//H29/01/05：ウィンドウプロシージャを追加
//H29/01/16：WindowBaseをpublic にして、
//			 外部クラスからアクセスできるようにしました。
////////////////////////////////////////

#include <Windows.h>
#include "WindowBase.h"

using namespace variableNS;

namespace variableNS {
	class MainWindow : public WindowBase {
	private:
	public:
		//////////////////////////////////
		//コンストラクタ
		//////////////////////////////////
		MainWindow(HINSTANCE);
		virtual ~MainWindow();

		LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM) override;

	};
}
#endif // !MAIN_WINDOW
