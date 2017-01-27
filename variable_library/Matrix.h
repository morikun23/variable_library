#ifndef MATRIX
#define MATRIX

//////////////////////////////////////////////////////////////////
//�N���X���F Matrix
//�쐬�� �F��R�@�� 
//�T�v  �F4x4�̍s��̐����A�v�Z���s���N���X
//�X�V  �FH28/12/18/ �N���X�̍쐬
//      :H29/01/04/ �ϊ��֐��̍쐬
//////////////////////////////////////////////////////////////////

#include"Vector3.h"
#include"Vector4.h"
#include"Quaternion.h"

namespace variableNS {

	class Matrix {

	public:
		union{
			struct{
				float m00, m01, m02, m03;
				float m10, m11, m12, m13;
				float m20, m21, m22, m23;
				float m30, m31, m32, m33;
			};
			float _matrix[4][4];
		};

		//�R���X�g���N�^�A�f�X�g���N�^
		Matrix();
		virtual ~Matrix();

		///////////////////////////////////////
		//�}�g���N�X�̒P�ʉ��@�قƂ�ǂ̍s��v�Z�̑O�ɕK�v�ȏ���
		///////////////////////////////////////
		void Identity();

		///////////////////////////////////////
		//�}�g���N�X���ʒu�s��ɕς���
		//vec : �ʒu��\���O����
		///////////////////////////////////////
		void ToPositionMatrix(Vector3 arg_vec);

		///////////////////////////////////////
		//�}�g���N�X���k���g��s��ɕς���
		//vec : �傫����\���O����
		///////////////////////////////////////
		void ToScaleMatrix(Vector3 arg_vec);

		///////////////////////////////////////
		//�}�g���N�X����]�s��ɕς���
		//quat : �傫����\���l����
		///////////////////////////////////////
		void ToRotateMatrix(Quaternion arg_quat);

		//�e�I�y���[�^
		Matrix operator +(Matrix);
		Matrix operator -(Matrix);
		Matrix operator *(Matrix);
		void operator +=(Matrix);
		void operator -=(Matrix);
		void operator *=(Matrix);
	};

}

#endif