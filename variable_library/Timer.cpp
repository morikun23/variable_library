#include "Timer.h"
#include <stdio.h>
#include <time.h>
#include <Windows.h>

using namespace variableNS;

float Timer::start = 0.f;
int Timer::count = 0;

Timer::Timer() {

}
Timer::~Timer() {

}

float Timer::GetTimer(){
	//�V�X�e���̌o�ߎ��Ԏ擾���Ă����߂�l�Ƃ��ĕԂ�
	return clock()/1000;
}

//�ۗ����̊֐��ł�
float Timer::FrameTime() {
	

	Timer timer;

	if (count == 0) {
		count++;
		return timer.startTime = clock();
	}

	timer.endTime = clock();

	clock_t time = (timer.endTime - timer.startTime) / (double)CLOCKS_PER_SEC;

	timer.startTime = clock();

	return time;

}

bool Timer::Delay(float waitTime) {
	

	if (count == 0) {
		start = clock(); // 0
		count++;
	}
		

    

	if ( (start + waitTime * 1000) <= clock()) {// 0+5500 < 
		
		start = 0;
		count = 0;

		return true;
		
	}
	
		return false;
	
}

int Timer::GetSecond() {

	struct tm tm;
	//���ԏ��̎擾
	time_t t = time(NULL);
	//���{���Ԃɕϊ�
	localtime_s(&tm, &t);
	//�b��Ԃ�
	return (int)tm.tm_sec;
}

int Timer::GetMinutes() {
	struct tm tm;
	//���ԏ��̎擾
	time_t t = time(NULL);
	//���{���Ԃɕϊ�
	localtime_s(&tm, &t);
	//����ς���
	return (int)tm.tm_min;
}

int Timer::GetHour() {
	struct tm tm;
	//���ԏ��̎擾
	time_t t = time(NULL);
	//���{���Ԃɕϊ�
	localtime_s(&tm, &t);
	//����Ԃ�
	return (int)tm.tm_hour;
}

int Timer::GetDate() {
	struct tm tm;
	//���ԏ��̎擾
	time_t t = time(NULL);
	//���{���Ԃɕϊ�
	localtime_s(&tm, &t);
	//����Ԃ�
	return (int)tm.tm_mday ;
}

int Timer::GetMonth() {
	struct tm tm;
	//���ԏ��̎擾
	time_t t = time(NULL);
	//���{���Ԃɕϊ�
	localtime_s(&tm, &t);
	//����Ԃ�
	return (int)tm.tm_mon+1;
}

int Timer::GetYear() {
	struct tm tm;
	//���ԏ��̎擾
	time_t t = time(NULL);
	//���{���Ԃɕϊ�
	localtime_s(&tm, &t);
	//����N��Ԃ�
	return (int)tm.tm_year+1900;
}



