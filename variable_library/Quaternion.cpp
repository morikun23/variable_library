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

	const_cast<Vector3&>(this->euler) = this->ToVector3();
}

Quaternion::Quaternion(float xx, float yy, float zz, float ww) {
	x = xx;
	y = yy;
	z = zz;
	w = ww;

	const_cast<Vector3&>(this->euler) = this->ToVector3();
}

Quaternion::Quaternion(Vector4 vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;

	const_cast<Vector3&>(this->euler) = this->ToVector3();
}

Quaternion::~Quaternion() {


}

//単位化
void Quaternion::Identity() {
	this->x = this->y = this->z = 0;
	this->w = 1;

	const_cast<Vector3&>(this->euler) = this->ToVector3();
}

//長さ
float Quaternion::Length() {
	return sqrt(this->w * this->w + this->x * this->x + this->y * this->y + this->z * this->z);
}

//値のセット
void Quaternion::Set(Quaternion quaternion) {
	this->x = quaternion.x;
	this->y = quaternion.y;
	this->z = quaternion.z;
	this->w = quaternion.w;

	const_cast<Vector3&>(this->euler) = this->ToVector3();
}

//各オペレータ
void Quaternion::operator =(Quaternion q) {
	this->Set(q);
	const_cast<Vector3&>(this->euler) = this->ToVector3();
}

//任意軸回転四元数
//Quaternion Quaternion::RotateAxis(Vector3 vec, float angle) {
//	Quaternion out;
//	vec.Normalize();
//
//	out = RotateAxis(vec.x,vec.y,vec.z, angle);
//
//	return out;
//}
//Quaternion Quaternion::RotateAxis(float x, float y, float z, float angle) {
//
//	Quaternion out;
//	Quaternion R, P, Q;
//
//	//Pには座標を入れる(Position)
//	//不具合が起きるとしたらここ
//	P.x = this->x;
//	P.y = this->y;
//	P.z = this->z;
//	P.w = 0;
//
//	Q.x = x * sin(angle / 2);
//	Q.y = y * sin(angle / 2);
//	Q.z = z * sin(angle / 2);
//	Q.w = cos(angle / 2);
//
//	R.x = -x * sin(angle / 2);
//	R.y = -y * sin(angle / 2);
//	R.z = -z * sin(angle / 2);
//	R.w = cos(angle / 2);
//
//	out = R*P*Q;
//
//	return out;
//}


//４→３
Vector3 Quaternion::ToVector3() {
	Vector3 out = Vector3::ZERO;

	float ysqr = this->y * this->y;
	float t0 = -2 * (ysqr + this->z * this->z) + 1;
	float t1 = 2 * (this->x * this->y - this->w * this->z);
	float t2 = -2 * (this->x * this->z + this->w * this->y);
	float t3 = 2 * (this->y * this->z - this->w * this->x);
	float t4 = -2 * (this->x * this->x + ysqr) + 1;

	t2 = t2 > 1.0f ? 1.0f : t2;
	t2 = t2 < -1.0f ? -1.0f : t2;

	out.x = atan2(t3, t4);
	out.y = asin(t2);
	out.z = atan2(t1, t0);

	return out;
}


//オイラー角でセットできるよ
/*void Quaternion::operator =(Vector3) {

}*/

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

	const_cast<Vector3&>(this->euler) = this->ToVector3();

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

	const_cast<Vector3&>(this->euler) = this->ToVector3();

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

	const_cast<Vector3&>(this->euler) = this->ToVector3();

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