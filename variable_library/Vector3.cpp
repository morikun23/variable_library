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
	x = y = z = 0;
}
Vector3::Vector3(int xx, int yy,int zz) {
	x = xx; y = yy; z = zz;
}
Vector3::Vector3(float xx, float yy, float zz) {
	x = xx; y = yy; z = zz;
}
//�f�X�g���N�^
Vector3::~Vector3() {

}

//�X�V(�Z�b�g)
void Vector3::Set(float xx, float yy, float zz) {
	x = xx; y = yy; z = zz;
}
void Vector3::Set(Vector3 vec) {
	x = vec.x; y = vec.y; z = vec.z;
}

//���K��
void Vector3::Normalize() {
	float vectorlength = VectorLength(this);
	x = x / vectorlength;
	y = y / vectorlength;
	z = z / vectorlength;
}

//����
float Vector3::Dot(Vector3 vec1, Vector3 vec2) {
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

//�O��
Vector3 Vector3::Cross(Vector3 vec1, Vector3 vec2) {
	Vector3 cross;
	cross.x = vec1.y * vec2.z - vec1.z * vec2.y;
	cross.y = vec1.z * vec2.x - vec1.x * vec2.z;
	cross.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return cross;
}

//�s�p
float Vector3::Angle(Vector3 vec1, Vector3 vec2) {
	//�@���x�N�g���̒�����0���Ɠ������o�܂���̂Œ��ӂ��Ă��������B

	//�x�N�g��A��B�̒������v�Z����
	float length_A = VectorLength(vec1);
	float length_B = VectorLength(vec2);

	//��O�����I�Ȃ�����킦����
	//if (length_A == 0 || length_B == 0)

	//���ςƃx�N�g���������g����cos�Ƃ����߂�
	float cos_sita = Vector3::Dot(vec1, vec2) / (length_A * length_B);

	//cos�Ƃ���Ƃ����߂�
	float sita = acos(Vector3::Dot(vec1, vec2) / (length_A * length_B));

	//�x���ɕϊ�
	sita = sita * 180.0 / M_PI;

	return sita;
}

//����
float Vector3::Distance(Vector3 vec1, Vector3 vec2) {
	return sqrt((vec2.x - vec1.x) * (vec2.x - vec1.x) + (vec2.y - vec1.y) * (vec2.y - vec1.y) + (vec2.z - vec1.z) * (vec2.z - vec1.z));
}

//���ˊp
Vector3 Vector3::Reflect(Vector3 vec1, Vector3 vec2) {

	Vector3 reflect(0, 0, 0);
	//�܂�vec2�̐��K�����s����
	vec2.Normalize();
	//���ɓ��ς����߂��
	float dot = Vector3::Dot(vec1, vec2);
	//�����˂̃x�N�g�������߂��
	reflect.x = 2 * vec2.x * dot - vec1.x;
	reflect.y = 2 * vec2.y * dot - vec1.y;
	reflect.z = 2 * vec2.z * dot - vec1.z;

	return reflect;
}

//�������Ă邩�ǂ���(�s����邩��)
bool Vector3::IsCross(Vector3 vec1, Vector3 vec2, Vector3 vec3, Vector3 vec4) {

	float ta, tb, tc, td;
	ta = (vec3.x - vec4.x) * (vec1.y - vec3.y) + (vec3.y - vec4.y) * (vec3.x - vec1.x);
	tb = (vec3.x - vec4.x) * (vec2.y - vec3.y) + (vec3.y - vec4.y) * (vec3.x - vec2.x);
	tc = (vec1.x - vec2.x) * (vec3.y - vec1.y) + (vec1.y - vec2.y) * (vec1.x - vec3.x);
	td = (vec1.x - vec2.x) * (vec4.y - vec1.y) + (vec1.y - vec2.y) * (vec1.x - vec4.x);
	//true�Ȃ�����Afalse�Ȃ�������ĂȂ�
	return tc * td < 0 && ta * tb < 0;
}

//����
float VectorLength(Vector3 *vec) {
	return sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}
float VectorLength(Vector3 vec) {
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

//�e�I�y���[�^
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