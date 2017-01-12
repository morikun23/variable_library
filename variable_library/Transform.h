#ifndef TRANSFORM
#define TRANSFORM

//////////////////////////////////////////////////////////////////
//クラス名： Transform 
//作成者 ：大山　亮 
//概要  ：Unityで使ってるposition,rotation,scaleをまとめたライブラリ
//更新  ：H28/12/07/ クラスの作成 
//////////////////////////////////////////////////////////////////

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace variableNS{

	class Transform {

	private:

		//位置の値、大きさの値を格納する三元数
		Vector3 position;
		Vector3 scale;

		//回転の値を格納する四元数(クォータニオン)
		//Quaternion rotation;

	public:
		

		/////////////////////////////////////////
		//コンストラクタ、デストラクタ
		/////////////////////////////////////////
		Transform();
		Transform(Vector3 pos,Vector3 sca,Vector3 rota);
		virtual ~Transform();


	};

	
}

#endif