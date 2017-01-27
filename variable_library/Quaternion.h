#ifndef QUATERNION
#define QUATERNION

//////////////////////////////////////////////////////////////////
//クラス名： Quaternion
//作成者 ：大山　亮 
//概要  ：回転情報を格納するクラス
//更新  ：H29/01/04/ クラスの作成
//////////////////////////////////////////////////////////////////

#include"Vector3.h"
#include"Vector4.h"

namespace variableNS {

	class Quaternion {

	private:
		
		
	public:
		float _x, _y, _z, _w;
		const Vector3 _euler;

		Quaternion();
		Quaternion(int arg_x, int arg_y, int arg_z, int arg_w);
		Quaternion(float arg_x,float arg_y,float arg_z,float arg_w);
		Quaternion(Vector4 arg_vec);
		~Quaternion();

		//////////////////////////////////////////////
		//四元数の単位化(回転していない状態)
		//////////////////////////////////////////////
		void Identity();


		//////////////////////////////////////////////
		//四元数の長さを返す(ノルムと呼ばれる)
		//////////////////////////////////////////////
		float Length();


		//////////////////////////////////////////////
		//値のセット
		//quaternion : x,y,z,wの三元数
		//////////////////////////////////////////////
		void Set(Quaternion arg_quat);


		//////////////////////////////////////////////
		//任意軸のまわりを回転する四元数を返す
		//vec : 軸
		//x,y,z :上記と同義
		//angle : 回転角度
		//////////////////////////////////////////////
		//Quaternion RotateAxis(Vector3 vec,float angle);
		//Quaternion RotateAxis(float x, float y, float z,float angle);


		//////////////////////////////////////////////
		//四元数を三元数に変換する
		//q : 変換したい四元数
		//////////////////////////////////////////////
		Vector3 ToVector3();


		//各オペレータ
		void operator =(Quaternion);
		void operator =(Vector3);
		Quaternion operator *(Quaternion);
		void operator *=(Quaternion);
		Quaternion operator +(Quaternion);
		void operator +=(Quaternion);
		Quaternion operator -(Quaternion);
		void operator -=(Quaternion);
		bool operator ==(Quaternion);
		bool operator !=(Quaternion);
	};
}


#endif