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
void Vector4::Set(float xx, float yy, float zz, float ww) {
	x = xx; y = yy; z = zz; w = ww;
}
void Vector4::Set(Vector4 vec) {
	x = vec.x; y = vec.y; z = vec.z; w = vec.w;
}

//���K��
void Vector4::Normalize() {
	float vectorlength = VectorLength(this);
	x = x / vectorlength;
	y = y / vectorlength;
	z = z / vectorlength;
	w = w / vectorlength;
}

//����
float Vector4::Dot(Vector4 vec1, Vector4 vec2) {
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
}

//�O��
Vector4 Vector4::Cross(Vector4 vec1, Vector4 vec2) {
	Vector4 cross;
	cross.x = vec1.y * vec2.z - vec1.z * vec2.y;
	cross.y = vec1.z * vec2.x - vec1.x * vec2.z;
	cross.z = vec1.x * vec2.y - vec1.y * vec2.x;
	cross.w = 0;
	return cross;
}

//�s�p
float Vector4::Angle(Vector4 vec1, Vector4 vec2) {
	//�@���x�N�g���̒�����0���Ɠ������o�܂���̂Œ��ӂ��Ă��������B

	//�x�N�g��A��B�̒������v�Z����
	float length_A = VectorLength(vec1);
	float length_B = VectorLength(vec2);

	//��O�����I�Ȃ�����킦����
	//if (length_A == 0 || length_B == 0)

	//���ςƃx�N�g���������g����cos�Ƃ����߂�
	float cos_sita = Vector4::Dot(vec1, vec2) / (length_A * length_B);

	//cos�Ƃ���Ƃ����߂�
	float sita = acos(Vector4::Dot(vec1, vec2) / (length_A * length_B));

	//�x���ɕϊ�
	sita = sita * 180.0 / M_PI;

	return sita;
}

//����
float Vector4::Distance(Vector4 vec1, Vector4 vec2) {
	return sqrt((vec2.x - vec1.x) * (vec2.x - vec1.x) + (vec2.y - vec1.y) * (vec2.y - vec1.y) + (vec2.z - vec1.z) * (vec2.z - vec1.z) + (vec2.w - vec1.w) * (vec2.w - vec1.w));
}

//���ˊp
Vector4 Vector4::Reflect(Vector4 vec1, Vector4 vec2) {

	Vector4 reflect(0, 0, 0, 0);
	//�܂�vec2�̐��K�����s����
	vec2.Normalize();
	//���ɓ��ς����߂��
	float dot = Vector4::Dot(vec1, vec2);
	//�����˂̃x�N�g�������߂��
	reflect.x = 2 * vec2.x * dot - vec1.x;
	reflect.y = 2 * vec2.y * dot - vec1.y;
	reflect.z = 2 * vec2.z * dot - vec1.z;
	reflect.w = 2 * vec2.w * dot - vec1.w;

	return reflect;
}

//�������Ă邩�ǂ���(�s����邩��)
bool Vector4::IsCross(Vector4 vec1, Vector4 vec2, Vector4 vec3, Vector4 vec4) {

	float ta, tb, tc, td;
	ta = (vec3.x - vec4.x) * (vec1.y - vec3.y) + (vec3.y - vec4.y) * (vec3.x - vec1.x);
	tb = (vec3.x - vec4.x) * (vec2.y - vec3.y) + (vec3.y - vec4.y) * (vec3.x - vec2.x);
	tc = (vec1.x - vec2.x) * (vec3.y - vec1.y) + (vec1.y - vec2.y) * (vec1.x - vec3.x);
	td = (vec1.x - vec2.x) * (vec4.y - vec1.y) + (vec1.y - vec2.y) * (vec1.x - vec4.x);
	//true�Ȃ�����Afalse�Ȃ�������ĂȂ�
	return tc * td < 0 && ta * tb < 0;
}

//����
float VectorLength(Vector4 *vec) {
	return sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z + vec->w * vec->w);
}
float VectorLength(Vector4 vec) {
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);
}

//�e�I�y���[�^
Vector4 Vector4::operator +(Vector4 vec) {
	this->x = this->x + vec.x;
	this->y = this->y + vec.y;
	this->z = this->z + vec.z;
	this->w = this->w + vec.w;
	return *this;
}

void Vector4::operator +=(Vector4 vec) {
	*this = *this + vec;
}

Vector4 Vector4::operator +(int num) {
	this->x = this->x + num;
	this->y = this->y + num;
	this->z = this->z + num;
	this->w = this->w + num;
	return *this;
}

void Vector4::operator +=(int num) {
	*this = *this + num;
}

Vector4 Vector4::operator +(float num) {
	this->x = this->x + num;
	this->y = this->y + num;
	this->z = this->z + num;
	this->w = this->w + num;
	return *this;
}

void Vector4::operator +=(float num) {
	*this = *this + num;
}

Vector4 Vector4::operator -(Vector4 vec) {
	this->x = this->x - vec.x;
	this->y = this->y - vec.y;
	this->z = this->z - vec.z;
	this->w = this->w - vec.w;
	return *this;
}

void Vector4::operator -=(Vector4 vec) {
	*this = *this - vec;
}

Vector4 Vector4::operator -(int num) {
	this->x = this->x - num;
	this->y = this->y - num;
	this->z = this->z - num;
	this->w = this->w - num;
	return *this;
}

void Vector4::operator -=(int num) {
	*this = *this - num;
}

Vector4 Vector4::operator -(float num) {
	this->x = this->x - num;
	this->y = this->y - num;
	this->z = this->z - num;
	this->w = this->w - num;
	return *this;
}

void Vector4::operator -=(float num) {
	*this = *this - num;
}

Vector4 Vector4::operator *(int num) {
	this->x = this->x * num;
	this->y = this->y * num;
	this->z = this->z * num;
	this->w = this->w * num;
	return *this;
}

void Vector4::operator *=(int num) {
	*this = *this * num;
}

Vector4 Vector4::operator *(float num) {
	this->x = this->x * num;
	this->y = this->y * num;
	this->z = this->z * num;
	this->w = this->w * num;
	return *this;
}

void Vector4::operator *=(float num) {
	*this = *this * num;
}

Vector4 Vector4::operator /(int num) {
	this->x = this->x / num;
	this->y = this->y / num;
	this->z = this->z / num;
	this->w = this->w / num;
	return *this;
}

void Vector4::operator /=(int num) {
	*this = *this / num;
}

Vector4 Vector4::operator /(float num) {
	this->x = this->x / num;
	this->y = this->y / num;
	this->z = this->z / num;
	this->w = this->w / num;
	return *this;
}

void Vector4::operator /=(float num) {
	*this = *this / num;
}

void Vector4::operator =(Vector4 vec) {
	this->Set(vec);
}

bool Vector4::operator !=(Vector4 vec) {
	bool vectorFlag;
	if (this->x != vec.x && this->y != vec.y && this->z != vec.z && this->w != vec.w) {
		vectorFlag = true;
	}
	else {
		vectorFlag = false;
	}
	return vectorFlag;
}

bool Vector4::operator ==(Vector4 vec) {
	bool vectorFlag;
	if (this->x == vec.x && this->y == vec.y && this->z == vec.z && this->w == vec.w) {
		vectorFlag = true;
	}
	else {
		vectorFlag = false;
	}
	return vectorFlag;
}