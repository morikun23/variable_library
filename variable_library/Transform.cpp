#include"Transform.h"
#include<cmath>//��Ŗ�{��Math���C�u�����ɕύX
#define _USE_MATH_DEFINES
#include <math.h>//��Ŗ�{��Math���C�u�����ɕύX
using namespace variableNS;

/////////////////////////�ȉ����[�e�[�V�����֌W//////////////////////////////////////////

//�R���X�g���N�^�A�f�X�g���N�^
Transform::Transform() {
	position = Vector3::ZERO;
	scale = Vector3::ONE;
	rotation.Identity();
}

Transform::Transform(Vector3 pos, Vector3 sca, Vector3 rota) {
	position = pos;
	scale = sca;
	rotation = rota.ToQuaternion();
}

Transform::~Transform() {

}

//���[���h�}�g���N�X�����
Matrix Transform::MakeWorldTransform() {
	
	Matrix out,posMat,scaMat,rotaMat;
	out.Identity();
	
	posMat.ToPositionMatrix(position);
	scaMat.ToScaleMatrix(scale);
	rotaMat.ToRotateMatrix(rotation);

	out = out * scaMat;
	out = out * posMat;
	out = out * rotaMat;

	return out;
}

/*
//�p�x�̉��Z
void Transform::Rotate(Vector3 vec3) {

	rotationMatrix.m00 += (cos(vec3.x) * cos(vec3.y) * cos(vec3.z)) - (sin(vec3.x) * sin(vec3.z));
	rotationMatrix.m01 += ((cos(vec3.x) * cos(vec3.y) * sin(vec3.z)) * -1) - (sin(vec3.x) * cos(vec3.z));
	rotationMatrix.m02 += cos(vec3.x) * sin(vec3.y);

	rotationMatrix.m10 += (sin(vec3.x) * cos(vec3.y) * cos(vec3.z)) + (cos(vec3.x) * sin(vec3.z));
	rotationMatrix.m11 += ((sin(vec3.x) * cos(vec3.y) * sin(vec3.z)) * -1) + (cos(vec3.x) * cos(vec3.z));
	rotationMatrix.m12 += sin(vec3.x) * sin(vec3.y);

	rotationMatrix.m20 += (sin(vec3.y) * cos(vec3.z) * -1);
	rotationMatrix.m21 += sin(vec3.y) * sin(vec3.z);
	rotationMatrix.m22 += cos(vec3.y);


	
	//x��
	if (vec3.x != 0) {
	rotaMatX.m11 += cosf(vec3.x);
	rotaMatX.m12 += -sinf(vec3.x);
	rotaMatX.m21 += sinf(vec3.x);
	rotaMatX.m22 += cosf(vec3.x);
	}

	//y��
	if (vec3.y != 0) {
	rotaMatY.m00 += cosf(vec3.y);
	rotaMatY.m02 += sinf(vec3.y);
	rotaMatY.m20 += -sinf(vec3.y);
	rotaMatY.m22 += cosf(vec3.y);
	}

	//z��
	if (vec3.z != 0) {
	rotaMatZ.m00 += cosf(vec3.z);
	rotaMatZ.m01 += -sinf(vec3.z);
	rotaMatZ.m10 += sinf(vec3.z);
	rotaMatZ.m11 += cosf(vec3.z);
	}
}
*/
/*
//�S�����Ŋp�x���Z�b�g
void Transform::Set(Vector4 vec4) {

	rotationMatrix.m00 = (vec4.x * vec4.x) + (vec4.y * vec4.y) - (vec4.z * vec4.z) - (vec4.w * vec4.w);
	rotationMatrix.m01 = (vec4.y * vec4.z - vec4.x * vec4.w) * (vec4.y * vec4.z - vec4.x * vec4.w);
	rotationMatrix.m02 = (vec4.y * vec4.w + vec4.x * vec4.z) * (vec4.y * vec4.w + vec4.x * vec4.z);

	rotationMatrix.m10 = (vec4.y * vec4.z + vec4.x * vec4.w) * (vec4.y * vec4.z + vec4.x * vec4.w);
	rotationMatrix.m11 = (vec4.x * vec4.x) - (vec4.y * vec4.y) + (vec4.z * vec4.z) - (vec4.w * vec4.w);
	rotationMatrix.m12 = (vec4.z * vec4.w - vec4.x * vec4.y) * (vec4.z * vec4.w - vec4.x * vec4.y);

	rotationMatrix.m20 = (vec4.y * vec4.w - vec4.x * vec4.z) * (vec4.y * vec4.w - vec4.x * vec4.z);
	rotationMatrix.m21 = (vec4.z * vec4.w + vec4.x * vec4.y) * (vec4.z * vec4.w + vec4.x * vec4.y);
	rotationMatrix.m22 = (vec4.x * vec4.x) - (vec4.y * vec4.y) - (vec4.z * vec4.z) + (vec4.w * vec4.w);

}*/


/////////�|�W�V�������o�����撅��
//�����_�Ɍ����Č������ނ���
/*void Transform::Lookat(Vector3 at) {
Vector3 myRota(rotationMatrix.m00);

Vector3 zaxis = Vector3::Normalize(at - this.)

}*/
/*
//�I�C���[�p�ŃZ�b�g
void Transform::Euler(Vector3 vec3) {
	rotationMatrix.m00 = (cos(vec3.x) * cos(vec3.y) * cos(vec3.z)) - (sin(vec3.x) * sin(vec3.z));
	rotationMatrix.m01 = ((cos(vec3.x) * cos(vec3.y) * sin(vec3.z)) * -1) - (sin(vec3.x) * cos(vec3.z));
	rotationMatrix.m02 = cos(vec3.x) * sin(vec3.y);

	rotationMatrix.m10 = (sin(vec3.x) * cos(vec3.y) * cos(vec3.z)) + (cos(vec3.x) * sin(vec3.z));
	rotationMatrix.m11 = ((sin(vec3.x) * cos(vec3.y) * sin(vec3.z)) * -1) + (cos(vec3.x) * cos(vec3.z));
	rotationMatrix.m12 = sin(vec3.x) * sin(vec3.y);

	rotationMatrix.m20 = (sin(vec3.y) * cos(vec3.z) * -1);
	rotationMatrix.m21 = sin(vec3.y) * sin(vec3.z);
	rotationMatrix.m22 = cos(vec3.y);
}
*/
////////////////////////////////////////////////////////////////////////////////////////

