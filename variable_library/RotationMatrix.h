/*
#ifndef ROTATIONMATRIX
#define ROTATIONMATRIX

//////////////////////////////////////////////////////////////////
//クラス名： RotationMatrix 
//作成者 ：大山　亮 
//概要  ：回転行列を扱うクラス
//更新  ：H28/12/19/ クラスの作成 
//////////////////////////////////////////////////////////////////

#include"MatrixBase.h"

namespace variableNS {

	class RotationMatrix : public MatrixBase{
	
	public:
		//読み取り専用のx,y,z成分
		float x, y, z;

		//コンストラクタ、デストラクタ
		RotationMatrix();
		virtual ~RotationMatrix();


		///////////////////////
		//オイラー角で回します(オペレーターあるからいらねえかも)
		//vec : x,y,z要素
		///////////////////////
		void Rotate(Vector3 vec);


		///////////////////////////
		//目標物に対してロックオン(向きを合わせる)
		//position : 自分の位置
		//target : 目標物
		//up : カメラの上方向(一般的には(0,1,0))
		///////////////////////////
		void LookAt(Vector3 position, Vector3 target, Vector3 up);


		//各オペレータ
		RotationMatrix operator+(Vector3);
		RotationMatrix operator-(Vector3);
		RotationMatrix operator=(Vector3);
		void operator+=(Vector3);
		void operator-=(Vector3);
	};

}

#endif
*/