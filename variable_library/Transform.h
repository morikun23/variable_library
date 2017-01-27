#ifndef TRANSFORM
#define TRANSFORM

//////////////////////////////////////////////////////////////////
//�N���X���F Transform 
//�쐬�� �F��R�@�� 
//�T�v  �FUnity�Ŏg���Ă�position,rotation,scale���܂Ƃ߂����C�u����
//�X�V  �FH28/12/07/ �N���X�̍쐬 
//////////////////////////////////////////////////////////////////

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"
#include "Matrix.h"

namespace variableNS{

	class Transform {

	public:
		//�ʒu�̒l�A�傫���̒l���i�[����O����
		Vector3 _position;
		Vector3 _scale;

		//��]�̒l���i�[����l����(�N�H�[�^�j�I��)
		Quaternion _rotation;

		/////////////////////////////////////////
		//�R���X�g���N�^�A�f�X�g���N�^
		/////////////////////////////////////////
		Transform();
		Transform(Vector3 arg_pos,Vector3 arg_sca,Vector3 arg_rota);
		virtual ~Transform();


		//////////////////////////////////////////////
		//�C�ӎ��̂܂�����]����l������Ԃ�
		//vec : ��
		//x,y,z :��L�Ɠ��`
		//angle : ��]�p�x
		//////////////////////////////////////////////
		void RotateAxis(Vector3 arg_vec, float arg_angle);
		void RotateAxis(float arg_x, float arg_y, float arg_z, float arg_angle);


		/////////////////////////////////////////
		//���[���h�}�g���N�X(�ʒu�A�傫���A��]�̏�񂪊i�[���ꂽ�s��)�����
		/////////////////////////////////////////
		Matrix MakeWorldTransform();

	};

	
}

#endif