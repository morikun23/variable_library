#include"Vector4.h"
#include<cmath>//後で野本のMathライブラリに変更
#define _USE_MATH_DEFINES
#include <math.h>//後で野本のMathライブラリに変更

using namespace variableNS;
//ベクトルの長さを調べる関数のプロトタイプ宣言
//各関数内でしょっちゅう長さを求める必要があるため作成
float VectorLength(Vector4*);
float VectorLength(Vector4);

//ZEROとONEの初期化
const Vector4 Vector4::ZERO = Vector4(0, 0, 0, 0);
const Vector4 Vector4::ONE = Vector4(1, 1, 1, 1);

//コンストラクタ
Vector4::Vector4() {
	x = y = z = w = 0;
}
Vector4::Vector4(int xx, int yy, int zz,int ww) {
	x = xx; y = yy; z = zz; w = ww;
}
Vector4::Vector4(float xx, float yy, float zz, float ww) {
	x = xx; y = yy; z = zz; w = ww;
}
//デストラクタ
Vector4::~Vector4() {

}

//更新(セット)
void Vector4::Set(float arg_x, float arg_y, float arg_z, float arg_w) {
	_x = arg_x; _y = arg_y; _z = arg_z; _w = arg_w;
}
void Vector4::Set(Vector4 arg_vec) {
	_x = arg_vec._x; _y = arg_vec._y; _z = arg_vec._z; _w = arg_vec._w;
}

//正規化
void Vector4::Normalize() {
	float vectorlength = VectorLength(this);
	_x = _x / vectorlength;
	_y = _y / vectorlength;
	_z = _z / vectorlength;
	_w = _w / vectorlength;
}

//内積
float Vector4::Dot(Vector4 arg_vec1, Vector4 arg_vec2) {
	return arg_vec1._x * arg_vec2._x + arg_vec1._y * arg_vec2._y + arg_vec1._z * arg_vec2._z + arg_vec1._w * arg_vec2._w;
}

//外積
Vector4 Vector4::Cross(Vector4 arg_vec1, Vector4 arg_vec2) {
	Vector4 cross;
	cross._x = arg_vec1._y * arg_vec2._z - arg_vec1._z * arg_vec2._y;
	cross._y = arg_vec1._z * arg_vec2._x - arg_vec1._x * arg_vec2._z;
	cross._z = arg_vec1._x * arg_vec2._y - arg_vec1._y * arg_vec2._x;
	cross._w = 0;
	return cross;
}

//鋭角
float Vector4::Angle(Vector4 arg_vec1, Vector4 arg_vec2) {
	//　※ベクトルの長さが0だと答えが出ませんので注意してください。

	//ベクトルAとBの長さを計算する
	float length_A = VectorLength(arg_vec1);
	float length_B = VectorLength(arg_vec2);

	//例外処理的なやつをくわえたい
	//if (length_A == 0 || length_B == 0)

	//内積とベクトル長さを使ってcosθを求める
	float cos_sita = Vector4::Dot(arg_vec1, arg_vec2) / (length_A * length_B);

	//cosθからθを求める
	float sita = acos(Vector4::Dot(arg_vec1, arg_vec2) / (length_A * length_B));

	//度数に変換
	sita = sita * 180.0 / M_PI;

	return sita;
}

//距離
float Vector4::Distance(Vector4 arg_vec1, Vector4 arg_vec2) {
	return sqrt((arg_vec2._x - arg_vec1._x) * (arg_vec2._x - arg_vec1._x) + (arg_vec2._y - arg_vec1._y) * (arg_vec2._y - arg_vec1._y)
		+ (arg_vec2._z - arg_vec1._z) * (arg_vec2._z - arg_vec1._z) + (arg_vec2._w - arg_vec1._w) * (arg_vec2._w - arg_vec1._w));
}

//反射角
Vector4 Vector4::Reflect(Vector4 arg_vec1, Vector4 arg_vec2) {

	Vector4 reflect(0, 0, 0, 0);
	//まずvec2の正規化を行うよ
	arg_vec2.Normalize();
	//次に内積を求めるよ
	float dot = Vector4::Dot(arg_vec1, arg_vec2);
	//正反射のベクトルを求めるよ
	reflect._x = 2 * arg_vec2._x * dot - arg_vec1._x;
	reflect._y = 2 * arg_vec2._y * dot - arg_vec1._y;
	reflect._z = 2 * arg_vec2._z * dot - arg_vec1._z;
	reflect._w = 2 * arg_vec2._w * dot - arg_vec1._w;

	return reflect;
}

//交差してるかどうか(不具合あるかも)
bool Vector4::IsCross(Vector4 arg_vec1, Vector4 arg_vec2, Vector4 arg_vec3, Vector4 arg_vec4) {

	float ta, tb, tc, td;
	ta = (arg_vec3._x - arg_vec4._x) * (arg_vec1._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec1._x);
	tb = (arg_vec3._x - arg_vec4._x) * (arg_vec2._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec2._x);
	tc = (arg_vec1._x - arg_vec2._x) * (arg_vec3._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec3._x);
	td = (arg_vec1._x - arg_vec2._x) * (arg_vec4._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec4._x);
	//trueなら交差、falseなら交差してない
	return tc * td < 0 && ta * tb < 0;
}

