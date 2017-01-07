#ifndef MAINWINDOW
#define MAINWINDOW

////////////////////////////////////////
//クラス名：MainWindow
//作成者　：森田　勝
//概要　　：起動時に作成されるウィンドウをまとめました。
//　　　　　以降、ここで生成されるウィンドウがメインとして
//　　　　　扱われます。
////////////////////////////////////////

#include <Windows.h>
#include "WindowBase.h"

namespace variableNS {
	class MainWindow : WindowBase {
	private:
		
	public:
		//////////////////////////////////
		//コンストラクタ
		//////////////////////////////////
		MainWindow();
		~MainWindow();

		 LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM) override;

	};
}
#endif // !MAINWINDOW
