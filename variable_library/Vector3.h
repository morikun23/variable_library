#ifndef VECTOR3
#define VECTOR3

//////////////////////////////////////////////////////////////////
//クラス名： Vector3 
//作成者 ：大山　亮 
//概要  ：原点(ウィンドウの左上端)からのベクトル(力の向きや大きさ)を取得したり変更したりするクラス
//更新  ：H28/12/04/ クラスの作成 
//　　　：H28/12/11/　外積を求める関数を追加
//　　　：H28/12/12/　リファクタリング、Set関数のVectorを引数にとった物を追加
//　　　：H29/01/10/　オペレータの見直しと記述場所の変更
//　　　：H29/01/19/  クォータニオンへの変換関数を追加
//////////////////////////////////////////////////////////////////

#include"Quaternion.h"

namespace variableNS {

	class Vector3 {

	public:
		float x, y, z;


		///////////////////////////////////////
		//定数ZEROとONEの定義(ヘッダーファイルでは定数の値の格納まではできない)
		//ZEROでベクトルの長さを０に、ONEで１にする
		///////////////////////////////////////
		static const Vector3 ZERO;
		static const Vector3 ONE;

		/////////////////////////////////////////
		//コンストラクタ
		/////////////////////////////////////////
		Vector3();


		///////////////////////////////////////
		//引数なしコンストラクタ
		//xx : ｘ座標の初期値
		//yy : ｙ座標の初期値
		///////////////////////////////////////
		Vector3(int xx, int yy, int zz);
		Vector3(float xx, float yy,float zz);	


		//////////////////////////////////////
		//デストラクタ
		//////////////////////////////////////
		virtual ~Vector3();

		//////////////////////////////////////
		//座標を代入する関数
		//xx : 代入するｘ座標
		//yy : 代入するｙ座標
		//vec : 代入するx,y,z成分を持ったVector3
		//////////////////////////////////////
		void Set(float xx, float yy, float zz);
		void Set(Vector3 vec);


		//////////////////////////////////////
		//ベクトルの大きさを１に揃える(正規化)
		//////////////////////////////////////
		void Normalize();


		//////////////////////////////////////
		//二線のVector3間の内積を返す
		//vec1 : 一線目のVector3
		//vec2 : 二線目のVector3
		//////////////////////////////////////
		static float Dot(Vector3 vec1, Vector3 vec2);


		//////////////////////////////////////
		//二線のVector3間の外積を返す
		//vec1 : 一線目のVector3
		//vec2 : 二線目のVector3
		//////////////////////////////////////
		static Vector3 Cross(Vector3 vec1, Vector3 vec2);


		//////////////////////////////////////
		//二線のVector3間の角度を返す
		//vec1 : 一線目のVector3
		//vec2 : 二線目のVector3
		//////////////////////////////////////
		static float Angle(Vector3 vec1, Vector3 vec2);


		//////////////////////////////////////
		//二線のVector3間の距離を返す
		//vec1 : 一線目のVector3
		//vec2 : 二線目のVector3
		//////////////////////////////////////
		static float Distance(Vector3 vec1, Vector3 vec2);


		//////////////////////////////////////
		//二線のVector3間の反射角を返す
		//vec1 : 一線目のVector3
		//vec2 : 二線目のVector3
		//////////////////////////////////////
		static Vector3 Reflect(Vector3 vec1, Vector3 vec2);


		//////////////////////////////////////
		//二線のVector3が交わってるかどうかを返す
		//vec1 : 一線目のVector3
		//vec2 : 二線目のVector3
		//vec3 : 三線目のVector3
		//vec4 : 四線目のVector3
		//////////////////////////////////////
		static bool IsCross(Vector3 vec1, Vector3 vec2, Vector3 vec3, Vector3 vec4);


		//////////////////////////////////////////////
		//三元数を四元数に変換する
		//////////////////////////////////////////////
		Quaternion ToQuaternion();


		//各オペレータ
		Vector3 operator +(Vector3);
		void operator +=(Vector3);
		Vector3 operator +(int);
		void operator +=(int);
		Vector3 operator +(float);
		void operator +=(float);
		Vector3 operator -(Vector3);
		void operator -=(Vector3);
		Vector3 operator -(int);
		void operator -=(int);
		Vector3 operator -(float);
		void operator -=(float);
		Vector3 operator *(int);
		void operator *=(int);
		Vector3 operator *(float);
		void operator *=(float);
		Vector3 operator /(int);
		void operator /=(int);
		Vector3 operator /(float);
		void operator /=(float);
		void operator =(Vector3);
		bool operator ==(Vector3);
		bool operator !=(Vector3);
	};


}

#endif // !1