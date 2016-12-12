//////////////////////////////////////////////////////////////////
//クラス名： Vector4 
//作成者 ：大山　亮 
//概要  ：原点(ウィンドウの左上端)からのベクトル(力の向きや大きさ)を取得したり変更したりするクラス
//更新  ：H28/12/05/ クラスの作成 
//　　　：H28/12/11/　外積を求める関数を追加
//////////////////////////////////////////////////////////////////
#ifndef VECTOR4
#define VECTOR4

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
		Vector4(float xx, float yy, float zz,float ww);


		//////////////////////////////////////
		//デストラクタ
		//////////////////////////////////////
		virtual ~Vector4();

		//////////////////////////////////////
		//座標を代入する関数
		//xx : 代入するｘ座標
		//yy : 代入するｙ座標
		//////////////////////////////////////
		void Set(float xx, float yy, float zz, float ww);


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


		//////////////////////////////////////
		//加算のoperator
		//////////////////////////////////////
		Vector4 operator + (Vector4 vec) {
			x = x + vec.x;
			y = y + vec.y;
			z = z + vec.z;
			w = w + vec.w;
			return *this;
		}
		Vector4 operator += (Vector4 vec) {
			x += vec.x;
			y += vec.y;
			z += vec.z;
			w += vec.w;
			return *this;
		}

		//////////////////////////////////////
		//減算のoperator
		//////////////////////////////////////
		Vector4 operator - (Vector4 vec) {
			x = x - vec.x;
			y = y - vec.y;
			z = z - vec.z;
			w = w - vec.w;
			return *this;
		}
		Vector4 operator -= (Vector4 vec) {
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
			w -= vec.w;
			return *this;
		}

		//////////////////////////////////////
		//偽のoperator
		//////////////////////////////////////
		bool operator != (Vector4 vec) {
			bool vectorFlag;
			if (x != vec.x && y != vec.y && z != vec.z && w != vec.w) {
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
		bool operator == (Vector4 vec) {
			bool vectorFlag;
			if (x == vec.x && y == vec.y && z == vec.z && w == vec.w) {
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
		Vector4 operator * (int number) {
			x = x * number;
			y = y * number;
			z = z * number;
			w = w * number;
			return *this;
		}
		Vector4 operator * (float number) {
			x = x * number;
			y = y * number;
			z = z * number;
			w = w * number;
			return *this;
		}

		//////////////////////////////////////
		//除法のoperator
		//ベクトル同士の除法もご法度だそうです
		//////////////////////////////////////
		Vector4 operator / (int number) {
			x = x / number;
			y = y / number;
			z = z / number;
			w = w / number;
			return *this;
		}
		Vector4 operator / (float number) {
			x = x / number;
			y = y / number;
			z = z / number;
			w = w / number;
			return *this;
		}
	};


}

#endif // !1