#include"Quaternion.h"
#include<cmath>//後で野本のMathライブラリに変更
#define _USE_MATH_DEFINES
#include <math.h>//後で野本のMathライブラリに変更
using namespace variableNS;

Quaternion::Quaternion(){
	this->Identity();
}

Quaternion::Quaternion(int xx, int yy, int zz, int ww) {
	x = xx;
	y = yy;
	z = zz;
	w = ww;
}

Quaternion::Quaternion(float xx, float yy, float zz, float ww) {
	x = xx;
	y = yy;
	z = zz;
	w = ww;
}

Quaternion::Quaternion(Vector4 vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;
}

Quaternion::~Quaternion() {


}

//単位化
void Quaternion::Identity() {
	this->x = this->y = this->z = 0;
	this->w = 1;
}

//絶対値
float Quaternion::Norm() {
	return sqrt(this->w * this->w + this->x * this->x + this->y * this->y + this->z * this->z);
}

//値のセット
void Quaternion::Set(Quaternion quaternion) {
	this->x = quaternion.x;
	this->y = quaternion.y;
	this->z = quaternion.z;
	this->w = quaternion.w;
}

//オイラー角で回転
void Quaternion::EulerAngles(Vector3 vec) {
	//this->x = 
}

//各オペレータ
void Quaternion::operator =(Quaternion q) {
	this->Set(q);
}

Quaternion Quaternion::operator *(Quaternion q) {
	Quaternion outQ(0,0,0,0);
	Vector3 newVector3(0, 0, 0);
	Vector3 thisVector3(this->x, this->y, this->z);
	Vector3 inVector3(q.x, q.y, q.z);

	outQ.w = this->w * q.w - (Vector3::Dot(thisVector3,inVector3));
	newVector3 = (thisVector3 + inVector3) + (Vector3::Cross(thisVector3, inVector3));
	outQ.x = newVector3.x;
	outQ.y = newVector3.y;
	outQ.z = newVector3.z;

	return outQ;
}

void Quaternion::operator *=(Quaternion q) {
	*this = *this * q;
}

Quaternion Quaternion::operator +(Quaternion q) {
	Quaternion outQ(0, 0, 0, 0);
	
	outQ.x = this->x + q.x;
	outQ.y = this->y + q.y;
	outQ.z = this->z + q.z;
	outQ.w = this->w + q.w;

	return outQ;
}

void Quaternion::operator +=(Quaternion q) {
	*this = *this + q;
}

Quaternion Quaternion::operator -(Quaternion q) {
	Quaternion outQ(0, 0, 0, 0);

	outQ.x = this->x - q.x;
	outQ.y = this->y - q.y;
	outQ.z = this->z - q.z;
	outQ.w = this->w - q.w;

	return outQ;
}

void Quaternion::operator -=(Quaternion q) {
	*this = *this - q;
}

bool Quaternion::operator ==(Quaternion q) {
	if (this->x == q.x && this->y == q.y && this->z == q.z && this->w == q.w)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Quaternion::operator !=(Quaternion q) {
	if (this->x != q.x && this->y != q.y && this->z != q.z && this->w != q.w)
	{
		return true;
	}
	else {
		return false;
	}
}