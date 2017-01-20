#ifndef VECTOR2
#define VECTOR2

//////////////////////////////////////////////////////////////////
//クラス名： Vector2 
//作成者 ：大山　亮 
//概要  ：原点(ウィンドウの左上端)からのベクトル(力の向きや大きさ)を取得したり変更したりするクラス
//更新  ：H28/12/02/ クラスの作成 
//　　　：H28/12/11/　外積を求める関数を追加
//　　　：H28/12/12/　リファクタリング、Set関数のVectorを引数にとった物を追加
//　　　：H29/01/10/　オペレータの見直しと記述場所の変更
//　　　：H29/01/20/　メンバ変数及び、メンバ関数内での引数の名前を変更
//////////////////////////////////////////////////////////////////

namespace variableNS {

	class Vector2 {

	public:
		//Vector2(x,y)
		float _x, _y;


		///////////////////////////////////////
		//定数ZEROとONEの定義(ヘッダーファイルでは定数の値の格納まではできない)
		//ZEROでベクトルの長さを０に、ONEで１にする
		///////////////////////////////////////
		static const Vector2 ZERO;
		static const Vector2 ONE;

		/////////////////////////////////////////
		//コンストラクタ
		/////////////////////////////////////////
		Vector2();


		///////////////////////////////////////
		//引数なしコンストラクタ
		//xx : ｘ座標の初期値
		//yy : ｙ座標の初期値
		///////////////////////////////////////
		Vector2(int arg_x, int arg_y);
		Vector2(float arg_x, float arg_y);
		

		//////////////////////////////////////
		//デストラクタ
		//////////////////////////////////////
		virtual ~Vector2();

		//////////////////////////////////////
		//座標を代入する関数
		//xx : 代入するｘ座標
		//yy : 代入するｙ座標
		//vec : 代入するx,y成分を持ったVector2
		//////////////////////////////////////
		void Set(float arg_x, float arg_y);
		void Set(Vector2 arg_vec);

		//////////////////////////////////////
		//ベクトルの大きさを１に揃える(正規化)
		//////////////////////////////////////
		void Normalize();


		//////////////////////////////////////
		//二線のVector2間の内積を返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//////////////////////////////////////
		static float Dot(Vector2 arg_vec1, Vector2 arg_vec2);


		//////////////////////////////////////
		//二線のVector2間の外積を返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//////////////////////////////////////
		static float Cross(Vector2 vvec1, Vector2 arg_vec2);


		//////////////////////////////////////
		//二線のVector2間の角度を返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//////////////////////////////////////
		static float Angle(Vector2 arg_vec1, Vector2 arg_vec2);


		//////////////////////////////////////
		//二線のVector2間の距離を返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//////////////////////////////////////
		static float Distance(Vector2 arg_vec1, Vector2 arg_vec2);
		

		//////////////////////////////////////
		//二線のVector2間の反射角を返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//////////////////////////////////////
		static Vector2 Reflect(Vector2 arg_vec1, Vector2 arg_vec2);
		

		//////////////////////////////////////
		//二線のVector2が交わってるかどうかを返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//vec3 : 三線目のVector2
		//vec4 : 四線目のVector2
		//////////////////////////////////////
		static bool IsCross(Vector2 arg_vec1, Vector2 arg_vec2,Vector2 arg_vec3, Vector2 arg_vec4);


		//各オペレータ
		Vector2 operator +(Vector2);
		void operator +=(Vector2);
		Vector2 operator +(int);
		void operator +=(int);
		Vector2 operator +(float);
		void operator +=(float);
		Vector2 operator -(Vector2);
		void operator -=(Vector2);
		Vector2 operator -(int);
		void operator -=(int);
		Vector2 operator -(float);
		void operator -=(float);
		Vector2 operator *(int);
		void operator *=(int);
		Vector2 operator *(float);
		void operator *=(float);
		Vector2 operator /(int);
		void operator /=(int);
		Vector2 operator /(float);
		void operator /=(float);
		void operator =(Vector2);
		bool operator ==(Vector2);
		bool operator !=(Vector2);

	};


}
#endif // !1
