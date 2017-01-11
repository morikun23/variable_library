/*
#ifndef ROTATIONMATRIX
#define ROTATIONMATRIX

//////////////////////////////////////////////////////////////////
//�N���X���F RotationMatrix 
//�쐬�� �F��R�@�� 
//�T�v  �F��]�s��������N���X
//�X�V  �FH28/12/19/ �N���X�̍쐬 
//////////////////////////////////////////////////////////////////

#include"MatrixBase.h"

namespace variableNS {

	class RotationMatrix : public MatrixBase{
	
	public:
		//�ǂݎ���p��x,y,z����
		float x, y, z;

		//�R���X�g���N�^�A�f�X�g���N�^
		RotationMatrix();
		virtual ~RotationMatrix();


		///////////////////////
		//�I�C���[�p�ŉ񂵂܂�(�I�y���[�^�[���邩�炢��˂�����)
		//vec : x,y,z�v�f
		///////////////////////
		void Rotate(Vector3 vec);


		///////////////////////////
		//�ڕW���ɑ΂��ă��b�N�I��(���������킹��)
		//position : �����̈ʒu
		//target : �ڕW��
		//up : �J�����̏����(��ʓI�ɂ�(0,1,0))
		///////////////////////////
		void LookAt(Vector3 position, Vector3 target, Vector3 up);


		//�e�I�y���[�^
		RotationMatrix operator+(Vector3);
		RotationMatrix operator-(Vector3);
		RotationMatrix operator=(Vector3);
		void operator+=(Vector3);
		void operator-=(Vector3);
	};

}

#endif
*/