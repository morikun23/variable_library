#ifndef WINDOW_BASE
#define WINDOW_BASE

/////////////////////////////////////
//クラス名：WindowBase
//作成者　：森田　勝
//概要　　：ウィンドウの基盤となるプロパティ
//更新　　：
//H28/12/22：クラスの作成
//H29/01/05：WindowProcedureを追加
//H29/01/08：GetHandle関数を追加
//H29/01/18：Register、Create関数を修正
//H29/01/19：GetWidth、GetHeight関数を追加
////////////////////////////////////

#include <Windows.h>
#include <iostream>
#include"Vector2.h"

using namespace variableNS;

namespace variableNS {
	class WindowBase {
	
	private:
		
	protected:
		//ウィンドウの座標
		Vector2 _position;

		//ウィンドウの幅
		int _width;

		//ウィンドウの高さ
		int _height;

		//ウィンドウ名
		std::string _name;

		//ウィンドウハンドル
		HWND _handle;

		//ウィンドウスタイル
		DWORD _windowStyle;

		//デフォルト値
		const int DEFAULT_WIDTH = 640;
		const int DEFAULT_HEIGHT = 480;

		/////////////////////////////////////
		//ウィンドウの登録
		////////////////////////////////////
		bool Register(HINSTANCE);
		
		////////////////////////////////////
		//ウィンドウの生成
		////////////////////////////////////
		bool Create(HINSTANCE);

		////////////////////////////////////
		//ウィンドウの表示
		////////////////////////////////////
		void Open();

		////////////////////////////////////
		//ウィンドウの非表示
		////////////////////////////////////
		void Close();

	public:
		
		///////////////////////////////////
		//ウィンドウプロシージャ
		//////////////////////////////////
		virtual LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);
		
		//////////////////////////////////
		//ウィンドウプロシージャを取得する
		//////////////////////////////////
		static LRESULT CALLBACK GetWindowProcedure(HWND, UINT, WPARAM, LPARAM);
		
		//////////////////////////////////
		//ウィンドウハンドルを取得
		//////////////////////////////////
		HWND GetHandle();
		
		//////////////////////////////////
		//ウィンドウの幅を取得
		//////////////////////////////////
		int GetWidth();

		//////////////////////////////////
		//ウィンドウの高さを取得
		//////////////////////////////////
		int GetHeight();
	};
}
#endif // !WINDOW_BASE