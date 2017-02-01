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

		///////////////////////////////////////
		//マトリクスの単位化　ほとんどの行列計算の前に必要な処理
		///////////////////////////////////////
		virtual void Identity();

		///////////////////////////////////////
		//マトリクスを位置行列に変える
		///////////////////////////////////////
		virtual void ToPositionMatrix();

		///////////////////////////////////////
		//マトリクスを縮小拡大行列に変える
		///////////////////////////////////////
		virtual void ToScaleMatrix();

		///////////////////////////////////////
		//マトリクスを回転行列に変える
		///////////////////////////////////////
		virtual void ToRotateMatrix();

		//各オペレータ
		virtual MatrixBase operator +(MatrixBase);
		virtual MatrixBase operator -(MatrixBase);
		virtual MatrixBase operator *(MatrixBase);
		virtual void operator +=(MatrixBase);
		virtual void operator -=(MatrixBase);
		virtual void operator *=(MatrixBase);

	};

}

#endif