#ifndef VECTOR3
#define VECTOR3

//////////////////////////////////////////////////////////////////
//�N���X���F Vector3 
//�쐬�� �F��R�@�� 
//�T�v  �F���_(�E�B���h�E�̍���[)����̃x�N�g��(�͂̌�����傫��)���擾������ύX�����肷��N���X
//�X�V  �FH28/12/04/ �N���X�̍쐬 
//�@�@�@�FH28/12/11/�@�O�ς����߂�֐���ǉ�
//�@�@�@�FH28/12/12/�@���t�@�N�^�����O�ASet�֐���Vector�������ɂƂ�������ǉ�
//�@�@�@�FH29/01/10/�@�I�y���[�^�̌������ƋL�q�ꏊ�̕ύX
//�@�@�@�FH29/01/19/  �N�H�[�^�j�I���ւ̕ϊ��֐���ǉ�
//////////////////////////////////////////////////////////////////

#include"Quaternion.h"

namespace variableNS {

	class Vector3 {

	public:
		float x, y, z;


		///////////////////////////////////////
		//�萔ZERO��ONE�̒�`(�w�b�_�[�t�@�C���ł͒萔�̒l�̊i�[�܂ł͂ł��Ȃ�)
		//ZERO�Ńx�N�g���̒������O�ɁAONE�łP�ɂ���
		///////////////////////////////////////
		static const Vector3 ZERO;
		static const Vector3 ONE;

		/////////////////////////////////////////
		//�R���X�g���N�^
		/////////////////////////////////////////
		Vector3();


		///////////////////////////////////////
		//�����Ȃ��R���X�g���N�^
		//xx : �����W�̏����l
		//yy : �����W�̏����l
		///////////////////////////////////////
		Vector3(int xx, int yy, int zz);
		Vector3(float xx, float yy,float zz);	


		//////////////////////////////////////
		//�f�X�g���N�^
		//////////////////////////////////////
		virtual ~Vector3();

		//////////////////////////////////////
		//���W��������֐�
		//xx : ������邘���W
		//yy : ������邙���W
		//vec : �������x,y,z������������Vector3
		//////////////////////////////////////
		void Set(float xx, float yy, float zz);
		void Set(Vector3 vec);


		//////////////////////////////////////
		//�x�N�g���̑傫�����P�ɑ�����(���K��)
		//////////////////////////////////////
		void Normalize();


		//////////////////////////////////////
		//�����Vector3�Ԃ̓��ς�Ԃ�
		//vec1 : ����ڂ�Vector3
		//vec2 : ����ڂ�Vector3
		//////////////////////////////////////
		static float Dot(Vector3 vec1, Vector3 vec2);


		//////////////////////////////////////
		//�����Vector3�Ԃ̊O�ς�Ԃ�
		//vec1 : ����ڂ�Vector3
		//vec2 : ����ڂ�Vector3
		//////////////////////////////////////
		static Vector3 Cross(Vector3 vec1, Vector3 vec2);


		//////////////////////////////////////
		//�����Vector3�Ԃ̊p�x��Ԃ�
		//vec1 : ����ڂ�Vector3
		//vec2 : ����ڂ�Vector3
		//////////////////////////////////////
		static float Angle(Vector3 vec1, Vector3 vec2);


		//////////////////////////////////////
		//�����Vector3�Ԃ̋�����Ԃ�
		//vec1 : ����ڂ�Vector3
		//vec2 : ����ڂ�Vector3
		//////////////////////////////////////
		static float Distance(Vector3 vec1, Vector3 vec2);


		//////////////////////////////////////
		//�����Vector3�Ԃ̔��ˊp��Ԃ�
		//vec1 : ����ڂ�Vector3
		//vec2 : ����ڂ�Vector3
		//////////////////////////////////////
		static Vector3 Reflect(Vector3 vec1, Vector3 vec2);


		//////////////////////////////////////
		//�����Vector3��������Ă邩�ǂ�����Ԃ�
		//vec1 : ����ڂ�Vector3
		//vec2 : ����ڂ�Vector3
		//vec3 : �O���ڂ�Vector3
		//vec4 : �l���ڂ�Vector3
		//////////////////////////////////////
		static bool IsCross(Vector3 vec1, Vector3 vec2, Vector3 vec3, Vector3 vec4);


		//////////////////////////////////////////////
		//�O�������l�����ɕϊ�����
		//////////////////////////////////////////////
		Quaternion ToQuaternion();


		//�e�I�y���[�^
		Vector3 operator +(Vector3);
		void operator +=(Vector3);
		Vector3 operator +(int);
		void operator +=(int);
		Vector3 operator +(float);
		void operator +=(float);
		Vector3 operator -(Vector3);
		void operator -=(Vector3);
		Vector3 operator -(int);
		void operator -=(int);
		Vector3 operator -(float);
		void operator -=(float);
		Vector3 operator *(int);
		void operator *=(int);
		Vector3 operator *(float);
		void operator *=(float);
		Vector3 operator /(int);
		void operator /=(int);
		Vector3 operator /(float);
		void operator /=(float);
		void operator =(Vector3);
		bool operator ==(Vector3);
		bool operator !=(Vector3);
	};


}

#endif // !1