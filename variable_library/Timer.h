#ifndef TIMER
#define TIMER

#include <time.h>

//////////////////////////////////////

//クラス名:　Timer

//作成者  :　野本　真央

//概要    :　ゲーム内部の時間を参照するクラス

//更新    :
//H28/12/1/ クラス作成
//H28/12/2/ GetTimer関数作成
//H28/12/3/ Delay関数の作成 
//			GetYear関数以下時間に関する関数の作成
//H28/12/4/ FrameTime関数の作成
//H28/12/12 GetTimer関数の修正
//					小数点で記述できるように変更　修正前：if (i+5500 < Timer::GetTimer())  
//												　修正後：iif (i+5.0f < Timer::GetTimer()) 
//			Delay関数の修正
//					waitTimeの定義を小数点にでできるように変更

///////////////////////////////////

namespace variableNS {

	
	class Timer
	{
	
	private:	

		//測定開始時刻
		clock_t startTime;

		//測定終了時刻
		clock_t endTime;

	

		static float start;
		static int count;

	public:

		

		////////////////////////
		//コンストラクタ
		///////////////////////
		Timer();


		///////////////////////
		//デスコントラクタ
		///////////////////////
		virtual ~Timer();


		///////////////////////
		//システム起動開始からの経過時間を返す
		//　clock() : システム経過時間
		///////////////////////
		static float GetTimer();


		///////////////////////
		//最後のフレームを完了するのに要した時間(秒)を返す
		//　
		///////////////////////
		static float FrameTime();


		///////////////////////
		//指定した時間(秒)後にtrueを返す
		//
		///////////////////////
		static bool Delay(float waitTime);


		///////////////////////
		//西暦年を戻り値で返す
		//　year  :西暦年
		///////////////////////
		static int GetYear();


		///////////////////////
		//月を戻り値で返す
		//　month  :月
		///////////////////////
		static int GetMonth();


		///////////////////////
		//日を戻り値で返す
		//　date  :日
		///////////////////////
		static int GetDate();


		///////////////////////
		//時を戻り値で返す
		//　hour  :時
		///////////////////////
		static int GetHour();


		///////////////////////
		//分を戻り値で返す
		//　minutes  :分
		///////////////////////
		static int GetMinutes();


		//////////////////////
		//秒を戻り値で返す
		//　hsecond  :秒
		///////////////////////
		static int GetSecond();

	
	};
}

#endif // !TIMER