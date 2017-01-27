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
		float _x, _y, _z, _w;
		const Vector3 _euler;

		Quaternion();
		Quaternion(int arg_x, int arg_y, int arg_z, int arg_w);
		Quaternion(float arg_x,float arg_y,float arg_z,float arg_w);
		Quaternion(Vector4 arg_vec);
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
		void Set(Quaternion arg_quat);


		//////////////////////////////////////////////
		//�C�ӎ��̂܂�����]����l������Ԃ�
		//vec : ��
		//x,y,z :��L�Ɠ��`
		//angle : ��]�p�x
		//////////////////////////////////////////////
		//Quaternion RotateAxis(Vector3 vec,float angle);
		//Quaternion RotateAxis(float x, float y, float z,float angle);


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