//長さ
float VectorLength(Vector4 *arg_vec) {
	return sqrt(arg_vec->_x * arg_vec->_x + arg_vec->_y * arg_vec->_y + arg_vec->_z * arg_vec->_z + arg_vec->_w * arg_vec->_w);
}
float VectorLength(Vector4 arg_vec) {
	return sqrt(arg_vec._x * arg_vec._x + arg_vec._y * arg_vec._y + arg_vec._z * arg_vec._z + arg_vec._w * arg_vec._w);
}

//各オペレータ
Vector4 Vector4::operator +(Vector4 arg_vec) {
	this->_x = this->_x + arg_vec._x;
	this->_y = this->_y + arg_vec._y;
	this->_z = this->_z + arg_vec._z;
	this->_w = this->_w + arg_vec._w;
	return *this;
}

void Vector4::operator +=(Vector4 arg_vec) {
	*this = *this + arg_vec;
}

Vector4 Vector4::operator +(int arg_num) {
	this->_x = this->_x + arg_num;
	this->_y = this->_y + arg_num;
	this->_z = this->_z + arg_num;
	this->_w = this->_w + arg_num;
	return *this;
}

void Vector4::operator +=(int arg_num) {
	*this = *this + arg_num;
}

Vector4 Vector4::operator +(float arg_num) {
	this->_x = this->_x + arg_num;
	this->_y = this->_y + arg_num;
	this->_z = this->_z + arg_num;
	this->_w = this->_w + arg_num;
	return *this;
}

void Vector4::operator +=(float arg_num) {
	*this = *this + arg_num;
}

Vector4 Vector4::operator -(Vector4 arg_vec) {
	this->_x = this->_x - arg_vec._x;
	this->_y = this->_y - arg_vec._y;
	this->_z = this->_z - arg_vec._z;
	this->_w = this->_w - arg_vec._w;
	return *this;
}

void Vector4::operator -=(Vector4 arg_vec) {
	*this = *this - arg_vec;
}

Vector4 Vector4::operator -(int arg_num) {
	this->_x = this->_x - arg_num;
	this->_y = this->_y - arg_num;
	this->_z = this->_z - arg_num;
	this->_w = this->_w - arg_num;
	return *this;
}

void Vector4::operator -=(int arg_num) {
	*this = *this - arg_num;
}

Vector4 Vector4::operator -(float arg_num) {
	this->_x = this->_x - arg_num;
	this->_y = this->_y - arg_num;
	this->_z = this->_z - arg_num;
	this->_w = this->_w - arg_num;
	return *this;
}

void Vector4::operator -=(float arg_num) {
	*this = *this - arg_num;
}

Vector4 Vector4::operator *(int arg_num) {
	this->_x = this->_x * arg_num;
	this->_y = this->_y * arg_num;
	this->_z = this->_z * arg_num;
	this->_w = this->_w * arg_num;
	return *this;
}

void Vector4::operator *=(int arg_num) {
	*this = *this * arg_num;
}

Vector4 Vector4::operator *(float arg_num) {
	this->_x = this->_x * arg_num;
	this->_y = this->_y * arg_num;
	this->_z = this->_z * arg_num;
	this->_w = this->_w * arg_num;
	return *this;
}

void Vector4::operator *=(float arg_num) {
	*this = *this * arg_num;
}

Vector4 Vector4::operator /(int arg_num) {
	this->_x = this->_x / arg_num;
	this->_y = this->_y / arg_num;
	this->_z = this->_z / arg_num;
	this->_w = this->_w / arg_num;
	return *this;
}

void Vector4::operator /=(int arg_num) {
	*this = *this / arg_num;
}

Vector4 Vector4::operator /(float arg_num) {
	this->_x = this->_x / arg_num;
	this->_y = this->_y / arg_num;
	this->_z = this->_z / arg_num;
	this->_w = this->_w / arg_num;
	return *this;
}

void Vector4::operator /=(float arg_num) {
	*this = *this / arg_num;
}

void Vector4::operator =(Vector4 arg_vec) {
	this->Set(arg_vec);
}

bool Vector4::operator !=(Vector4 arg_vec) {
	bool vectorFlag;
	if (this->_x != arg_vec._x && this->_y != arg_vec._y && this->_z != arg_vec._z && this->_w != arg_vec._w) {
		vectorFlag = true;
	}
	else {
		vectorFlag = false;
	}
	return vectorFlag;
}

bool Vector4::operator ==(Vector4 arg_vec) {
	bool vectorFlag;
	if (this->_x == arg_vec._x && this->_y == arg_vec._y && this->_z == arg_vec._z && this->_w == arg_vec._w) {
		vectorFlag = true;
	}
	else {
		vectorFlag = false;
	}
	return vectorFlag;
}