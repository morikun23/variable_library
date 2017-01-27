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
#include "Quaternion.h"
#include "Matrix.h"

namespace variableNS{

	class Transform {

	public:
		//位置の値、大きさの値を格納する三元数
		Vector3 _position;
		Vector3 _scale;

		//回転の値を格納する四元数(クォータニオン)
		Quaternion _rotation;

		/////////////////////////////////////////
		//コンストラクタ、デストラクタ
		/////////////////////////////////////////
		Transform();
		Transform(Vector3 arg_pos,Vector3 arg_sca,Vector3 arg_rota);
		virtual ~Transform();


		//////////////////////////////////////////////
		//任意軸のまわりを回転する四元数を返す
		//vec : 軸
		//x,y,z :上記と同義
		//angle : 回転角度
		//////////////////////////////////////////////
		void RotateAxis(Vector3 arg_vec, float arg_angle);
		void RotateAxis(float arg_x, float arg_y, float arg_z, float arg_angle);


		/////////////////////////////////////////
		//ワールドマトリクス(位置、大きさ、回転の情報が格納された行列)を作る
		/////////////////////////////////////////
		Matrix MakeWorldTransform();

	};

	
}

#endif