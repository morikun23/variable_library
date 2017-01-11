#ifndef RESOURCES
#define RESOURCES


//////////////////////////////////////

//クラス名:　NMath

//作成者  :　野本　真央

//概要    :　ファイル参照クラス

//更新	　:
//H29/1/4	クラス作成
//H29/1/11  Load関数の作成
//			pointer渡しはできるが細かい指定ができない
//			staticメンバに格納したものならできている


///////////////////////////////////////

#include <stdio.h>
#include <string>
#include <vector>



namespace variableNS {

	class Resources {

	private:


	public:

		

		//pointerで取得したtextファイルを読み込むための変数
		static char text[256];


		//texture格納用の変数を実装予定
		//Actor格納用の変数を実装予定
		//Sound格納用の変数を実装予定
		//Effect格納用の変数を実装予定
		//Font格納用の変数を実装予定

		
		///////////////////////////////
		//　filepointを読み込む関数
		//　引数　:pass　c:から始まるパスを指定する　例）c:root/Reources/Textures/2D/test.txt
		//　戻り値:未定(今のところはfilepointを戻り値とする)
		///////////////////////////////
		static FILE *Load(char pass[]);

		//未完成品
		/*template<template T>
		static T *Load(char pass[]);
		*/
 		
		///////////////////////////////
		//　読み込んだfilepointをしめる関数
		//　引数　:filepoint
		//　戻り値:Errorならtrueを返す　きちんと処理で来たらfalseを返す
		///////////////////////////////
		static bool Close(FILE *fp);
		

	};

}


#endif // !RESOURCES