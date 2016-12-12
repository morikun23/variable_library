//////////////////////////////////////////////////////////////////
//クラス名： Vector3 
//作成者 ：大山　亮 
//概要  ：原点(ウィンドウの左上端)からのベクトル(力の向きや大きさ)を取得したり変更したりするクラス
//更新  ：H28/12/04/ クラスの作成 
//　　　：H28/12/11/　外積を求める関数を追加
//////////////////////////////////////////////////////////////////
#ifndef VECTOR3
#define VECTOR3

namespace variableNS {

	class Vector3 {

	public:
		//Vector3(x,y,z)
		float x, y,z;


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
		Vector3(float xx, float yy,float zz);


		//////////////////////////////////////
		//デストラクタ
		//////////////////////////////////////
		virtual ~Vector3();

		//////////////////////////////////////
		//座標を代入する関数
		//xx : 代入するｘ座標
		//yy : 代入するｙ座標
		//////////////////////////////////////
		void Set(float xx, float yy, float zz);


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


		//////////////////////////////////////
		//加算のoperator
		//////////////////////////////////////
		Vector3 operator + (Vector3 vec) {
			x = x + vec.x;
			y = y + vec.y;
			z = z + vec.z;
			return *this;
		}
		Vector3 operator += (Vector3 vec) {
			x += vec.x;
			y += vec.y;
			z += vec.z;
			return *this;
		}

		//////////////////////////////////////
		//減算のoperator
		//////////////////////////////////////
		Vector3 operator - (Vector3 vec) {
			x = x - vec.x;
			y = y - vec.y;
			z = z - vec.z;
			return *this;
		}
		Vector3 operator -= (Vector3 vec) {
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
			return *this;
		}

		//////////////////////////////////////
		//偽のoperator
		//////////////////////////////////////
		bool operator != (Vector3 vec) {
			bool vectorFlag;
			if (x != vec.x && y != vec.y && z != vec.z) {
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
		bool operator == (Vector3 vec) {
			bool vectorFlag;
			if (x == vec.x && y == vec.y && z == vec.z) {
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
		Vector3 operator * (int number) {
			x = x * number;
			y = y * number;
			z = z * number;
			return *this;
		}
		Vector3 operator * (float number) {
			x = x * number;
			y = y * number;
			z = z * number;
			return *this;
		}

		//////////////////////////////////////
		//除法のoperator
		//ベクトル同士の除法もご法度だそうです
		//////////////////////////////////////
		Vector3 operator / (int number) {
			x = x / number;
			y = y / number;
			z = z / number;
			return *this;
		}
		Vector3 operator / (float number) {
			x = x / number;
			y = y / number;
		    z = z / number;
			return *this;
		}
	};


}

#endif // !1