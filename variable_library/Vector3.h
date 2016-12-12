//////////////////////////////////////////////////////////////////
//�N���X���F Vector3 
//�쐬�� �F��R�@�� 
//�T�v  �F���_(�E�B���h�E�̍���[)����̃x�N�g��(�͂̌�����傫��)���擾������ύX�����肷��N���X
//�X�V  �FH28/12/04/ �N���X�̍쐬 
//�@�@�@�FH28/12/11/�@�O�ς����߂�֐���ǉ�
//////////////////////////////////////////////////////////////////
#ifndef VECTOR3
#define VECTOR3

namespace variableNS {

	class Vector3 {

	public:
		//Vector3(x,y,z)
		float x, y,z;


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
		Vector3(float xx, float yy,float zz);


		//////////////////////////////////////
		//�f�X�g���N�^
		//////////////////////////////////////
		virtual ~Vector3();

		//////////////////////////////////////
		//���W��������֐�
		//xx : ������邘���W
		//yy : ������邙���W
		//////////////////////////////////////
		void Set(float xx, float yy, float zz);


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


		//////////////////////////////////////
		//���Z��operator
		//////////////////////////////////////
		Vector3 operator + (Vector3 vec) {
			x = x + vec.x;
			y = y + vec.y;
			z = z + vec.z;
			return *this;
		}
		Vector3 operator += (Vector3 vec) {
			x += vec.x;
			y += vec.y;
			z += vec.z;
			return *this;
		}

		//////////////////////////////////////
		//���Z��operator
		//////////////////////////////////////
		Vector3 operator - (Vector3 vec) {
			x = x - vec.x;
			y = y - vec.y;
			z = z - vec.z;
			return *this;
		}
		Vector3 operator -= (Vector3 vec) {
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
			return *this;
		}

		//////////////////////////////////////
		//�U��operator
		//////////////////////////////////////
		bool operator != (Vector3 vec) {
			bool vectorFlag;
			if (x != vec.x && y != vec.y && z != vec.z) {
				vectorFlag = true;
			}
			else {
				vectorFlag = false;
			}
			return vectorFlag;
		}

		//////////////////////////////////////
		//�^��operator
		//////////////////////////////////////
		bool operator == (Vector3 vec) {
			bool vectorFlag;
			if (x == vec.x && y == vec.y && z == vec.z) {
				vectorFlag = true;
			}
			else {
				vectorFlag = false;
			}
			return vectorFlag;
		}

		//////////////////////////////////////
		//��Z��operator
		//�x�N�g�����m�̏�Z�͂��@�x�������ł�
		//////////////////////////////////////
		Vector3 operator * (int number) {
			x = x * number;
			y = y * number;
			z = z * number;
			return *this;
		}
		Vector3 operator * (float number) {
			x = x * number;
			y = y * number;
			z = z * number;
			return *this;
		}

		//////////////////////////////////////
		//���@��operator
		//�x�N�g�����m�̏��@�����@�x�������ł�
		//////////////////////////////////////
		Vector3 operator / (int number) {
			x = x / number;
			y = y / number;
			z = z / number;
			return *this;
		}
		Vector3 operator / (float number) {
			x = x / number;
			y = y / number;
		    z = z / number;
			return *this;
		}
	};


}

#endif // !1