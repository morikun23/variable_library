//////////////////////////////////////////////////////////////////
//�N���X���F Vector4 
//�쐬�� �F��R�@�� 
//�T�v  �F���_(�E�B���h�E�̍���[)����̃x�N�g��(�͂̌�����傫��)���擾������ύX�����肷��N���X
//�X�V  �FH28/12/05/ �N���X�̍쐬 
//�@�@�@�FH28/12/11/�@�O�ς����߂�֐���ǉ�
//////////////////////////////////////////////////////////////////
#ifndef VECTOR4
#define VECTOR4

namespace variableNS {

	class Vector4 {

	public:
		//Vector4(x,y,z,w)
		float x, y, z, w;


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
		Vector4(float xx, float yy, float zz,float ww);


		//////////////////////////////////////
		//�f�X�g���N�^
		//////////////////////////////////////
		virtual ~Vector4();

		//////////////////////////////////////
		//���W��������֐�
		//xx : ������邘���W
		//yy : ������邙���W
		//////////////////////////////////////
		void Set(float xx, float yy, float zz, float ww);


		//////////////////////////////////////
		//�x�N�g���̑傫�����P�ɑ�����(���K��)
		//////////////////////////////////////
		void Normalize();


		//////////////////////////////////////
		//�����Vector4�Ԃ̓��ς�Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//////////////////////////////////////
		static float Dot(Vector4 vec1, Vector4 vec2);


		//////////////////////////////////////
		//�����Vector2�Ԃ̊O�ς�Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//////////////////////////////////////
		static Vector4 Cross(Vector4 vec1, Vector4 vec2);


		//////////////////////////////////////
		//�����Vector4�Ԃ̊p�x��Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//////////////////////////////////////
		static float Angle(Vector4 vec1, Vector4 vec2);


		//////////////////////////////////////
		//�����Vector4�Ԃ̋�����Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//////////////////////////////////////
		static float Distance(Vector4 vec1, Vector4 vec2);


		//////////////////////////////////////
		//�����Vector4�Ԃ̔��ˊp��Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//////////////////////////////////////
		static Vector4 Reflect(Vector4 vec1, Vector4 vec2);


		//////////////////////////////////////
		//�����Vector4��������Ă邩�ǂ�����Ԃ�
		//vec1 : ����ڂ�Vector4
		//vec2 : ����ڂ�Vector4
		//vec3 : �O���ڂ�Vector4
		//vec4 : �l���ڂ�Vector4
		//////////////////////////////////////
		static bool IsCross(Vector4 vec1, Vector4 vec2, Vector4 vec3, Vector4 vec4);


		//////////////////////////////////////
		//���Z��operator
		//////////////////////////////////////
		Vector4 operator + (Vector4 vec) {
			x = x + vec.x;
			y = y + vec.y;
			z = z + vec.z;
			w = w + vec.w;
			return *this;
		}
		Vector4 operator += (Vector4 vec) {
			x += vec.x;
			y += vec.y;
			z += vec.z;
			w += vec.w;
			return *this;
		}

		//////////////////////////////////////
		//���Z��operator
		//////////////////////////////////////
		Vector4 operator - (Vector4 vec) {
			x = x - vec.x;
			y = y - vec.y;
			z = z - vec.z;
			w = w - vec.w;
			return *this;
		}
		Vector4 operator -= (Vector4 vec) {
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
			w -= vec.w;
			return *this;
		}

		//////////////////////////////////////
		//�U��operator
		//////////////////////////////////////
		bool operator != (Vector4 vec) {
			bool vectorFlag;
			if (x != vec.x && y != vec.y && z != vec.z && w != vec.w) {
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
		bool operator == (Vector4 vec) {
			bool vectorFlag;
			if (x == vec.x && y == vec.y && z == vec.z && w == vec.w) {
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
		Vector4 operator * (int number) {
			x = x * number;
			y = y * number;
			z = z * number;
			w = w * number;
			return *this;
		}
		Vector4 operator * (float number) {
			x = x * number;
			y = y * number;
			z = z * number;
			w = w * number;
			return *this;
		}

		//////////////////////////////////////
		//���@��operator
		//�x�N�g�����m�̏��@�����@�x�������ł�
		//////////////////////////////////////
		Vector4 operator / (int number) {
			x = x / number;
			y = y / number;
			z = z / number;
			w = w / number;
			return *this;
		}
		Vector4 operator / (float number) {
			x = x / number;
			y = y / number;
			z = z / number;
			w = w / number;
			return *this;
		}
	};


}

#endif // !1