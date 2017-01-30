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
	_x = _y = _z = 0;
}
Vector3::Vector3(int arg_x, int arg_y,int arg_z) {
	_x = arg_x; _y = arg_y; _z = arg_z;
}
Vector3::Vector3(float arg_x, float arg_y, float arg_z) {
	_x = arg_x; _y = arg_y; _z = arg_z;
}
//デストラクタ
Vector3::~Vector3() {

}

//更新(セット)
void Vector3::Set(float arg_x, float arg_y, float arg_z) {
	_x = arg_x; _y = arg_y; _z = arg_z;
}
void Vector3::Set(Vector3 arg_vec) {
	_x = arg_vec._x; _y = arg_vec._y; _z = arg_vec._z;
}

//正規化
void Vector3::Normalize() {
	float vectorlength = VectorLength(this);
	_x = _x / vectorlength;
	_y = _y / vectorlength;
	_z = _z / vectorlength;
}

//内積
float Vector3::Dot(Vector3 arg_vec1, Vector3 arg_vec2) {
	return arg_vec1._x * arg_vec2._x + arg_vec1._y * arg_vec2._y + arg_vec1._z * arg_vec2._z;
}

//外積
Vector3 Vector3::Cross(Vector3 arg_vec1, Vector3 arg_vec2) {
	Vector3 cross;
	cross._x = arg_vec1._y * arg_vec2._z - arg_vec1._z * arg_vec2._y;
	cross._y = arg_vec1._z * arg_vec2._x - arg_vec1._x * arg_vec2._z;
	cross._z = arg_vec1._x * arg_vec2._y - arg_vec1._y * arg_vec2._x;
	return cross;
}

//鋭角
float Vector3::Angle(Vector3 arg_vec1, Vector3 arg_vec2) {
	//　※ベクトルの長さが0だと答えが出ませんので注意してください。

	//ベクトルAとBの長さを計算する
	float length_A = VectorLength(arg_vec1);
	float length_B = VectorLength(arg_vec2);

	//例外処理的なやつをくわえたい
	//if (length_A == 0 || length_B == 0)

	//内積とベクトル長さを使ってcosθを求める
	float cos_sita = Vector3::Dot(arg_vec1, arg_vec2) / (length_A * length_B);

	//cosθからθを求める
	float sita = acos(Vector3::Dot(arg_vec1, arg_vec2) / (length_A * length_B));

	//度数に変換
	sita = sita * 180.0 / M_PI;

	return sita;
}

//距離
float Vector3::Distance(Vector3 arg_vec1, Vector3 arg_vec2) {
	return sqrt((arg_vec2._x - arg_vec1._x) * (arg_vec2._x - arg_vec1._x) + (arg_vec2._y - arg_vec1._y) * (arg_vec2._y - arg_vec1._y)
		+ (arg_vec2._z - arg_vec1._z) * (arg_vec2._z - arg_vec1._z));
}

//反射角
Vector3 Vector3::Reflect(Vector3 arg_vec1, Vector3 arg_vec2) {

	Vector3 reflect(0, 0, 0);
	//まずvec2の正規化を行うよ
	arg_vec2.Normalize();
	//次に内積を求めるよ
	float dot = Vector3::Dot(arg_vec1, arg_vec2);
	//正反射のベクトルを求めるよ
	reflect._x = 2 * arg_vec2._x * dot - arg_vec1._x;
	reflect._y = 2 * arg_vec2._y * dot - arg_vec1._y;
	reflect._z = 2 * arg_vec2._z * dot - arg_vec1._z;

	return reflect;
}

//交差してるかどうか(不具合あるかも)
bool Vector3::IsCross(Vector3 arg_vec1, Vector3 arg_vec2, Vector3 arg_vec3, Vector3 arg_vec4) {

	float ta, tb, tc, td;
	ta = (arg_vec3._x - arg_vec4._x) * (arg_vec1._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec1._x);
	tb = (arg_vec3._x - arg_vec4._x) * (arg_vec2._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec2._x);
	tc = (arg_vec1._x - arg_vec2._x) * (arg_vec3._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec3._x);
	td = (arg_vec1._x - arg_vec2._x) * (arg_vec4._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec4._x);
	//trueなら交差、falseなら交差してない
	return tc * td < 0 && ta * tb < 0;
}

//長さ
float VectorLength(Vector3 *arg_vec) {
	return sqrt(arg_vec->_x * arg_vec->_x + arg_vec->_y * arg_vec->_y + arg_vec->_z * arg_vec->_z);
}
float VectorLength(Vector3 arg_vec) {
	return sqrt(arg_vec._x * arg_vec._x + arg_vec._y * arg_vec._y + arg_vec._z * arg_vec._z);
}

