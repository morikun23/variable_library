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
		const Vector3 euler;

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
		//�l�����̒�����Ԃ�(�m�����ƌĂ΂��)
		//////////////////////////////////////////////
		float Length();


		//////////////////////////////////////////////
		//�l�̃Z�b�g
		//quaternion : x,y,z,w�̎O����
		//////////////////////////////////////////////
		void Set(Quaternion quaternion);


		//////////////////////////////////////////////
		//�C�ӎ��̂܂�����]����l������Ԃ�
		//vec : ��
		//x,y,z :��L�Ɠ��`
		//angle : ��]�p�x
		//////////////////////////////////////////////
		Quaternion RotateAxis(Vector3 vec,float angle);
		Quaternion RotateAxis(float x, float y, float z,float angle);


		//////////////////////////////////////////////
		//�l�������O�����ɕϊ�����
		//q : �ϊ��������l����
		//////////////////////////////////////////////
		Vector3 ToVector3();


		//�e�I�y���[�^
		void operator =(Quaternion);
		void operator =(Vector3);
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