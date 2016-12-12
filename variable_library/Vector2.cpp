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
	x = y = 0;
}
Vector2::Vector2(float xx, float yy) {
	x = xx; y = yy;
}
//�f�X�g���N�^
Vector2::~Vector2() {

}

//�X�V(�Z�b�g)
void Vector2::Set(float xx,float yy) {
	x = xx; y = yy;
}

//���K��
void Vector2::Normalize() {
	float vectorlength = VectorLength(this);
	x = x / vectorlength;
	y = y / vectorlength;
}

//����
float Vector2::Dot(Vector2 vec1, Vector2 vec2) {
	return vec1.x * vec2.x + vec1.y * vec2.y;
}

//�O��(�񎟌��̂ݕԂ�l�̓x�N�g���ł͂Ȃ��X�J���[�l)
float Vector2::Cross(Vector2 vec1, Vector2 vec2) {
	return vec1.x * vec2.y - vec1.y * vec2.x;
}

//�s�p
float Vector2::Angle(Vector2 vec1, Vector2 vec2) {
	//�@���x�N�g���̒�����0���Ɠ������o�܂���̂Œ��ӂ��Ă��������B

	//�x�N�g��A��B�̒������v�Z����
	float length_A = VectorLength(vec1);
	float length_B = VectorLength(vec2);

	//��O�����I�Ȃ�����킦����
	//if (length_A == 0 || length_B == 0)

	//���ςƃx�N�g���������g����cos�Ƃ����߂�
	float cos_sita = Vector2::Dot(vec1, vec2) / (length_A * length_B);

	//cos�Ƃ���Ƃ����߂�
	float sita = acos(Vector2::Dot(vec1, vec2) / (length_A * length_B));

	//�x���ɕϊ�
	sita = sita * 180.0 / M_PI;

	return sita;
}

//����
float Vector2::Distance(Vector2 vec1, Vector2 vec2) {
	return sqrt((vec2.x - vec1.x) * (vec2.x - vec1.x) + (vec2.y - vec1.y) * (vec2.y - vec1.y));
}

//���ˊp
Vector2 Vector2::Reflect(Vector2 vec1, Vector2 vec2) {

	Vector2 reflect(0, 0);
	//�܂�vec2�̐��K�����s����
	vec2.Normalize();
	//���ɓ��ς����߂��
	float dot = Vector2::Dot(vec1, vec2);
	//�����˂̃x�N�g�������߂��
	reflect.x = 2 * vec2.x * dot - vec1.x;
	reflect.y = 2 * vec2.y * dot - vec1.y;

	return reflect;
}

//�������Ă邩�ǂ���
bool Vector2::IsCross(Vector2 vec1, Vector2 vec2, Vector2 vec3, Vector2 vec4) {
	
	float ta, tb, tc, td;
	ta = (vec3.x - vec4.x) * (vec1.y - vec3.y) + (vec3.y - vec4.y) * (vec3.x - vec1.x);
	tb = (vec3.x - vec4.x) * (vec2.y - vec3.y) + (vec3.y - vec4.y) * (vec3.x - vec2.x);
	tc = (vec1.x - vec2.x) * (vec3.y - vec1.y) + (vec1.y - vec2.y) * (vec1.x - vec3.x);
	td = (vec1.x - vec2.x) * (vec4.y - vec1.y) + (vec1.y - vec2.y) * (vec1.x - vec4.x);
	//true�Ȃ�����Afalse�Ȃ�������ĂȂ�
	return tc * td < 0 && ta * tb < 0;
}

//����
float VectorLength(Vector2 *vec) {
	return sqrt(vec->x * vec->x + vec->y * vec->y);
}
float VectorLength(Vector2 vec) {
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}