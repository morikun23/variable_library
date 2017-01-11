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

namespace variableNS{

	class Transform {

	private:

		//�ʒu�̒l�A�傫���̒l���i�[����O����
		Vector3 position;
		Vector3 scale;

		//��]�̒l���i�[����l����(�N�H�[�^�j�I��)
		//Quaternion rotation;

	public:
		

		/////////////////////////////////////////
		//�R���X�g���N�^�A�f�X�g���N�^
		/////////////////////////////////////////
		Transform();
		Transform(Vector3 pos,Vector3 sca,Vector3 rota);
		virtual ~Transform();


	};

	
}

#endif