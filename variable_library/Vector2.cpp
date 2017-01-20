#include"Vector2.h"
#include<cmath>//��Ŗ�{��Math���C�u�����ɕύX
#define _USE_MATH_DEFINES
#include <math.h>//��Ŗ�{��Math���C�u�����ɕύX

using namespace variableNS;
//�x�N�g���̒����𒲂ׂ�֐��̃v���g�^�C�v�錾
//�e�֐����ł�������イ���������߂�K�v�����邽�ߍ쐬
float VectorLength(Vector2*);
float VectorLength(Vector2);

//ZERO��ONE�̏�����
const Vector2 Vector2::ZERO = Vector2(0,0);
const Vector2 Vector2::ONE = Vector2(1,1);

//�R���X�g���N�^
Vector2::Vector2() {
	_x = _y = 0;
}
Vector2::Vector2(int arg_x, int arg_y) {
	_x = arg_x; _y = arg_y;
}
Vector2::Vector2(float arg_x, float arg_y) {
	_x = arg_x; _y = arg_y;
}
//�f�X�g���N�^
Vector2::~Vector2() {

}

//�X�V(�Z�b�g)
void Vector2::Set(float arg_x,float arg_y) {
	_x = arg_x; _y = arg_y;
}
void Vector2::Set(Vector2 arg_vec) {
	_x = arg_vec.x; _y = arg_vec.y;
}

//���K��
void Vector2::Normalize() {
	float vectorlength = VectorLength(this);
	_x = _x / vectorlength;
	_y = _y / vectorlength;
}

//����
float Vector2::Dot(Vector2 arg_vec1, Vector2 arg_vec2) {
	return arg_vec1._x * arg_vec2._x + arg_vec1._y * arg_vec2._y;
}

//�O��(�񎟌��̂ݕԂ�l�̓x�N�g���ł͂Ȃ��X�J���[�l)
float Vector2::Cross(Vector2 arg_vec1, Vector2 arg_vec2) {
	return arg_vec1._x * arg_vec2._y - arg_vec1._y * arg_vec2._x;
}

//�s�p
float Vector2::Angle(Vector2 arg_vec1, Vector2 arg_vec2) {
	//�@���x�N�g���̒�����0���Ɠ������o�܂���̂Œ��ӂ��Ă��������B

	//�x�N�g��A��B�̒������v�Z����
	float length_A = VectorLength(arg_vec1);
	float length_B = VectorLength(arg_vec2);

	//��O�����I�Ȃ�����킦����
	//if (length_A == 0 || length_B == 0)

	//���ςƃx�N�g���������g����cos�Ƃ����߂�
	float cos_sita = Vector2::Dot(arg_vec1, arg_vec2) / (length_A * length_B);

	//cos�Ƃ���Ƃ����߂�
	float sita = acos(Vector2::Dot(arg_vec1, arg_vec2) / (length_A * length_B));

	//�x���ɕϊ�
	sita = sita * 180.0 / M_PI;

	return sita;
}

//����
float Vector2::Distance(Vector2 arg_vec1, Vector2 arg_vec2) {
	return sqrt((arg_vec2._x - arg_vec1._x) * (arg_vec2._x - arg_vec1._x) + (arg_vec2._y - arg_vec1._y) * (arg_vec2._y - arg_vec1._y));
}

//���ˊp
Vector2 Vector2::Reflect(Vector2 arg_vec1, Vector2 arg_vec2) {

	Vector2 reflect(0, 0);
	//�܂�vec2�̐��K�����s����
	arg_vec2.Normalize();
	//���ɓ��ς����߂��
	float dot = Vector2::Dot(arg_vec1, arg_vec2);
	//�����˂̃x�N�g�������߂��
	reflect._x = 2 * arg_vec2._x * dot - arg_vec1._x;
	reflect._y = 2 * arg_vec2._y * dot - arg_vec1._y;

	return reflect;
}

//�������Ă邩�ǂ���
bool Vector2::IsCross(Vector2 arg_vec1, Vector2 arg_vec2, Vector2 arg_vec3, Vector2 arg_vec4) {
	
	float ta, tb, tc, td;
	ta = (arg_vec3._x - arg_vec4._x) * (arg_vec1._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec1._x);
	tb = (arg_vec3._x - arg_vec4._x) * (arg_vec2._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec2._x);
	tc = (arg_vec1._x - arg_vec2._x) * (arg_vec3._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec3._x);
	td = (arg_vec1._x - arg_vec2._x) * (arg_vec4._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec4._x);
	//true�Ȃ�����Afalse�Ȃ�������ĂȂ�
	return tc * td < 0 && ta * tb < 0;
}

//����
float VectorLength(Vector2 *arg_vec) {
	return sqrt(arg_vec->_x * arg_vec->_x + arg_vec->_y * arg_vec->_y);
}
float VectorLength(Vector2 arg_vec) {
	return sqrt(arg_vec._x * arg_vec._x + arg_vec._y * arg_vec._y);
}

//�e�I�y���[�^
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