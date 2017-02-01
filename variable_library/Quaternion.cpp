#include"Quaternion.h"
#include<cmath>//後で野本のMathライブラリに変更
#define _USE_MATH_DEFINES
#include <math.h>//後で野本のMathライブラリに変更
using namespace variableNS;

Quaternion::Quaternion(){
	this->Identity();
}

Quaternion::Quaternion(int arg_x, int arg_y, int arg_z, int arg_w) {
	_x = arg_x;
	_y = arg_y;
	_z = arg_z;
	_w = arg_w;

	//const_cast<Vector3&>(this->_euler) = this->ToVector3();
}

Quaternion::Quaternion(float arg_x, float arg_y, float arg_z, float arg_w) {
	_x = arg_x;
	_y = arg_y;
	_z = arg_z;
	_w = arg_w;

	//const_cast<Vector3&>(this->_euler) = this->ToVector3();
}

Quaternion::Quaternion(Vector4 arg_vec) {
	_x = arg_vec._x;
	_y = arg_vec._y;
	_z = arg_vec._z;
	_w = arg_vec._w;

	//const_cast<Vector3&>(this->_euler) = this->ToVector3();
}

Quaternion::~Quaternion() {


}

//単位化
void Quaternion::Identity() {
	this->_x = this->_y = this->_z = 0;
	this->_w = 1;

	//const_cast<Vector3&>(this->_euler) = this->ToVector3();
}

//長さ
float Quaternion::Length() {
	return sqrt(this->_w * this->_w + this->_x * this->_x + this->_y * this->_y + this->_z * this->_z);
}

//値のセット
void Quaternion::Set(Quaternion arg_quat) {
	this->_x = arg_quat._x;
	this->_y = arg_quat._y;
	this->_z = arg_quat._z;
	this->_w = arg_quat._w;

	//const_cast<Vector3&>(this->_euler) = this->ToVector3();
}

//各オペレータ
void Quaternion::operator =(Quaternion arg_quat) {
	this->Set(arg_quat);
	//const_cast<Vector3&>(this->_euler) = this->ToVector3();
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
/*Vector3 Quaternion::ToVector3() {
	Vector3 out = Vector3::ZERO;

	float ysqr = this->_y * this->_y;
	float t0 = -2 * (ysqr + this->_z * this->_z) + 1;
	float t1 = 2 * (this->_x * this->_y - this->_w * this->_z);
	float t2 = -2 * (this->_x * this->_z + this->_w * this->_y);
	float t3 = 2 * (this->_y * this->_z - this->_w * this->_x);
	float t4 = -2 * (this->_x * this->_x + ysqr) + 1;

	t2 = t2 > 1.0f ? 1.0f : t2;
	t2 = t2 < -1.0f ? -1.0f : t2;

	out._x = atan2(t3, t4);
	out._y = asin(t2);
	out._z = atan2(t1, t0);

	return out;
}
*/

//オイラー角でセットできるよ
/*void Quaternion::operator =(Vector3) {

}*/

Quaternion Quaternion::operator *(Quaternion arg_quat) {
	Quaternion outQ(0,0,0,0);
	Vector3 newVector3(0, 0, 0);
	Vector3 thisVector3(this->_x, this->_y, this->_z);
	Vector3 inVector3(arg_quat._x, arg_quat._y, arg_quat._z);

	outQ._w = this->_w * arg_quat._w - (Vector3::Dot(thisVector3,inVector3));
	newVector3 = (thisVector3 + inVector3) + (Vector3::Cross(thisVector3, inVector3));
	outQ._x = newVector3._x;
	outQ._y = newVector3._y;
	outQ._z = newVector3._z;

	//const_cast<Vector3&>(this->_euler) = this->ToVector3();

	return outQ;
}

void Quaternion::operator *=(Quaternion arg_quat) {
	*this = *this * arg_quat;
}

Quaternion Quaternion::operator +(Quaternion arg_quat) {
	Quaternion outQ(0, 0, 0, 0);
	
	outQ._x = this->_x + arg_quat._x;
	outQ._y = this->_y + arg_quat._y;
	outQ._z = this->_z + arg_quat._z;
	outQ._w = this->_w + arg_quat._w;
	
	//const_cast<Vector3&>(this->_euler) = this->ToVector3();

	return outQ;
}

void Quaternion::operator +=(Quaternion arg_quat) {
	*this = *this + arg_quat;
}

Quaternion Quaternion::operator -(Quaternion arg_quat) {
	Quaternion outQ(0, 0, 0, 0);

	outQ._x = this->_x - arg_quat._x;
	outQ._y = this->_y - arg_quat._y;
	outQ._z = this->_z - arg_quat._z;
	outQ._w = this->_w - arg_quat._w;

	//const_cast<Vector3&>(this->_euler) = this->ToVector3();

	return outQ;
}

void Quaternion::operator -=(Quaternion arg_quat) {
	*this = *this - arg_quat;
}

bool Quaternion::operator ==(Quaternion arg_quat) {
	if (this->_x == arg_quat._x && this->_y == arg_quat._y && this->_z == arg_quat._z && this->_w == arg_quat._w)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Quaternion::operator !=(Quaternion arg_quat) {
	if (this->_x != arg_quat._x && this->_y != arg_quat._y && this->_z != arg_quat._z && this->_w != arg_quat._w)
	{
		return true;
	}
	else {
		return false;
	}
}