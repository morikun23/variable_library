#ifndef VECTOR2
#define VECTOR2

//////////////////////////////////////////////////////////////////
//�N���X���F Vector2 
//�쐬�� �F��R�@�� 
//�T�v  �F���_(�E�B���h�E�̍���[)����̃x�N�g��(�͂̌�����傫��)���擾������ύX�����肷��N���X
//�X�V  �FH28/12/02/ �N���X�̍쐬 
//�@�@�@�FH28/12/11/�@�O�ς����߂�֐���ǉ�
//�@�@�@�FH28/12/12/�@���t�@�N�^�����O�ASet�֐���Vector�������ɂƂ�������ǉ�
//�@�@�@�FH29/01/10/�@�I�y���[�^�̌������ƋL�q�ꏊ�̕ύX
//�@�@�@�FH29/01/20/�@�����o�ϐ��y�сA�����o�֐����ł̈����̖��O��ύX
//////////////////////////////////////////////////////////////////

namespace variableNS {

	class Vector2 {

	public:
		//Vector2(x,y)
		float _x, _y;


		///////////////////////////////////////
		//�萔ZERO��ONE�̒�`(�w�b�_�[�t�@�C���ł͒萔�̒l�̊i�[�܂ł͂ł��Ȃ�)
		//ZERO�Ńx�N�g���̒������O�ɁAONE�łP�ɂ���
		///////////////////////////////////////
		static const Vector2 ZERO;
		static const Vector2 ONE;

		/////////////////////////////////////////
		//�R���X�g���N�^
		/////////////////////////////////////////
		Vector2();


		///////////////////////////////////////
		//�����Ȃ��R���X�g���N�^
		//xx : �����W�̏����l
		//yy : �����W�̏����l
		///////////////////////////////////////
		Vector2(int arg_x, int arg_y);
		Vector2(float arg_x, float arg_y);
		

		//////////////////////////////////////
		//�f�X�g���N�^
		//////////////////////////////////////
		virtual ~Vector2();

		//////////////////////////////////////
		//���W��������֐�
		//xx : ������邘���W
		//yy : ������邙���W
		//vec : �������x,y������������Vector2
		//////////////////////////////////////
		void Set(float arg_x, float arg_y);
		void Set(Vector2 arg_vec);

		//////////////////////////////////////
		//�x�N�g���̑傫�����P�ɑ�����(���K��)
		//////////////////////////////////////
		void Normalize();


		//////////////////////////////////////
		//�����Vector2�Ԃ̓��ς�Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//////////////////////////////////////
		static float Dot(Vector2 arg_vec1, Vector2 arg_vec2);


		//////////////////////////////////////
		//�����Vector2�Ԃ̊O�ς�Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//////////////////////////////////////
		static float Cross(Vector2 vvec1, Vector2 arg_vec2);


		//////////////////////////////////////
		//�����Vector2�Ԃ̊p�x��Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//////////////////////////////////////
		static float Angle(Vector2 arg_vec1, Vector2 arg_vec2);


		//////////////////////////////////////
		//�����Vector2�Ԃ̋�����Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//////////////////////////////////////
		static float Distance(Vector2 arg_vec1, Vector2 arg_vec2);
		

		//////////////////////////////////////
		//�����Vector2�Ԃ̔��ˊp��Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//////////////////////////////////////
		static Vector2 Reflect(Vector2 arg_vec1, Vector2 arg_vec2);
		

		//////////////////////////////////////
		//�����Vector2��������Ă邩�ǂ�����Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//vec3 : �O���ڂ�Vector2
		//vec4 : �l���ڂ�Vector2
		//////////////////////////////////////
		static bool IsCross(Vector2 arg_vec1, Vector2 arg_vec2,Vector2 arg_vec3, Vector2 arg_vec4);


		//�e�I�y���[�^
		Vector2 operator +(Vector2);
		void operator +=(Vector2);
		Vector2 operator +(int);
		void operator +=(int);
		Vector2 operator +(float);
		void operator +=(float);
		Vector2 operator -(Vector2);
		void operator -=(Vector2);
		Vector2 operator -(int);
		void operator -=(int);
		Vector2 operator -(float);
		void operator -=(float);
		Vector2 operator *(int);
		void operator *=(int);
		Vector2 operator *(float);
		void operator *=(float);
		Vector2 operator /(int);
		void operator /=(int);
		Vector2 operator /(float);
		void operator /=(float);
		void operator =(Vector2);
		bool operator ==(Vector2);
		bool operator !=(Vector2);

	};


}
#endif // !1
