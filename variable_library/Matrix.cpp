#include"Matrix.h"
#include<stddef.h>
#include<string>
using namespace variableNS;

//コンストラクタ、デストラクタ
Matrix::Matrix() {
	memset(&_matrix, NULL, sizeof(_matrix));
}

Matrix::~Matrix() {
	memset(&_matrix, NULL, sizeof(_matrix));
}

//単位化
void Matrix::Identity() {
	memset(&_matrix, NULL, sizeof(_matrix));
	m00 = m11 = m22 = m33 = 1;
}

//位置変換
void Matrix::ToPositionMatrix(Vector3 arg_vec) {
	this->Identity();
	m30 = arg_vec._x;
	m31 = arg_vec._y;
	m32 = arg_vec._z;
}

//縮小拡大変換
void Matrix::ToScaleMatrix(Vector3 arg_vec) {
	this->Identity();
	m00 = arg_vec._x;
	m11 = arg_vec._y;
	m22 = arg_vec._z;
}

//回転変換
void Matrix::ToRotateMatrix(Quaternion arg_quat) {
	this->Identity();
	
	m00 = 1 - (2 * (arg_quat._y * arg_quat._y)) - (2 * (arg_quat._z * arg_quat._z));
	m01 = (2 * arg_quat._x * arg_quat._y) + (2 * arg_quat._w * arg_quat._z);
	m02 = (2 * arg_quat._x * arg_quat._z) - (2 * arg_quat._w * arg_quat._y);

	m10 = (2 * arg_quat._x * arg_quat._y) - (2 * arg_quat._w * arg_quat._z);
	m11 = 1 - (2 * (arg_quat._x * arg_quat._x)) - (2 * (arg_quat._z * arg_quat._z));
    m12 = (2 * arg_quat._y * arg_quat._z) + (2 * arg_quat._w * arg_quat._x);

	m20 = (2 * arg_quat._x * arg_quat._z) + (2 * arg_quat._w * arg_quat._y);
	m21 = (2 * arg_quat._y * arg_quat._z) - (2 * arg_quat._w * arg_quat._x);
	m22 = 1 - (2 * (arg_quat._x * arg_quat._x)) - (2 * (arg_quat._y * arg_quat._y));

}

//オぺレータ
Matrix Matrix::operator+(Matrix arg_mat) {
	this->m00 = this->m00 + arg_mat.m00; this->m01 = this->m01 + arg_mat.m01; this->m02 = this->m02 + arg_mat.m02; this->m03 = this->m03 + arg_mat.m03;
	this->m10 = this->m10 + arg_mat.m10; this->m11 = this->m11 + arg_mat.m11; this->m12 = this->m12 + arg_mat.m12; this->m13 = this->m13 + arg_mat.m13;
	this->m20 = this->m20 + arg_mat.m20; this->m21 = this->m21 + arg_mat.m21; this->m22 = this->m22 + arg_mat.m22; this->m23 = this->m23 + arg_mat.m23;
	this->m30 = this->m30 + arg_mat.m30; this->m31 = this->m31 + arg_mat.m31; this->m32 = this->m32 + arg_mat.m32; this->m33 = this->m33 + arg_mat.m33;

	return *this;
}

Matrix Matrix::operator-(Matrix arg_mat) {
	this->m00 = this->m00 - arg_mat.m00; this->m01 = this->m01 - arg_mat.m01; this->m02 = this->m02 - arg_mat.m02; this->m03 = this->m03 - arg_mat.m03;
	this->m10 = this->m10 - arg_mat.m10; this->m11 = this->m11 - arg_mat.m11; this->m12 = this->m12 - arg_mat.m12; this->m13 = this->m13 - arg_mat.m13;
	this->m20 = this->m20 - arg_mat.m20; this->m21 = this->m21 - arg_mat.m21; this->m22 = this->m22 - arg_mat.m22; this->m23 = this->m23 - arg_mat.m23;
	this->m30 = this->m30 - arg_mat.m30; this->m31 = this->m31 - arg_mat.m31; this->m32 = this->m32 - arg_mat.m32; this->m33 = this->m33 - arg_mat.m33;

	return *this;
}

Matrix Matrix::operator*(Matrix arg_mat) {
	this->m00 = this->m00 * arg_mat.m00 + this->m01 * arg_mat.m10 + this->m02 * arg_mat.m20 + this->m03 * arg_mat.m30;
	this->m01 = this->m00 * arg_mat.m01 + this->m01 * arg_mat.m11 + this->m02 * arg_mat.m21 + this->m03 * arg_mat.m31;
	this->m02 = this->m00 * arg_mat.m02 + this->m01 * arg_mat.m12 + this->m02 * arg_mat.m22 + this->m03 * arg_mat.m32;
	this->m03 = this->m00 * arg_mat.m03 + this->m01 * arg_mat.m13 + this->m02 * arg_mat.m23 + this->m03 * arg_mat.m33;

	this->m10 = this->m10 * arg_mat.m00 + this->m11 * arg_mat.m10 + this->m12 * arg_mat.m20 + this->m13 * arg_mat.m30;
	this->m11 = this->m10 * arg_mat.m01 + this->m11 * arg_mat.m11 + this->m12 * arg_mat.m21 + this->m13 * arg_mat.m31;
	this->m12 = this->m10 * arg_mat.m02 + this->m11 * arg_mat.m12 + this->m12 * arg_mat.m22 + this->m13 * arg_mat.m32;
	this->m13 = this->m10 * arg_mat.m03 + this->m11 * arg_mat.m13 + this->m12 * arg_mat.m23 + this->m13 * arg_mat.m33;

	this->m20 = this->m20 * arg_mat.m00 + this->m21 * arg_mat.m10 + this->m22 * arg_mat.m20 + this->m23 * arg_mat.m30;
	this->m21 = this->m20 * arg_mat.m01 + this->m21 * arg_mat.m11 + this->m22 * arg_mat.m21 + this->m23 * arg_mat.m31;
	this->m22 = this->m20 * arg_mat.m02 + this->m21 * arg_mat.m12 + this->m22 * arg_mat.m22 + this->m23 * arg_mat.m32;
	this->m23 = this->m20 * arg_mat.m03 + this->m21 * arg_mat.m13 + this->m22 * arg_mat.m23 + this->m23 * arg_mat.m33;

	this->m30 = this->m30 * arg_mat.m00 + this->m31 * arg_mat.m10 + this->m32 * arg_mat.m20 + this->m33 * arg_mat.m30;
	this->m31 = this->m30 * arg_mat.m01 + this->m31 * arg_mat.m11 + this->m32 * arg_mat.m21 + this->m33 * arg_mat.m31;
	this->m32 = this->m30 * arg_mat.m02 + this->m31 * arg_mat.m12 + this->m32 * arg_mat.m22 + this->m33 * arg_mat.m32;
	this->m33 = this->m30 * arg_mat.m03 + this->m31 * arg_mat.m13 + this->m32 * arg_mat.m23 + this->m33 * arg_mat.m33;

	return *this;
}

void Matrix::operator+=(Matrix arg_mat) {
	*this = *this + arg_mat;
}
void Matrix::operator-=(Matrix arg_mat) {
	*this = *this - arg_mat;
}
void Matrix::operator*=(Matrix arg_mat) {
	*this = *this * arg_mat;
}
