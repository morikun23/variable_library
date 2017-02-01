#ifndef MATRIXBASE
#define MATRIXBASE

//////////////////////////////////////////////////////////////////
//クラス名： MatrixBase
//作成者 ：大山　亮 
//概要  ：行列の生成の元になるクラス　様々な大きさの行列に継承、派生させる
//更新  ：H29/01/30/ クラスの作成
/////////////////////////////////////////////////////////////////

namespace variableNS {

	class MatrixBase {

	public:

		MatrixBase() {};
		virtual ~MatrixBase() = 0;

		///////////////////////////////////////
		//マトリクスの単位化　ほとんどの行列計算の前に必要な処理
		///////////////////////////////////////
		virtual void Identity() = 0;

		///////////////////////////////////////
		//マトリクスを位置行列に変える
		///////////////////////////////////////
		virtual void ToPositionMatrix() = 0;

		///////////////////////////////////////
		//マトリクスを縮小拡大行列に変える
		///////////////////////////////////////
		virtual void ToScaleMatrix() = 0;

		///////////////////////////////////////
		//マトリクスを回転行列に変える
		///////////////////////////////////////
		virtual void ToRotateMatrix() = 0;

		//各オペレータ
		virtual MatrixBase operator +(MatrixBase) = 0;
		virtual MatrixBase operator -(MatrixBase) = 0;
		virtual MatrixBase operator *(MatrixBase) = 0;
		virtual void operator +=(MatrixBase) = 0;
		virtual void operator -=(MatrixBase) = 0;
		virtual void operator *=(MatrixBase) = 0;

	};

}

#endif