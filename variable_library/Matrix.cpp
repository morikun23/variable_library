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
void Matrix::VectorToPositionMatrix(Vector3 vec) {
	this->Identity();
	m30 = vec.x;
	m31 = vec.y;
	m32 = vec.z;
}

//縮小拡大変換
void Matrix::VectorToScaleMatrix(Vector3 vec) {
	this->Identity();
	m00 = vec.x;
	m11 = vec.y;
	m22 = vec.z;
}

//オぺレータ
Matrix Matrix::operator+(Matrix mat) {
	this->m00 = this->m00 + mat.m00; this->m01 = this->m01 + mat.m01; this->m02 = this->m02 + mat.m02; this->m03 = this->m03 + mat.m03;
	this->m10 = this->m10 + mat.m10; this->m11 = this->m11 + mat.m11; this->m12 = this->m12 + mat.m12; this->m13 = this->m13 + mat.m13;
	this->m20 = this->m20 + mat.m20; this->m21 = this->m21 + mat.m21; this->m22 = this->m22 + mat.m22; this->m23 = this->m23 + mat.m23;
	this->m30 = this->m30 + mat.m30; this->m31 = this->m31 + mat.m31; this->m32 = this->m32 + mat.m32; this->m33 = this->m33 + mat.m33;

	return *this;
}

Matrix Matrix::operator-(Matrix mat) {
	this->m00 = this->m00 - mat.m00; this->m01 = this->m01 - mat.m01; this->m02 = this->m02 - mat.m02; this->m03 = this->m03 - mat.m03;
	this->m10 = this->m10 - mat.m10; this->m11 = this->m11 - mat.m11; this->m12 = this->m12 - mat.m12; this->m13 = this->m13 - mat.m13;
	this->m20 = this->m20 - mat.m20; this->m21 = this->m21 - mat.m21; this->m22 = this->m22 - mat.m22; this->m23 = this->m23 - mat.m23;
	this->m30 = this->m30 - mat.m30; this->m31 = this->m31 - mat.m31; this->m32 = this->m32 - mat.m32; this->m33 = this->m33 - mat.m33;

	return *this;
}

Matrix Matrix::operator*(Matrix mat) {
	this->m00 = this->m00 * mat.m00 + this->m01 * mat.m10 + this->m02 * mat.m20 + this->m03 * mat.m30;
	this->m01 = this->m00 * mat.m01 + this->m01 * mat.m11 + this->m02 * mat.m21 + this->m03 * mat.m31;
	this->m02 = this->m00 * mat.m02 + this->m01 * mat.m12 + this->m02 * mat.m22 + this->m03 * mat.m32;
	this->m03 = this->m00 * mat.m03 + this->m01 * mat.m13 + this->m02 * mat.m23 + this->m03 * mat.m33;

	this->m10 = this->m10 * mat.m00 + this->m11 * mat.m10 + this->m12 * mat.m20 + this->m13 * mat.m30;
	this->m11 = this->m10 * mat.m01 + this->m11 * mat.m11 + this->m12 * mat.m21 + this->m13 * mat.m31;
	this->m12 = this->m10 * mat.m02 + this->m11 * mat.m12 + this->m12 * mat.m22 + this->m13 * mat.m32;
	this->m13 = this->m10 * mat.m03 + this->m11 * mat.m13 + this->m12 * mat.m23 + this->m13 * mat.m33;

	this->m20 = this->m20 * mat.m00 + this->m21 * mat.m10 + this->m22 * mat.m20 + this->m23 * mat.m30;
	this->m21 = this->m20 * mat.m01 + this->m21 * mat.m11 + this->m22 * mat.m21 + this->m23 * mat.m31;
	this->m22 = this->m20 * mat.m02 + this->m21 * mat.m12 + this->m22 * mat.m22 + this->m23 * mat.m32;
	this->m23 = this->m20 * mat.m03 + this->m21 * mat.m13 + this->m22 * mat.m23 + this->m23 * mat.m33;

	this->m30 = this->m30 * mat.m00 + this->m31 * mat.m10 + this->m32 * mat.m20 + this->m33 * mat.m30;
	this->m31 = this->m30 * mat.m01 + this->m31 * mat.m11 + this->m32 * mat.m21 + this->m33 * mat.m31;
	this->m32 = this->m30 * mat.m02 + this->m31 * mat.m12 + this->m32 * mat.m22 + this->m33 * mat.m32;
	this->m33 = this->m30 * mat.m03 + this->m31 * mat.m13 + this->m32 * mat.m23 + this->m33 * mat.m33;

	return *this;
}

void Matrix::operator+=(Matrix mat) {
	*this = *this + mat;
}
void Matrix::operator-=(Matrix mat) {
	*this = *this - mat;
}
void Matrix::operator*=(Matrix mat) {
	*this = *this * mat;
}
