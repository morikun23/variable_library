#include"Vector2.h"
#include<cmath>//後で野本のMathライブラリに変更
#define _USE_MATH_DEFINES
#include <math.h>//後で野本のMathライブラリに変更

using namespace variableNS;
//ベクトルの長さを調べる関数のプロトタイプ宣言
//各関数内でしょっちゅう長さを求める必要があるため作成
float VectorLength(Vector2*);
float VectorLength(Vector2);

//ZEROとONEの初期化
const Vector2 Vector2::ZERO = Vector2(0,0);
const Vector2 Vector2::ONE = Vector2(1,1);

//コンストラクタ
Vector2::Vector2() {
	x = y = 0;
}
Vector2::Vector2(float xx, float yy) {
	x = xx; y = yy;
}
//デストラクタ
Vector2::~Vector2() {

}

//更新(セット)
void Vector2::Set(float xx,float yy) {
	x = xx; y = yy;
}

//正規化
void Vector2::Normalize() {
	float vectorlength = VectorLength(this);
	x = x / vectorlength;
	y = y / vectorlength;
}

//内積
float Vector2::Dot(Vector2 vec1, Vector2 vec2) {
	return vec1.x * vec2.x + vec1.y * vec2.y;
}

//外積(二次元のみ返り値はベクトルではなくスカラー値)
float Vector2::Cross(Vector2 vec1, Vector2 vec2) {
	return vec1.x * vec2.y - vec1.y * vec2.x;
}

//鋭角
float Vector2::Angle(Vector2 vec1, Vector2 vec2) {
	//　※ベクトルの長さが0だと答えが出ませんので注意してください。

	//ベクトルAとBの長さを計算する
	float length_A = VectorLength(vec1);
	float length_B = VectorLength(vec2);

	//例外処理的なやつをくわえたい
	//if (length_A == 0 || length_B == 0)

	//内積とベクトル長さを使ってcosθを求める
	float cos_sita = Vector2::Dot(vec1, vec2) / (length_A * length_B);

	//cosθからθを求める
	float sita = acos(Vector2::Dot(vec1, vec2) / (length_A * length_B));

	//度数に変換
	sita = sita * 180.0 / M_PI;

	return sita;
}

//距離
float Vector2::Distance(Vector2 vec1, Vector2 vec2) {
	return sqrt((vec2.x - vec1.x) * (vec2.x - vec1.x) + (vec2.y - vec1.y) * (vec2.y - vec1.y));
}

//反射角
Vector2 Vector2::Reflect(Vector2 vec1, Vector2 vec2) {

	Vector2 reflect(0, 0);
	//まずvec2の正規化を行うよ
	vec2.Normalize();
	//次に内積を求めるよ
	float dot = Vector2::Dot(vec1, vec2);
	//正反射のベクトルを求めるよ
	reflect.x = 2 * vec2.x * dot - vec1.x;
	reflect.y = 2 * vec2.y * dot - vec1.y;

	return reflect;
}

//交差してるかどうか
bool Vector2::IsCross(Vector2 vec1, Vector2 vec2, Vector2 vec3, Vector2 vec4) {
	
	float ta, tb, tc, td;
	ta = (vec3.x - vec4.x) * (vec1.y - vec3.y) + (vec3.y - vec4.y) * (vec3.x - vec1.x);
	tb = (vec3.x - vec4.x) * (vec2.y - vec3.y) + (vec3.y - vec4.y) * (vec3.x - vec2.x);
	tc = (vec1.x - vec2.x) * (vec3.y - vec1.y) + (vec1.y - vec2.y) * (vec1.x - vec3.x);
	td = (vec1.x - vec2.x) * (vec4.y - vec1.y) + (vec1.y - vec2.y) * (vec1.x - vec4.x);
	//trueなら交差、falseなら交差してない
	return tc * td < 0 && ta * tb < 0;
}

//長さ
float VectorLength(Vector2 *vec) {
	return sqrt(vec->x * vec->x + vec->y * vec->y);
}
float VectorLength(Vector2 vec) {
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}