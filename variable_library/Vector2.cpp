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
	_x = _y = 0;
}
Vector2::Vector2(int arg_x, int arg_y) {
	_x = arg_x; _y = arg_y;
}
Vector2::Vector2(float arg_x, float arg_y) {
	_x = arg_x; _y = arg_y;
}
//デストラクタ
Vector2::~Vector2() {

}

//更新(セット)
void Vector2::Set(float arg_x,float arg_y) {
	_x = arg_x; _y = arg_y;
}
void Vector2::Set(Vector2 arg_vec) {
	_x = arg_vec.x; _y = arg_vec.y;
}

//正規化
void Vector2::Normalize() {
	float vectorlength = VectorLength(this);
	_x = _x / vectorlength;
	_y = _y / vectorlength;
}

//内積
float Vector2::Dot(Vector2 arg_vec1, Vector2 arg_vec2) {
	return arg_vec1._x * arg_vec2._x + arg_vec1._y * arg_vec2._y;
}

//外積(二次元のみ返り値はベクトルではなくスカラー値)
float Vector2::Cross(Vector2 arg_vec1, Vector2 arg_vec2) {
	return arg_vec1._x * arg_vec2._y - arg_vec1._y * arg_vec2._x;
}

//鋭角
float Vector2::Angle(Vector2 arg_vec1, Vector2 arg_vec2) {
	//　※ベクトルの長さが0だと答えが出ませんので注意してください。

	//ベクトルAとBの長さを計算する
	float length_A = VectorLength(arg_vec1);
	float length_B = VectorLength(arg_vec2);

	//例外処理的なやつをくわえたい
	//if (length_A == 0 || length_B == 0)

	//内積とベクトル長さを使ってcosθを求める
	float cos_sita = Vector2::Dot(arg_vec1, arg_vec2) / (length_A * length_B);

	//cosθからθを求める
	float sita = acos(Vector2::Dot(arg_vec1, arg_vec2) / (length_A * length_B));

	//度数に変換
	sita = sita * 180.0 / M_PI;

	return sita;
}

//距離
float Vector2::Distance(Vector2 arg_vec1, Vector2 arg_vec2) {
	return sqrt((arg_vec2._x - arg_vec1._x) * (arg_vec2._x - arg_vec1._x) + (arg_vec2._y - arg_vec1._y) * (arg_vec2._y - arg_vec1._y));
}

//反射角
Vector2 Vector2::Reflect(Vector2 arg_vec1, Vector2 arg_vec2) {

	Vector2 reflect(0, 0);
	//まずvec2の正規化を行うよ
	arg_vec2.Normalize();
	//次に内積を求めるよ
	float dot = Vector2::Dot(arg_vec1, arg_vec2);
	//正反射のベクトルを求めるよ
	reflect._x = 2 * arg_vec2._x * dot - arg_vec1._x;
	reflect._y = 2 * arg_vec2._y * dot - arg_vec1._y;

	return reflect;
}

//交差してるかどうか
bool Vector2::IsCross(Vector2 arg_vec1, Vector2 arg_vec2, Vector2 arg_vec3, Vector2 arg_vec4) {
	
	float ta, tb, tc, td;
	ta = (arg_vec3._x - arg_vec4._x) * (arg_vec1._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec1._x);
	tb = (arg_vec3._x - arg_vec4._x) * (arg_vec2._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec2._x);
	tc = (arg_vec1._x - arg_vec2._x) * (arg_vec3._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec3._x);
	td = (arg_vec1._x - arg_vec2._x) * (arg_vec4._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec4._x);
	//trueなら交差、falseなら交差してない
	return tc * td < 0 && ta * tb < 0;
}

//長さ
float VectorLength(Vector2 *arg_vec) {
	return sqrt(arg_vec->_x * arg_vec->_x + arg_vec->_y * arg_vec->_y);
}
float VectorLength(Vector2 arg_vec) {
	return sqrt(arg_vec._x * arg_vec._x + arg_vec._y * arg_vec._y);
}

//各オペレータ
Vector2 Vector2::operator +(Vector2 arg_vec) {
	this->_x = this->_x + arg_vec._x;
	this->_y = this->_y + arg_vec._y;
	return *this;
}

void Vector2::operator +=(Vector2 arg_vec) {
	*this = *this + arg_vec;
}

Vector2 Vector2::operator +(int arg_num) {
	this->_x = this->_x + arg_num;
	this->_y = this->_y + arg_num;
	return *this;
}

void Vector2::operator +=(int arg_num) {
	*this = *this + arg_num;
}

Vector2 Vector2::operator +(float arg_num) {
	this->_x = this->_x + arg_num;
	this->_y = this->_y + arg_num;
	return *this;
}

void Vector2::operator +=(float arg_num) {
	*this = *this + arg_num;
}

Vector2 Vector2::operator -(Vector2 arg_vec) {
	this->_x = this->_x - arg_vec._x;
	this->_y = this->_y - arg_vec._y;
	return *this;
}

void Vector2::operator -=(Vector2 arg_vec) {
	*this = *this - arg_vec;
}

Vector2 Vector2::operator -(int arg_num) {
	this->_x = this->_x - arg_num;
	this->_y = this->_y - arg_num;
	return *this;
}

void Vector2::operator -=(int arg_num) {
	*this = *this - arg_num;
}

Vector2 Vector2::operator -(float arg_num) {
	this->_x = this->_x - arg_num;
	this->_y = this->_y - arg_num;
	return *this;
}

void Vector2::operator -=(float arg_num) {
	*this = *this - arg_num;
}

Vector2 Vector2::operator * (int arg_num) {
	this->_x = this->_x * arg_num;
	this->_y = this->_y * arg_num;
	return *this;
}

void Vector2::operator *=(int arg_num) {
	*this = *this * arg_num;
}

Vector2 Vector2::operator *(float arg_num) {
	this->_x = this->_x * arg_num;
	this->_y = this->_y * arg_num;
	return *this;
}

void Vector2::operator *=(float arg_num) {
	*this = *this * arg_num;
}

Vector2 Vector2::operator /(int arg_num) {
	this->_x = this->_x / arg_num;
	this->_y = this->_y / arg_num;
	return *this;
}

void Vector2::operator /=(int arg_num) {
	*this = *this / arg_num;
}

Vector2 Vector2::operator /(float arg_num) {
	this->_x = this->_x / arg_num;
	this->_y = this->_y / arg_num;
	return *this;
}

void Vector2::operator /=(float arg_num) {
	*this = *this / arg_num;
}

void Vector2::operator =(Vector2 arg_vec) {
	this->Set(arg_vec);
}

bool Vector2::operator !=(Vector2 arg_vec) {
	bool vectorFlag;
	if (this->_x != arg_vec._x && this->_y != arg_vec._y) {
		vectorFlag = true;
	}
	else {
		vectorFlag = false;
	}
	return vectorFlag;
}

bool Vector2::operator ==(Vector2 arg_vec) {
	bool vectorFlag;
	if (this->_x == arg_vec._x && this->_y == arg_vec._y) {
		vectorFlag = true;
	}
	else {
		vectorFlag = false;
	}
	return vectorFlag;
}