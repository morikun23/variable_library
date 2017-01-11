#ifndef QUATERNION
#define QUATERNION

//////////////////////////////////////////////////////////////////
//�N���X���F Quaternion
//�쐬�� �F��R�@�� 
//�T�v  �F��]�����i�[����N���X
//�X�V  �FH29/01/04/ �N���X�̍쐬
//////////////////////////////////////////////////////////////////

#include"Vector3.h"
#include"Vector4.h"

namespace variableNS {

	class Quaternion {

	private:
		
		
	public:
		float x, y, z, w;

		Quaternion();
		Quaternion(int xx, int yy, int zz, int ww);
		Quaternion(float xx,float yy,float zz,float ww);
		Quaternion(Vector4 vec);
		~Quaternion();

		//////////////////////////////////////////////
		//�l�����̒P�ʉ�(��]���Ă��Ȃ����)
		//////////////////////////////////////////////
		void Identity();


		//////////////////////////////////////////////
		//�l�����̐�Βl��Ԃ�(�m�����ƌĂ΂��)
		//////////////////////////////////////////////
		float Norm();


		//////////////////////////////////////////////
		//�l�̃Z�b�g
		//quaternion : x,y,z,w�̎O����
		//////////////////////////////////////////////
		void Set(Quaternion quaternion);


		//////////////////////////////////////////////
		//�I�C���[�p�ŉ�]
		//vec : x,y,z�̎O����
		//////////////////////////////////////////////
		void EulerAngles(Vector3 vec);


		//�e�I�y���[�^
		void operator =(Quaternion);
		Quaternion operator *(Quaternion);
		void operator *=(Quaternion);
		Quaternion operator +(Quaternion);
		void operator +=(Quaternion);
		Quaternion operator -(Quaternion);
		void operator -=(Quaternion);
		bool operator ==(Quaternion);
		bool operator !=(Quaternion);
	};
}

#endif