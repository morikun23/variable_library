#ifndef ACTOR
#define ACTOR

//////////////////////////////////////////////////////////////////
//クラス名： Actor
//作成者 ：大山　亮 
//概要  ：オブジェに必要な要素をまとめたクラス
//       早い話がUnityのGameObject
//更新  ：H29/01/04/ クラスの作成
//////////////////////////////////////////////////////////////////

#include<string>
#include"Transform.h"

namespace variableNS {

	class Actor {

	private:
		//このオブジェの名前
		std::string name;
		Transform transform;

	public:
		Actor();
		Actor(std::string inName);
		~Actor();

	};
}

#endif