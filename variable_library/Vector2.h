//////////////////////////////////////////////////////////////////
//クラス名： Vector2 
//作成者 ：大山　亮 
//概要  ：原点(ウィンドウの左上端)からのベクトル(力の向きや大きさ)を取得したり変更したりするクラス
//更新  ：H28/12/02/ クラスの作成 
//　　　：H28/12/11/　外積を求める関数を追加
//////////////////////////////////////////////////////////////////
#ifndef VECTOR2
#define VECTOR2

namespace variableNS {

	class Vector2 {

	public:
		//Vector2(x,y)
		float x, y;


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
		Vector2(float xx, float yy);
		

		//////////////////////////////////////
		//デストラクタ
		//////////////////////////////////////
		virtual ~Vector2();

		//////////////////////////////////////
		//座標を代入する関数
		//xx : 代入するｘ座標
		//yy : 代入するｙ座標
		//////////////////////////////////////
		void Set(float xx, float yy);


		//////////////////////////////////////
		//ベクトルの大きさを１に揃える(正規化)
		//////////////////////////////////////
		void Normalize();


		//////////////////////////////////////
		//二線のVector2間の内積を返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//////////////////////////////////////
		static float Dot(Vector2 vec1, Vector2 vec2);


		//////////////////////////////////////
		//二線のVector2間の外積を返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//////////////////////////////////////
		static float Cross(Vector2 vec1, Vector2 vec2);


		//////////////////////////////////////
		//二線のVector2間の角度を返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//////////////////////////////////////
		static float Angle(Vector2 vec1, Vector2 vec2);


		//////////////////////////////////////
		//二線のVector2間の距離を返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//////////////////////////////////////
		static float Distance(Vector2 vec1, Vector2 vec2);
		

		//////////////////////////////////////
		//二線のVector2間の反射角を返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//////////////////////////////////////
		static Vector2 Reflect(Vector2 vec1, Vector2 vec2);
		

		//////////////////////////////////////
		//二線のVector2が交わってるかどうかを返す
		//vec1 : 一線目のVector2
		//vec2 : 二線目のVector2
		//vec3 : 三線目のVector2
		//vec4 : 四線目のVector2
		//////////////////////////////////////
		static bool IsCross(Vector2 vec1, Vector2 vec2,Vector2 vec3, Vector2 vec4);


		//////////////////////////////////////
		//加算のoperator
		//////////////////////////////////////
		Vector2 operator + (Vector2 vec) {
			x = x + vec.x;
			y = y + vec.y;
			return *this;
		}
		Vector2 operator += (Vector2 vec) {
			x += vec.x;
			y += vec.y;
			return *this;
		}

		//////////////////////////////////////
		//減算のoperator
		//////////////////////////////////////
		Vector2 operator - (Vector2 vec) {
			x = x - vec.x;
			y = y - vec.y;
			return *this;
		}
		Vector2 operator -= (Vector2 vec) {
			x -= vec.x;
			y -= vec.y;
			return *this;
		}

		//////////////////////////////////////
		//偽のoperator
		//////////////////////////////////////
		bool operator != (Vector2 vec) {
			bool vectorFlag;
			if (x != vec.x && y != vec.y) {
				vectorFlag = true;
			}
			else {
				vectorFlag = false;
			}
			return vectorFlag;
		}

		//////////////////////////////////////
		//真のoperator
		//////////////////////////////////////
		bool operator == (Vector2 vec) {
			bool vectorFlag;
			if (x == vec.x && y == vec.y) {
				vectorFlag = true;
			}
			else {
				vectorFlag = false;
			}
			return vectorFlag;
		}

		//////////////////////////////////////
		//乗算のoperator
		//ベクトル同士の乗算はご法度だそうです
		//////////////////////////////////////
		Vector2 operator * (int number) {
			x = x * number;
			y = y * number;
			return *this;
		}
		Vector2 operator * (float number) {
			x = x * number;
			y = y * number;
			return *this;
		}

		//////////////////////////////////////
		//除法のoperator
		//ベクトル同士の除法もご法度だそうです
		//////////////////////////////////////
		Vector2 operator / (int number) {
			x = x / number;
			y = y / number;
			return *this;
		}
		Vector2 operator / (float number) {
			x = x / number;
			y = y / number;
			return *this;
		}

	};


}
#endif // !1
