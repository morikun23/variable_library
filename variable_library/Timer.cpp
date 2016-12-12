#include "Timer.h"
#include <stdio.h>
#include <time.h>
#include <Windows.h>

using namespace variableNS;

int Timer::start = 0;
int Timer::count = 0;

Timer::Timer() {

}
Timer::~Timer() {

}

float Timer::GetTimer(){
	//システムの経過時間取得してそれを戻り値として返す
	return clock()/1000;
}

//保留中の関数です
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

bool Timer::Delay(int waitTime) {
	
	Timer timer;

	struct tm tm;
	//時間情報の取得
	time_t t = time(NULL);
	//日本時間に変換
	localtime_s(&tm, &t);


	if (count == 0) {
		start = clock(); //37
		count++;
	}
		

    

	if ((start + waitTime * 1000) < clock() ) {// 37+5  < 38  39
		
		start = 0;
		count = 0;

		return true;

		
	}
	
		return false;
	
}

int Timer::GetSecond() {

	struct tm tm;
	//時間情報の取得
	time_t t = time(NULL);
	//日本時間に変換
	localtime_s(&tm, &t);
	//秒を返す
	return (int)tm.tm_sec;
}

int Timer::GetMinutes() {
	struct tm tm;
	//時間情報の取得
	time_t t = time(NULL);
	//日本時間に変換
	localtime_s(&tm, &t);
	//分を変えす
	return (int)tm.tm_min;
}

int Timer::GetHour() {
	struct tm tm;
	//時間情報の取得
	time_t t = time(NULL);
	//日本時間に変換
	localtime_s(&tm, &t);
	//時を返す
	return (int)tm.tm_hour;
}

int Timer::GetDate() {
	struct tm tm;
	//時間情報の取得
	time_t t = time(NULL);
	//日本時間に変換
	localtime_s(&tm, &t);
	//日を返す
	return (int)tm.tm_mday ;
}

int Timer::GetMonth() {
	struct tm tm;
	//時間情報の取得
	time_t t = time(NULL);
	//日本時間に変換
	localtime_s(&tm, &t);
	//月を返す
	return (int)tm.tm_mon+1;
}

int Timer::GetYear() {
	struct tm tm;
	//時間情報の取得
	time_t t = time(NULL);
	//日本時間に変換
	localtime_s(&tm, &t);
	//西暦年を返す
	return (int)tm.tm_year+1900;
}



