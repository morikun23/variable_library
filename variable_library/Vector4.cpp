#include"Vector4.h"
#include<cmath>//��Ŗ�{��Math���C�u�����ɕύX
#define _USE_MATH_DEFINES
#include <math.h>//��Ŗ�{��Math���C�u�����ɕύX

using namespace variableNS;
//�x�N�g���̒����𒲂ׂ�֐��̃v���g�^�C�v�錾
//�e�֐����ł�������イ���������߂�K�v�����邽�ߍ쐬
float VectorLength(Vector4*);
float VectorLength(Vector4);

//ZERO��ONE�̏�����
const Vector4 Vector4::ZERO = Vector4(0, 0, 0, 0);
const Vector4 Vector4::ONE = Vector4(1, 1, 1, 1);

//�R���X�g���N�^
Vector4::Vector4() {
	x = y = z = w = 0;
}
Vector4::Vector4(int xx, int yy, int zz,int ww) {
	x = xx; y = yy; z = zz; w = ww;
}
Vector4::Vector4(float xx, float yy, float zz, float ww) {
	x = xx; y = yy; z = zz; w = ww;
}
//�f�X�g���N�^
Vector4::~Vector4() {

}

//�X�V(�Z�b�g)
void Vector4::Set(float arg_x, float arg_y, float arg_z, float arg_w) {
	_x = arg_x; _y = arg_y; _z = arg_z; _w = arg_w;
}
void Vector4::Set(Vector4 arg_vec) {
	_x = arg_vec._x; _y = arg_vec._y; _z = arg_vec._z; _w = arg_vec._w;
}

//���K��
void Vector4::Normalize() {
	float vectorlength = VectorLength(this);
	_x = _x / vectorlength;
	_y = _y / vectorlength;
	_z = _z / vectorlength;
	_w = _w / vectorlength;
}

//����
float Vector4::Dot(Vector4 arg_vec1, Vector4 arg_vec2) {
	return arg_vec1._x * arg_vec2._x + arg_vec1._y * arg_vec2._y + arg_vec1._z * arg_vec2._z + arg_vec1._w * arg_vec2._w;
}

//�O��
Vector4 Vector4::Cross(Vector4 arg_vec1, Vector4 arg_vec2) {
	Vector4 cross;
	cross._x = arg_vec1._y * arg_vec2._z - arg_vec1._z * arg_vec2._y;
	cross._y = arg_vec1._z * arg_vec2._x - arg_vec1._x * arg_vec2._z;
	cross._z = arg_vec1._x * arg_vec2._y - arg_vec1._y * arg_vec2._x;
	cross._w = 0;
	return cross;
}

//�s�p
float Vector4::Angle(Vector4 arg_vec1, Vector4 arg_vec2) {
	//�@���x�N�g���̒�����0���Ɠ������o�܂���̂Œ��ӂ��Ă��������B

	//�x�N�g��A��B�̒������v�Z����
	float length_A = VectorLength(arg_vec1);
	float length_B = VectorLength(arg_vec2);

	//��O�����I�Ȃ�����킦����
	//if (length_A == 0 || length_B == 0)

	//���ςƃx�N�g���������g����cos�Ƃ����߂�
	float cos_sita = Vector4::Dot(arg_vec1, arg_vec2) / (length_A * length_B);

	//cos�Ƃ���Ƃ����߂�
	float sita = acos(Vector4::Dot(arg_vec1, arg_vec2) / (length_A * length_B));

	//�x���ɕϊ�
	sita = sita * 180.0 / M_PI;

	return sita;
}

//����
float Vector4::Distance(Vector4 arg_vec1, Vector4 arg_vec2) {
	return sqrt((arg_vec2._x - arg_vec1._x) * (arg_vec2._x - arg_vec1._x) + (arg_vec2._y - arg_vec1._y) * (arg_vec2._y - arg_vec1._y)
		+ (arg_vec2._z - arg_vec1._z) * (arg_vec2._z - arg_vec1._z) + (arg_vec2._w - arg_vec1._w) * (arg_vec2._w - arg_vec1._w));
}

//���ˊp
Vector4 Vector4::Reflect(Vector4 arg_vec1, Vector4 arg_vec2) {

	Vector4 reflect(0, 0, 0, 0);
	//�܂�vec2�̐��K�����s����
	arg_vec2.Normalize();
	//���ɓ��ς����߂��
	float dot = Vector4::Dot(arg_vec1, arg_vec2);
	//�����˂̃x�N�g�������߂��
	reflect._x = 2 * arg_vec2._x * dot - arg_vec1._x;
	reflect._y = 2 * arg_vec2._y * dot - arg_vec1._y;
	reflect._z = 2 * arg_vec2._z * dot - arg_vec1._z;
	reflect._w = 2 * arg_vec2._w * dot - arg_vec1._w;

	return reflect;
}

//�������Ă邩�ǂ���(�s����邩��)
bool Vector4::IsCross(Vector4 arg_vec1, Vector4 arg_vec2, Vector4 arg_vec3, Vector4 arg_vec4) {

	float ta, tb, tc, td;
	ta = (arg_vec3._x - arg_vec4._x) * (arg_vec1._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec1._x);
	tb = (arg_vec3._x - arg_vec4._x) * (arg_vec2._y - arg_vec3._y) + (arg_vec3._y - arg_vec4._y) * (arg_vec3._x - arg_vec2._x);
	tc = (arg_vec1._x - arg_vec2._x) * (arg_vec3._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec3._x);
	td = (arg_vec1._x - arg_vec2._x) * (arg_vec4._y - arg_vec1._y) + (arg_vec1._y - arg_vec2._y) * (arg_vec1._x - arg_vec4._x);
	//true�Ȃ�����Afalse�Ȃ�������ĂȂ�
	return tc * td < 0 && ta * tb < 0;
}

//����
float VectorLength(Vector4 *arg_vec) {
	return sqrt(arg_vec->_x * arg_vec->_x + arg_vec->_y * arg_vec->_y + arg_vec->_z * arg_vec->_z + arg_vec->_w * arg_vec->_w);
}
float VectorLength(Vector4 arg_vec) {
	return sqrt(arg_vec._x * arg_vec._x + arg_vec._y * arg_vec._y + arg_vec._z * arg_vec._z + arg_vec._w * arg_vec._w);
}

//�e�I�y���[�^
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