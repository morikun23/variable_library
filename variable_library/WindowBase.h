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
#include"Vector2.h"
namespace variableNS {
	class WindowBase {
	
	private:
		
	protected:
		//ウィンドウの座標
		Vector2 m_position;

		//ウィンドウの幅
		int m_width;

		//ウィンドウの高さ
		int m_height;

		//ウィンドウ名
		std::string m_name;

		//ウィンドウハンドル
		HWND m_handle;

		//ウィンドウスタイル
		DWORD m_windowStyle;

		//デフォルト値
		const int m_DEFAULT_WIDTH = 640;
		const int m_DEFAULT_HEIGHT = 480;

		
		/////////////////////////////////////
		//ウィンドウの登録
		////////////////////////////////////
		virtual bool Register();
		
		////////////////////////////////////
		//ウィンドウの生成
		////////////////////////////////////
		virtual bool Create();

		////////////////////////////////////
		//ウィンドウの表示
		////////////////////////////////////
		virtual void Open();

		////////////////////////////////////
		//ウィンドウの非表示
		////////////////////////////////////
		virtual void Close();

	public:
		
		///////////////////////////////////
		//ウィンドウプロシージャ
		//////////////////////////////////
		virtual LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);
		
		//////////////////////////////////
		//ウィンドウプロシージャを取得する
		//////////////////////////////////
		static LRESULT CALLBACK GetWindowProcedure(HWND, UINT, WPARAM, LPARAM);
		
	};
}
#endif // !WindowBase