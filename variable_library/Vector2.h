//////////////////////////////////////////////////////////////////
//�N���X���F Vector2 
//�쐬�� �F��R�@�� 
//�T�v  �F���_(�E�B���h�E�̍���[)����̃x�N�g��(�͂̌�����傫��)���擾������ύX�����肷��N���X
//�X�V  �FH28/12/02/ �N���X�̍쐬 
//�@�@�@�FH28/12/11/�@�O�ς����߂�֐���ǉ�
//////////////////////////////////////////////////////////////////
#ifndef VECTOR2
#define VECTOR2

namespace variableNS {

	class Vector2 {

	public:
		//Vector2(x,y)
		float x, y;


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
		Vector2(float xx, float yy);
		

		//////////////////////////////////////
		//�f�X�g���N�^
		//////////////////////////////////////
		virtual ~Vector2();

		//////////////////////////////////////
		//���W��������֐�
		//xx : ������邘���W
		//yy : ������邙���W
		//////////////////////////////////////
		void Set(float xx, float yy);


		//////////////////////////////////////
		//�x�N�g���̑傫�����P�ɑ�����(���K��)
		//////////////////////////////////////
		void Normalize();


		//////////////////////////////////////
		//�����Vector2�Ԃ̓��ς�Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//////////////////////////////////////
		static float Dot(Vector2 vec1, Vector2 vec2);


		//////////////////////////////////////
		//�����Vector2�Ԃ̊O�ς�Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//////////////////////////////////////
		static float Cross(Vector2 vec1, Vector2 vec2);


		//////////////////////////////////////
		//�����Vector2�Ԃ̊p�x��Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//////////////////////////////////////
		static float Angle(Vector2 vec1, Vector2 vec2);


		//////////////////////////////////////
		//�����Vector2�Ԃ̋�����Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//////////////////////////////////////
		static float Distance(Vector2 vec1, Vector2 vec2);
		

		//////////////////////////////////////
		//�����Vector2�Ԃ̔��ˊp��Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//////////////////////////////////////
		static Vector2 Reflect(Vector2 vec1, Vector2 vec2);
		

		//////////////////////////////////////
		//�����Vector2��������Ă邩�ǂ�����Ԃ�
		//vec1 : ����ڂ�Vector2
		//vec2 : ����ڂ�Vector2
		//vec3 : �O���ڂ�Vector2
		//vec4 : �l���ڂ�Vector2
		//////////////////////////////////////
		static bool IsCross(Vector2 vec1, Vector2 vec2,Vector2 vec3, Vector2 vec4);


		//////////////////////////////////////
		//���Z��operator
		//////////////////////////////////////
		Vector2 operator + (Vector2 vec) {
			x = x + vec.x;
			y = y + vec.y;
			return *this;
		}
		Vector2 operator += (Vector2 vec) {
			x += vec.x;
			y += vec.y;
			return *this;
		}

		//////////////////////////////////////
		//���Z��operator
		//////////////////////////////////////
		Vector2 operator - (Vector2 vec) {
			x = x - vec.x;
			y = y - vec.y;
			return *this;
		}
		Vector2 operator -= (Vector2 vec) {
			x -= vec.x;
			y -= vec.y;
			return *this;
		}

		//////////////////////////////////////
		//�U��operator
		//////////////////////////////////////
		bool operator != (Vector2 vec) {
			bool vectorFlag;
			if (x != vec.x && y != vec.y) {
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
		bool operator == (Vector2 vec) {
			bool vectorFlag;
			if (x == vec.x && y == vec.y) {
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
		Vector2 operator * (int number) {
			x = x * number;
			y = y * number;
			return *this;
		}
		Vector2 operator * (float number) {
			x = x * number;
			y = y * number;
			return *this;
		}

		//////////////////////////////////////
		//���@��operator
		//�x�N�g�����m�̏��@�����@�x�������ł�
		//////////////////////////////////////
		Vector2 operator / (int number) {
			x = x / number;
			y = y / number;
			return *this;
		}
		Vector2 operator / (float number) {
			x = x / number;
			y = y / number;
			return *this;
		}

	};


}
#endif // !1
