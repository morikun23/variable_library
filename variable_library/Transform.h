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
		Vector3 position;
		Vector3 scale;

		//��]�̒l���i�[����l����(�N�H�[�^�j�I��)
		Quaternion rotation;

		/////////////////////////////////////////
		//�R���X�g���N�^�A�f�X�g���N�^
		/////////////////////////////////////////
		Transform();
		Transform(Vector3 pos,Vector3 sca,Vector3 rota);
		virtual ~Transform();


		/////////////////////////////////////////
		//���[���h�}�g���N�X(�ʒu�A�傫���A��]�̏�񂪊i�[���ꂽ�s��)�����
		/////////////////////////////////////////
		Matrix MakeWorldTransform();

	};

	
}

#endif