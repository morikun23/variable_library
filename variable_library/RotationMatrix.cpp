/*

#include"RotationMatrix.h"
#include<cmath>//後で野本のMathライブラリに変更
#define _USE_MATH_DEFINES
#include <math.h>//後で野本のMathライブラリに変更
using namespace variableNS;

//コンストラクタ、デストラクタ
RotationMatrix::RotationMatrix() {
	this->Identity();
	x = y = z = 0;
}

RotationMatrix::~RotationMatrix() {
}

//オイラー角で回転
void RotationMatrix::Rotate(Vector3 vec) {

	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;

	this->m00 = cosf(vec.x)*cosf(vec.y)*cosf(vec.z) - sinf(vec.x)*sinf(vec.z);
	this->m01 = -(cosf(vec.x))*cosf(vec.y)*sinf(vec.z) - sinf(vec.x)*cosf(vec.z);
	this->m02 = cosf(vec.x)*sinf(vec.y);

	this->m10 = sinf(vec.x)*cosf(vec.y)*cosf(vec.z) + cosf(vec.x)*sinf(vec.z);
	this->m11 = -(sinf(vec.x)*cosf(vec.y)*sinf(vec.z) + cosf(vec.x)*cosf(vec.z));
	this->m12 = sinf(vec.x)*sinf(vec.y);

	this->m20 = -(sinf(vec.y)*cosf(vec.z));
	this->m21 = sinf(vec.y)*sinf(vec.z);
	this->m22 = cosf(vec.y);
}

//ロックオン
void RotationMatrix::LookAt(Vector3 position, Vector3 target, Vector3 up) {
	Vector3 zaxis = target - position;
	zaxis.Normalize();
	Vector3 xaxis = Vector3::Cross(up,zaxis);
	xaxis.Normalize();
	Vector3 yaxis = Vector3::Cross(zaxis,xaxis);

	this->m00 = xaxis.x;
	this->m01 = yaxis.x;
	this->m02 = zaxis.x;
	this->m03 = 0;

	this->m10 = xaxis.y;
	this->m11 = yaxis.y;
	this->m12 = zaxis.y;
	this->m13 = 0;

	this->m20 = xaxis.z;
	this->m21 = yaxis.z;
	this->m22 = zaxis.z;
	this->m23 = 0;

	this->m30 = Vector3::Dot(xaxis * -1,position);
	this->m31 = Vector3::Dot(yaxis * -1, position);
	this->m32 = Vector3::Dot(zaxis * -1, position);
	this->m33 = 0;

}

//各オペレータ
RotationMatrix RotationMatrix::operator+(Vector3 vec) {
	this->x = this->x + vec.x;
	this->y = this->y + vec.y;
	this->z = this->z + vec.z;

	Rotate(Vector3(this->x, this->y, this->z));

	return *this;
}

RotationMatrix RotationMatrix::operator-(Vector3 vec) {
	this->x = this->x - vec.x;
	this->y = this->y - vec.y;
	this->z = this->z - vec.z;

	Rotate(Vector3(this->x, this->y, this->z));

	return *this;
}

RotationMatrix RotationMatrix::operator=(Vector3 vec) {
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;

	Rotate(Vector3(this->x,this->y,this->z));

	return *this;
}

void RotationMatrix::operator+=(Vector3 vec) {
	*this = *this + vec;
}

void RotationMatrix::operator-=(Vector3 vec) {
	*this = *this - vec;
}

*/