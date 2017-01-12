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
		float x, y, z, w;

		Quaternion();
		Quaternion(int xx, int yy, int zz, int ww);
		Quaternion(float xx,float yy,float zz,float ww);
		Quaternion(Vector4 vec);
		~Quaternion();

		//////////////////////////////////////////////
		//四元数の単位化(回転していない状態)
		//////////////////////////////////////////////
		void Identity();


		//////////////////////////////////////////////
		//四元数の絶対値を返す(ノルムと呼ばれる)
		//////////////////////////////////////////////
		float Norm();


		//////////////////////////////////////////////
		//値のセット
		//quaternion : x,y,z,wの三元数
		//////////////////////////////////////////////
		void Set(Quaternion quaternion);


		//////////////////////////////////////////////
		//オイラー角で回転
		//vec : x,y,zの三元数
		//////////////////////////////////////////////
		void EulerAngles(Vector3 vec);


		//各オペレータ
		void operator =(Quaternion);
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