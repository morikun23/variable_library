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
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <Windows.h>
#include <sstream>
#include <vector>



namespace variableNS {

	template<typename T>
	class Resources {

	private:


	public:

		

		//texture格納用の変数を実装予定
		//Sound格納用の変数を実装予定
		//Effect格納用の変数を実装予定
		//Font格納用の変数を実装予定

		
		///////////////////////////////
		//　パス指定したファイルを読み込む関数
		//　引数　:pass　c:から始まるパスを指定する　例）c:root/Reources/←ここまでは省略　　ここからパス指定：Textures/2D/test.txt
		//　戻り値:指定した型のファイル情報を返す
		//		　例)stringで.txtだったら　中の文字列をすべて返す　など
		///////////////////////////////
		static T Load(char pass[]);
		

		static T Loads(char pass[]);

		///////////////////////////////
		//　パス指定したファイルを読み込む関数
		//　引数　:pass　c:から始まるパスを指定する　例）c:root/Reources/Textures/2D/test.txt
		//　戻り値:fp 
		///////////////////////////////
		//static FILE *FilePointLoad(char pass[]);

		

	};

}

#endif // !RESOURCES