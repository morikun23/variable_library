#include"Vector3.h"
#include<cmath>//後で野本のMathライブラリに変更
#define _USE_MATH_DEFINES
#include <math.h>//後で野本のMathライブラリに変更

using namespace variableNS;
//ベクトルの長さを調べる関数のプロトタイプ宣言
//各関数内でしょっちゅう長さを求める必要があるため作成
float VectorLength(Vector3*);
float VectorLength(Vector3);

//ZEROとONEの初期化
const Vector3 Vector3::ZERO = Vector3(0, 0, 0);
const Vector3 Vector3::ONE = Vector3(1, 1, 1);

//コンストラクタ
Vector3::Vector3() {
	x = y = z = 0;
}
Vector3::Vector3(int xx, int yy,int zz) {
	x = xx; y = yy; z = zz;
}
Vector3::Vector3(float xx, float yy, float zz) {
	x = xx; y = yy; z = zz;
}
//デストラクタ
Vector3::~Vector3() {

}

//更新(セット)
void Vector3::Set(float xx, float yy, float zz) {
	x = xx; y = yy; z = zz;
}
void Vector3::Set(Vector3 vec) {
	x = vec.x; y = vec.y; z = vec.z;
}

//正規化
void Vector3::Normalize() {
	float vectorlength = VectorLength(this);
	x = x / vectorlength;
	y = y / vectorlength;
	z = z / vectorlength;
}

//内積
float Vector3::Dot(Vector3 vec1, Vector3 vec2) {
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

//外積
Vector3 Vector3::Cross(Vector3 vec1, Vector3 vec2) {
	Vector3 cross;
	cross.x = vec1.y * vec2.z - vec1.z * vec2.y;
	cross.y = vec1.z * vec2.x - vec1.x * vec2.z;
	cross.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return cross;
}

//鋭角
float Vector3::Angle(Vector3 vec1, Vector3 vec2) {
	//　※ベクトルの長さが0だと答えが出ませんので注意してください。

	//ベクトルAとBの長さを計算する
	float length_A = VectorLength(vec1);
	float length_B = VectorLength(vec2);

	//例外処理的なやつをくわえたい
	//if (length_A == 0 || length_B == 0)

	//内積とベクトル長さを使ってcosθを求める
	float cos_sita = Vector3::Dot(vec1, vec2) / (length_A * length_B);

	//cosθからθを求める
	float sita = acos(Vector3::Dot(vec1, vec2) / (length_A * length_B));

	//度数に変換
	sita = sita * 180.0 / M_PI;

	return sita;
}

//距離
float Vector3::Distance(Vector3 vec1, Vector3 vec2) {
	return sqrt((vec2.x - vec1.x) * (vec2.x - vec1.x) + (vec2.y - vec1.y) * (vec2.y - vec1.y) + (vec2.z - vec1.z) * (vec2.z - vec1.z));
}

//反射角
Vector3 Vector3::Reflect(Vector3 vec1, Vector3 vec2) {

	Vector3 reflect(0, 0, 0);
	//まずvec2の正規化を行うよ
	vec2.Normalize();
	//次に内積を求めるよ
	float dot = Vector3::Dot(vec1, vec2);
	//正反射のベクトルを求めるよ
	reflect.x = 2 * vec2.x * dot - vec1.x;
	reflect.y = 2 * vec2.y * dot - vec1.y;
	reflect.z = 2 * vec2.z * dot - vec1.z;

	return reflect;
}

//交差してるかどうか(不具合あるかも)
bool Vector3::IsCross(Vector3 vec1, Vector3 vec2, Vector3 vec3, Vector3 vec4) {

	float ta, tb, tc, td;
	ta = (vec3.x - vec4.x) * (vec1.y - vec3.y) + (vec3.y - vec4.y) * (vec3.x - vec1.x);
	tb = (vec3.x - vec4.x) * (vec2.y - vec3.y) + (vec3.y - vec4.y) * (vec3.x - vec2.x);
	tc = (vec1.x - vec2.x) * (vec3.y - vec1.y) + (vec1.y - vec2.y) * (vec1.x - vec3.x);
	td = (vec1.x - vec2.x) * (vec4.y - vec1.y) + (vec1.y - vec2.y) * (vec1.x - vec4.x);
	//trueなら交差、falseなら交差してない
	return tc * td < 0 && ta * tb < 0;
}

//長さ
float VectorLength(Vector3 *vec) {
	return sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}
float VectorLength(Vector3 vec) {
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

//各オペレータ
Vector3 Vector3::operator +(Vector3 vec) {
	this->x = this->x + vec.x;
	this->y = this->y + vec.y;
	this->z = this->z + vec.z;
	return *this;
}

void Vector3::operator +=(Vector3 vec) {
	*this = *this + vec;
}

Vector3 Vector3::operator +(int num) {
	this->x = this->x + num;
	this->y = this->y + num;
	this->z = this->z + num;
	return *this;
}

void Vector3::operator +=(int num) {
	*this = *this + num;
}

Vector3 Vector3::operator +(float num) {
	this->x = this->x + num;
	this->y = this->y + num;
	this->z = this->z + num;
	return *this;
}

void Vector3::operator +=(float num) {
	*this = *this + num;
}

Vector3 Vector3::operator -(Vector3 vec) {
	this->x = this->x - vec.x;
	this->y = this->y - vec.y;
	this->z = this->z - vec.z;
	return *this;
}

void Vector3::operator -=(Vector3 vec) {
	*this = *this - vec;
}

Vector3 Vector3::operator -(int num) {
	this->x = this->x - num;
	this->y = this->y - num;
	this->z = this->z - num;
	return *this;
}

void Vector3::operator -=(int num) {
	*this = *this - num;
}

Vector3 Vector3::operator -(float num) {
	this->x = this->x - num;
	this->y = this->y - num;
	this->z = this->z - num;
	return *this;
}

void Vector3::operator -=(float num) {
	*this = *this - num;
}

Vector3 Vector3::operator *(int num) {
	this->x = this->x * num;
	this->y = this->y * num;
	this->z = this->z * num;
	return *this;
}

void Vector3::operator *=(int num) {
	*this = *this * num;
}

Vector3 Vector3::operator *(float num) {
	this->x = this->x * num;
	this->y = this->y * num;
	this->z = this->z * num;
	return *this;
}

void Vector3::operator *=(float num) {
	*this = *this * num;
}

Vector3 Vector3::operator /(int num) {
	this->x = this->x / num;
	this->y = this->y / num;
	this->z = this->z / num;
	return *this;
}

void Vector3::operator /=(int num) {
	*this = *this / num;
}

Vector3 Vector3::operator /(float num) {
	this->x = this->x / num;
	this->y = this->y / num;
	this->z = this->z / num;
	return *this;
}

void Vector3::operator /=(float num) {
	*this = *this / num;
}

void Vector3::operator =(Vector3 vec) {
	this->Set(vec);
}

bool Vector3::operator !=(Vector3 vec) {
	bool vectorFlag;
	if (this->x != vec.x && this->y != vec.y && this->z != vec.z) {
		vectorFlag = true;
	}
	else {
		vectorFlag = false;
	}
	return vectorFlag;
}

bool Vector3::operator ==(Vector3 vec) {
	bool vectorFlag;
	if (this->x == vec.x && this->y == vec.y && this->z == vec.z) {
		vectorFlag = true;
	}
	else {
		vectorFlag = false;
	}
	return vectorFlag;
}