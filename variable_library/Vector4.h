#ifndef VECTOR4
#define VECTOR4

//////////////////////////////////////////////////////////////////
//クラス名： Vector4 
//作成者 ：大山　亮 
//概要  ：原点(ウィンドウの左上端)からのベクトル(力の向きや大きさ)を取得したり変更したりするクラス
//更新  ：H28/12/05/ クラスの作成 
//　　　：H28/12/11/　外積を求める関数を追加
//　　　：H28/12/12/　リファクタリング、Set関数のVectorを引数にとった物を追加
//　　　：H29/01/10/　オペレータの見直しと記述場所の変更
//////////////////////////////////////////////////////////////////

namespace variableNS {

	class Vector4 {

	public:
		//Vector4(x,y,z,w)
		float x, y, z, w;


		///////////////////////////////////////
		//定数ZEROとONEの定義(ヘッダーファイルでは定数の値の格納まではできない)
		//ZEROでベクトルの長さを０に、ONEで１にする
		///////////////////////////////////////
		static const Vector4 ZERO;
		static const Vector4 ONE;

		/////////////////////////////////////////
		//コンストラクタ
		/////////////////////////////////////////
		Vector4();


		///////////////////////////////////////
		//引数なしコンストラクタ
		//xx : ｘ座標の初期値
		//yy : ｙ座標の初期値
		///////////////////////////////////////
		Vector4(int xx, int yy, int zz,int ww);
		Vector4(float xx, float yy, float zz,float ww);


		//////////////////////////////////////
		//デストラクタ
		//////////////////////////////////////
		virtual ~Vector4();

		//////////////////////////////////////
		//座標を代入する関数
		//xx : 代入するｘ座標
		//yy : 代入するｙ座標
		//vec : 代入するx,y,z,w成分を持ったVector4
		//////////////////////////////////////
		void Set(float xx, float yy, float zz, float ww);
		void Set(Vector4 vec);


		//////////////////////////////////////
		//ベクトルの大きさを１に揃える(正規化)
		//////////////////////////////////////
		void Normalize();


		//////////////////////////////////////
		//二線のVector4間の内積を返す
		//vec1 : 一線目のVector4
		//vec2 : 二線目のVector4
		//////////////////////////////////////
		static float Dot(Vector4 vec1, Vector4 vec2);


		//////////////////////////////////////
		//二線のVector2間の外積を返す
		//vec1 : 一線目のVector4
		//vec2 : 二線目のVector4
		//////////////////////////////////////
		static Vector4 Cross(Vector4 vec1, Vector4 vec2);


		//////////////////////////////////////
		//二線のVector4間の角度を返す
		//vec1 : 一線目のVector4
		//vec2 : 二線目のVector4
		//////////////////////////////////////
		static float Angle(Vector4 vec1, Vector4 vec2);


		//////////////////////////////////////
		//二線のVector4間の距離を返す
		//vec1 : 一線目のVector4
		//vec2 : 二線目のVector4
		//////////////////////////////////////
		static float Distance(Vector4 vec1, Vector4 vec2);


		//////////////////////////////////////
		//二線のVector4間の反射角を返す
		//vec1 : 一線目のVector4
		//vec2 : 二線目のVector4
		//////////////////////////////////////
		static Vector4 Reflect(Vector4 vec1, Vector4 vec2);


		//////////////////////////////////////
		//二線のVector4が交わってるかどうかを返す
		//vec1 : 一線目のVector4
		//vec2 : 二線目のVector4
		//vec3 : 三線目のVector4
		//vec4 : 四線目のVector4
		//////////////////////////////////////
		static bool IsCross(Vector4 vec1, Vector4 vec2, Vector4 vec3, Vector4 vec4);


		//各オペレータ
		Vector4 operator +(Vector4);
		void operator +=(Vector4);
		Vector4 operator +(int);
		void operator +=(int);
		Vector4 operator +(float);
		void operator +=(float);
		Vector4 operator -(Vector4);
		void operator -=(Vector4);
		Vector4 operator -(int);
		void operator -=(int);
		Vector4 operator -(float);
		void operator -=(float);
		Vector4 operator *(int);
		void operator *=(int);
		Vector4 operator *(float);
		void operator *=(float);
		Vector4 operator /(int);
		void operator /=(int);
		Vector4 operator /(float);
		void operator /=(float);
		void operator =(Vector4);
		bool operator ==(Vector4);
		bool operator !=(Vector4);
	};


}

#endif // !1