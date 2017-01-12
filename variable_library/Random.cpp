#include"Random.h"
using namespace variableNS;
using namespace std;

//Valueの処理
float Random::Value() {

	//非決定論的な乱数生成エンジンによって、rdに乱数を呼び出す。
	random_device randomDevice;
	
	//上記のみだと毎回ハードウェアエントロピーソースを収集するため、実行速度が遅い
	//初期シードから長周期の乱数列を高速に生成するメルセンヌ・ツイスターも呼び出します。
	mt19937 mersenneTwister(randomDevice());

	//1 ～　9の範囲に一様に分布する整数の乱数を生成。
	uniform_int_distribution<int> range(0,10);

	//0.1をかけることで小数点を出し戻り値として渡す
	return range(mersenneTwister) * 0.1f;

}

//Rangeの処理
int   Random::Range(int min, int max) {

	random_device randomDevice;
	mt19937 mersenneTwister(randomDevice());

	//2つの範囲に一様に分布するintの乱数を生成。
	uniform_int_distribution<int> range(min, max);

	//生成した乱数の整数を戻り値として渡す
	return range(mersenneTwister);
}

//Rangeのオーバーロードの処理
float Random::Range(float min, float max) {

	//小数点にするために１度、値を格納するための変数
	float dimension;

	random_device randomDevice;
	mt19937 mersenneTwister(randomDevice());

	//2つの範囲に一様に分布するfloatの乱数を生成。
	uniform_real_distribution<float> range(min, max);

	//小数点第２位にするための変換で1度10倍します。
	dimension = range(mersenneTwister) * 10;

	//そのあとでfloatからintに変換
	dimension = (float)(int)(dimension);

	//intに変換した値に0.1をかけることで小数点を出し戻り値として渡す
	return dimension * 0.1f;

} 