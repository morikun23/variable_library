#ifndef MATRIX
#define MATRIX

//////////////////////////////////////////////////////////////////
//クラス名： Matrix
//作成者 ：大山　亮 
//概要  ：4x4の行列の生成、計算を行うクラス
//更新  ：H28/12/18/ クラスの作成
//      :H29/01/04/ 変換関数の作成
//////////////////////////////////////////////////////////////////

#include"Vector3.h"
#include"Vector4.h"
#include"Quaternion.h"

namespace variableNS {

	class Matrix {

	public:
		union{
			struct{
				float m00, m01, m02, m03;
				float m10, m11, m12, m13;
				float m20, m21, m22, m23;
				float m30, m31, m32, m33;
			};
			float _matrix[4][4];
		};

		//コンストラクタ、デストラクタ
		Matrix();
		virtual ~Matrix();

		///////////////////////////////////////
		//マトリクスの単位化　ほとんどの行列計算の前に必要な処理
		///////////////////////////////////////
		void Identity();

		///////////////////////////////////////
		//マトリクスを位置行列に変える
		//vec : 位置を表す三元数
		///////////////////////////////////////
		void ToPositionMatrix(Vector3 arg_vec);

		///////////////////////////////////////
		//マトリクスを縮小拡大行列に変える
		//vec : 大きさを表す三元数
		///////////////////////////////////////
		void ToScaleMatrix(Vector3 arg_vec);

		///////////////////////////////////////
		//マトリクスを回転行列に変える
		//quat : 大きさを表す四元数
		///////////////////////////////////////
		void ToRotateMatrix(Quaternion arg_quat);

		//各オペレータ
		Matrix operator +(Matrix);
		Matrix operator -(Matrix);
		Matrix operator *(Matrix);
		void operator +=(Matrix);
		void operator -=(Matrix);
		void operator *=(Matrix);
	};

}

#endif