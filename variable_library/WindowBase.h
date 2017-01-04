#ifndef WindowBase
#define WINDOWBASE

/////////////////////////////////////
//クラス名：WindowBase
//作成者　：森田　勝
//概要　　：ウィンドウの基盤となるプロパティ
//更新　　：
//H28/12/22：クラスの作成
////////////////////////////////////
#include <Windows.h>
#include <iostream>
namespace variableNS {
	class WindowBase {
	
	private:
		
	protected:
		/////////////////////////////////////
		//ウィンドウの登録
		////////////////////////////////////
		virtual bool Register();
		//デフォルト値
		const int m_DEFAULT_WIDTH = 640;
		const int m_DEFAULT_HEIGHT = 480;

	public:
		std::wstring m_name;
		float m_width;
		float m_height;
		HWND m_handle;
		DWORD m_windowStyle;
		
		///////////////////////////////////
		//ウィンドウプロシージャ
		//////////////////////////////////
		virtual LRESULT CALLBACK WinProc(HWND,UINT,WPARAM,LPARAM);

		virtual bool Create();
		virtual void Open();
		virtual void Close();
	};
}
#endif // !WindowBase