//３→４
/*Quaternion Vector3::ToQuaternion() {

	Quaternion out;

	float t0 = cos(this->_z * 0.5f);
	float t1 = sin(this->_z * 0.5f);
	float t2 = cos(this->_x * 0.5f);
	float t3 = sin(this->_x * 0.5f);
	float t4 = cos(this->_y * 0.5f);
	float t5 = sin(this->_y * 0.5f);

	out._w = t0 * t2 * t4 + t1 * t3 * t5;
	out._x = t0 * t3 * t4 - t1 * t2 * t5;
	out._y = t0 * t2 * t5 + t1 * t3 * t4;
	out._z = t1 * t2 * t4 - t0 * t3 * t5;

	return out;

}*/

//各オペレータ
Vector3 Vector3::operator +(Vector3 arg_vec) {
	this->_x = this->_x + arg_vec._x;
	this->_y = this->_y + arg_vec._y;
	this->_z = this->_z + arg_vec._z;
	return *this;
}

void Vector3::operator +=(Vector3 arg_vec) {
	*this = *this + arg_vec;
}

Vector3 Vector3::operator +(int arg_num) {
	this->_x = this->_x + arg_num;
	this->_y = this->_y + arg_num;
	this->_z = this->_z + arg_num;
	return *this;
}

void Vector3::operator +=(int arg_num) {
	*this = *this + arg_num;
}

Vector3 Vector3::operator +(float arg_num) {
	this->_x = this->_x + arg_num;
	this->_y = this->_y + arg_num;
	this->_z = this->_z + arg_num;
	return *this;
}

void Vector3::operator +=(float arg_num) {
	*this = *this + arg_num;
}

Vector3 Vector3::operator -(Vector3 arg_vec) {
	this->_x = this->_x - arg_vec._x;
	this->_y = this->_y - arg_vec._y;
	this->_z = this->_z - arg_vec._z;
	return *this;
}

void Vector3::operator -=(Vector3 arg_vec) {
	*this = *this - arg_vec;
}

Vector3 Vector3::operator -(int arg_num) {
	this->_x = this->_x - arg_num;
	this->_y = this->_y - arg_num;
	this->_z = this->_z - arg_num;
	return *this;
}

void Vector3::operator -=(int arg_num) {
	*this = *this - arg_num;
}

Vector3 Vector3::operator -(float arg_num) {
	this->_x = this->_x - arg_num;
	this->_y = this->_y - arg_num;
	this->_z = this->_z - arg_num;
	return *this;
}

void Vector3::operator -=(float arg_num) {
	*this = *this - arg_num;
}

Vector3 Vector3::operator *(int arg_num) {
	this->_x = this->_x * arg_num;
	this->_y = this->_y * arg_num;
	this->_z = this->_z * arg_num;
	return *this;
}

void Vector3::operator *=(int arg_num) {
	*this = *this * arg_num;
}

Vector3 Vector3::operator *(float arg_num) {
	this->_x = this->_x * arg_num;
	this->_y = this->_y * arg_num;
	this->_z = this->_z * arg_num;
	return *this;
}

void Vector3::operator *=(float arg_num) {
	*this = *this * arg_num;
}

Vector3 Vector3::operator /(int arg_num) {
	this->_x = this->_x / arg_num;
	this->_y = this->_y / arg_num;
	this->_z = this->_z / arg_num;
	return *this;
}

void Vector3::operator /=(int arg_num) {
	*this = *this / arg_num;
}

Vector3 Vector3::operator /(float arg_num) {
	this->_x = this->_x / arg_num;
	this->_y = this->_y / arg_num;
	this->_z = this->_z / arg_num;
	return *this;
}

void Vector3::operator /=(float arg_num) {
	*this = *this / arg_num;
}

void Vector3::operator =(Vector3 arg_vec) {
	this->Set(arg_vec);
}

bool Vector3::operator !=(Vector3 arg_vec) {
	bool vectorFlag;
	if (this->_x != arg_vec._x && this->_y != arg_vec._y && this->_z != arg_vec._z) {
		vectorFlag = true;
	}
	else {
		vectorFlag = false;
	}
	return vectorFlag;
}

bool Vector3::operator ==(Vector3 arg_vec) {
	bool vectorFlag;
	if (this->_x == arg_vec._x && this->_y == arg_vec._y && this->_z == arg_vec._z) {
		vectorFlag = true;
	}
	else {
		vectorFlag = false;
	}
	return vectorFlag;
}