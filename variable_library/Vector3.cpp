#include"Vector3.h"
#include<cmath>//��Ŗ�{��Math���C�u�����ɕύX
#define _USE_MATH_DEFINES
#include <math.h>//��Ŗ�{��Math���C�u�����ɕύX

using namespace variableNS;
//�x�N�g���̒����𒲂ׂ�֐��̃v���g�^�C�v�錾
//�e�֐����ł�������イ���������߂�K�v�����邽�ߍ쐬
float VectorLength(Vector3*);
float VectorLength(Vector3);

//ZERO��ONE�̏�����
const Vector3 Vector3::ZERO = Vector3(0, 0, 0);
const Vector3 Vector3::ONE = Vector3(1, 1, 1);

//�R���X�g���N�^
Vector3::Vector3() {
	_x = _y = _z = 0;
}
Vector3::Vector3(int arg_x, int arg_y,int arg_z) {
	_x = arg_x; _y = arg_y; _z = arg_z;
}
Vector3::Vector3(float arg_x, float arg_y, float arg_z) {
	_x = arg_x; _y = arg_y; _z = arg_z;
}
//�f�X�g���N�^
Vector3::~Vector3() {

}

//�X�V(�Z�b�g)
void Vector3::Set(float arg_x, float arg_y, float arg_z) {
	_x = arg_x; _y = arg_y; _z = arg_z;
}
void Vector3::Set(Vector3 arg_vec) {
	_x = arg_vec._x; _y = arg_vec._y; _z = arg_vec._z;
}

//���K��
void Vector3::Normalize() {
	float vectorlength = VectorLength(this);
	_x = _x / vectorlength;
	_y = _y / vectorlength;
	_z = _z / vectorlength;
}

//����
float Vector3::Dot(Vector3 arg_vec1, Vector3 arg_vec2) {
	return arg_vec1._x * arg_vec2._x + arg_vec1._y * arg_vec2._y + arg_vec1._z * arg_vec2._z;
}

//�O��
Vector3 Vector3::Cross(Vector3 arg_vec1, Vector3 arg_vec2) {
	Vector3 cross;
	cross._x = arg_vec1._y * arg_vec2._z - arg_vec1._z * arg_vec2._y;
	cross._y = arg_vec1._z * arg_vec2._x - arg_vec1._x * arg_vec2._z;
	cross._z = arg_vec1._x * arg_vec2._y - arg_vec1._y * arg_vec2._x;
	return cross;
}

//�s�p
float Vector3::Angle(Vector3 arg_vec1, Vector3 arg_vec2) {
	//�@���x�N�g���̒�����0���Ɠ������o�܂���̂Œ��ӂ��Ă��������B

	//�x�N�g��A��B�̒������v�Z����
	float length_A = VectorLength(arg_vec1);
	float length_B = VectorLength(arg_vec2);

	//��O�����I�Ȃ�����킦����
	//if (length_A == 0 || length_B == 0)

	//���ςƃx�N�g���������g����cos�Ƃ����߂�
	float cos_sita = Vector3::Dot(arg_vec1, arg_vec2) / (length_A * length_B);

	//cos�Ƃ���Ƃ����߂�
	float sita = acos(Vector3::Dot(arg_vec1, arg_vec2) / (length_A * length_B));

	//�x���ɕϊ�
	sita = sita * 180.0 / M_PI;

	return sita;
}

//����
float Vector3::Distance(Vector3 arg_vec1, Vector3 arg_vec2) {
	return sqrt((arg_vec2._x - arg_vec1._x) * (arg_vec2._x - arg_vec1._x) + (arg_vec2._y - arg_vec1._y) * (arg_vec2._y - arg_vec1._y)
		+ (arg_vec2._z - arg_vec1._z) * (arg_vec2._z - arg_vec1._z));
}

//���ˊp
Vector3 Vector3::Reflect(Vector3 arg_vec1, Vector3 arg_vec2) {

	Vector3 reflect(0, 0, 0);
	//�܂�vec2�̐��K�����s����
	arg_vec2.Normalize();
	//���ɓ��ς����߂��
	float dot = Vector3::Dot(arg_vec1, arg_vec2);
	//�����˂̃x�N�g�������߂��
	reflect._x = 2 * arg_vec2._x * dot - arg_vec1._x;
	reflect._y = 2 * arg_vec2._y * dot - arg_vec1._y;
	reflect._z = 2 * arg_vec2._z * dot - arg_vec1._z;

	return reflect;
}

//�������Ă邩�ǂ���(�s����邩��)
bool Vector3::IsCross(Vector3 arg_vec1, Vector3 arg_vec2, Vector3 arg_vec3, Vector3 arg_vec4) {

	float ta, tb, tc, td;
	ta = (arg_vec3._x - arg_vec4._x) * (arg_vec1._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec1._x);
	tb = (arg_vec3._x - arg_vec4._x) * (arg_vec2._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec2._x);
	tc = (arg_vec1._x - arg_vec2._x) * (arg_vec3._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec3._x);
	td = (arg_vec1._x - arg_vec2._x) * (arg_vec4._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec4._x);
	//true�Ȃ�����Afalse�Ȃ�������ĂȂ�
	return tc * td < 0 && ta * tb < 0;
}

//����
float VectorLength(Vector3 *arg_vec) {
	return sqrt(arg_vec->_x * arg_vec->_x + arg_vec->_y * arg_vec->_y + arg_vec->_z * arg_vec->_z);
}
float VectorLength(Vector3 arg_vec) {
	return sqrt(arg_vec._x * arg_vec._x + arg_vec._y * arg_vec._y + arg_vec._z * arg_vec._z);
}

//�R���S
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

//�e�I�y���[�^
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