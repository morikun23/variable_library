#ifndef VECTOR4
#define VECTOR4

//////////////////////////////////////////////////////////////////
//�N���X���F Vector4 
//�쐬�� �F��R�@�� 
//�T�v  �F���_(�E�B���h�E�̍���[)����̃x�N�g��(�͂̌�����傫��)���擾������ύX�����肷��N���X
//�X�V  �FH28/12/05/ �N���X�̍쐬 
//�@�@�@�FH28/12/11/�@�O�ς����߂�֐���ǉ�
//�@�@�@�FH28/12/12/�@���t�@�N�^�����O�ASet�֐���Vector�������ɂƂ�������ǉ�
//�@�@�@�FH29/01/10/�@�I�y���[�^�̌������ƋL�q�ꏊ�̕ύX
//�@�@�@�FH29/01/20/�@�����o�ϐ��y�сA�����o�֐����ł̈����̖��O��ύX
//////////////////////////////////////////////////////////////////

namespace variableNS {

	class Vector4 {

	public:
		//Vector4(x,y,z,w)
		float _x, _y, _z, _w;


		///////////////////////////////////////
		//�萔ZERO��ONE�̒�`(�w�b�_�[�t�@�C���ł͒萔�̒l�̊i�[�܂ł͂ł��Ȃ�)
		//ZERO�Ńx�N�g���̒������O�ɁAONE�łP�ɂ���
		///////////////////////////////////////
		static const Vector4 ZERO;
		static const Vector4 ONE;

		/////////////////////////////////////////
		//�R���X�g���N�^
		/////////////////////////////////////////
		Vector4();


		///////////////////////////////////////
		//�����Ȃ��R���X�g���N�^
		//xx : �����W�̏����l
		//yy : �����W�̏����l
		///////////////////////////////////////
		Vector4(int arg_x, int arg_y, int arg_z,int arg_w);
		Vector4(float arg_x, float arg_y, float arg_z,float arg_w);


		//////////////////////////////////////
		//�f�X�g���N�^
		//////////////////////////////////////
		virtual ~Vector4();

		//////////////////////////////////////
		//���W��������֐�
		//xx : ������邘���W
		//yy : ������邙���W
		//vec : �������x,y,z,w������������Vector4
		//////////////////////////////////////
		void Set(float arg_x, float arg_y, float arg_z, float arg_w);
		void Set(Vector4 arg_vec);


		//////////////////////////////////////
		//�x�N�g���̑傫�����P�ɑ�����(���K��)
		//////////////////////////////////////
		void Normalize();


		//////////////////////////////////////
		//�����Vector4�Ԃ̓��ς�Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//////////////////////////////////////
		static float Dot(Vector4 arg_vec1, Vector4 arg_vec2);


		//////////////////////////////////////
		//�����Vector2�Ԃ̊O�ς�Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//////////////////////////////////////
		static Vector4 Cross(Vector4 arg_vec1, Vector4 arg_vec2);


		//////////////////////////////////////
		//�����Vector4�Ԃ̊p�x��Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//////////////////////////////////////
		static float Angle(Vector4 arg_vec1, Vector4 arg_vec2);


		//////////////////////////////////////
		//�����Vector4�Ԃ̋�����Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//////////////////////////////////////
		static float Distance(Vector4 arg_vec1, Vector4 arg_vec2);


		//////////////////////////////////////
		//�����Vector4�Ԃ̔��ˊp��Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//////////////////////////////////////
		static Vector4 Reflect(Vector4 arg_vec1, Vector4 arg_vec2);


		//////////////////////////////////////
		//�����Vector4��������Ă邩�ǂ�����Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//vec3 : �O���ڂ�Vector4
		//vec4 : �l���ڂ�Vector4
		//////////////////////////////////////
		static bool IsCross(Vector4 arg_vec1, Vector4 arg_vec2, Vector4 arg_vec3, Vector4 arg_vec4);


		//�e�I�y���[�^
		Vector4 operator +(Vector4);
		void operator +=(Vector4);
		Vector4 operator +(int);
		void operator +=(int);
		Vector4 operator +(float);
		void operator +=(float);
		Vector4 operator -(Vector4);
		void operator -=(Vector4);
		Vector4 operator -(int);
		void operator -=(int);
		Vector4 operator -(float);
		void operator -=(float);
		Vector4 operator *(int);
		void operator *=(int);
		Vector4 operator *(float);
		void operator *=(float);
		Vector4 operator /(int);
		void operator /=(int);
		Vector4 operator /(float);
		void operator /=(float);
		void operator =(Vector4);
		bool operator ==(Vector4);
		bool operator !=(Vector4);
	};


}

#endif // !1