#ifndef TIMER
#define TIMER

#include <time.h>

//////////////////////////////////////

//�N���X��:�@Timer

//�쐬��  :�@��{�@�^��

//�T�v    :�@�Q�[�������̎��Ԃ��Q�Ƃ���N���X

//�X�V    :
//H28/12/1/ �N���X�쐬
//H28/12/2/ GetTimer�֐��쐬
//H28/12/3/ Delay�֐��̍쐬 
//			GetYear�֐��ȉ����ԂɊւ���֐��̍쐬
//H28/12/4/ FrameTime�֐��̍쐬
//H28/12/12 GetTimer�֐��̏C��
//					�����_�ŋL�q�ł���悤�ɕύX�@�C���O�Fif (i+5500 < Timer::GetTimer())  
//												�@�C����Fiif (i+5.0f < Timer::GetTimer()) 
//			Delay�֐��̏C��
//					waitTime�̒�`�������_�ɂłł���悤�ɕύX

///////////////////////////////////

namespace variableNS {

	
	class Timer
	{
	
	private:	

		//����J�n����
		clock_t startTime;

		//����I������
		clock_t endTime;

	

		static float start;
		static int count;

	public:

		

		////////////////////////
		//�R���X�g���N�^
		///////////////////////
		Timer();


		///////////////////////
		//�f�X�R���g���N�^
		///////////////////////
		virtual ~Timer();


		///////////////////////
		//�V�X�e���N���J�n����̌o�ߎ��Ԃ�Ԃ�
		//�@clock() : �V�X�e���o�ߎ���
		///////////////////////
		static float GetTimer();


		///////////////////////
		//�Ō�̃t���[������������̂ɗv��������(�b)��Ԃ�
		//�@
		///////////////////////
		static float FrameTime();


		///////////////////////
		//�w�肵������(�b)���true��Ԃ�
		//
		///////////////////////
		static bool Delay(float waitTime);


		///////////////////////
		//����N��߂�l�ŕԂ�
		//�@year  :����N
		///////////////////////
		static int GetYear();


		///////////////////////
		//����߂�l�ŕԂ�
		//�@month  :��
		///////////////////////
		static int GetMonth();


		///////////////////////
		//����߂�l�ŕԂ�
		//�@date  :��
		///////////////////////
		static int GetDate();


		///////////////////////
		//����߂�l�ŕԂ�
		//�@hour  :��
		///////////////////////
		static int GetHour();


		///////////////////////
		//����߂�l�ŕԂ�
		//�@minutes  :��
		///////////////////////
		static int GetMinutes();


		//////////////////////
		//�b��߂�l�ŕԂ�
		//�@hsecond  :�b
		///////////////////////
		static int GetSecond();

	
	};
}

#endif // !TIMER