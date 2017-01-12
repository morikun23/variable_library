#include "NMath.h"
#include <stdio.h>


using namespace variableNS;

double NMath::powResult = 1;
int NMath::mCount = 1;
int NMath::factResult = 1;

double NMath::Pi() {
	return 3.14159265359;
}

double NMath::Floor(double x) {
	return (int)(x < 0.0 ? x - 0.9 : x);//切り下げて返す
}

double NMath::Round(double x) {
	return (int)(x < 0.0 ? x : x + 0.9);//切り上げて返す
}

float NMath::Max(float x, float y) {

	if (x > y) {
		return x;
	}
	
		return y;
	
}
//まだできてない
float NMath::Max(float x[],int y) {
	
	if (x[0] < x[mCount]) {
		x[0] = x[mCount];
	}
	mCount++;
	y--;
	if (y == 0) {
		mCount = 1;//初期化
		return x[0];
	}

	return Max(x, y);
}

float NMath::Min(float x, float y) {

	if (x < y) {
		return x;
	}

	return y;

}
//まだできてない
float NMath::Min(float x[],int y) {
	
	if (x[0] > x[mCount-1]) {
		x[0] = x[mCount-1];
	}
	mCount++;
	y--;
	if (y == 0) {
		mCount = 1;
		return x[0];
	}

	return Min(x, y);
}

double NMath::Ads(double x) {

		if (x > 0) {
			return x;
		}
		else if (x == 0) {
			return 0;
		}
		else if (x < 0) {
			return -x;
		}

}

double NMath::Fact(int x) {

	factResult = factResult *x;

	x--;

	if (x == 0) {
		int i = factResult;//factResultを初期化する前に代入をする
		factResult = 1;//初期化
		return i;
	}

	return Fact(x);

}

double NMath::Sqrt(double x) {

	double s1 = 1, s2;
	if (x <= 0) {
		return 0;//Error
	}
	do
	{
		s2 = s1;
		s1 = (x / s1 + s1) / 2;

	} while (s1 != s2);

	return s1;
}

double NMath::Clamp(double x, double min, double max) {

	if (x < min) {
		x = min;
	}
	else if (x > max) {
		x = max;
	}
	return x;
}

double NMath::Repeat(double x, double min, double max) {

	if (x > max) {
		x -= (max - min);
		return Repeat(x, min, max);
	}

	return x;

}

double NMath::Lerp(float a, float b, float t) {
	
	if (t == 0)return a;
	else if (t == 1) return b;

	return (a+b)*t;

}



double NMath::Log(double x) {

	int i, t;
	double r = 0.0;

	for (i = 0; i < 13; i++) {
		t = i * 2 + 1;
		r += Pow( (x - 1.0)/(x + 1.0), t) / double(t);
	}

	return 2.0 * r;
}

double NMath::Pow(double x, int y) {

	if (y <= 0) return 0;//Error
	if (y == 0) return powResult;
		
	powResult *= x;
	y--;
	if (y != 0) return Pow(x, y);

	double i = powResult;//powResultを初期化する前に代入をする
	powResult = 1;//初期化
		return i;
}

double NMath::DegToRad(double x) {
	return x*(Pi() / 180);
}

double NMath::RadToDeg(double x) {
	return x*(180 / Pi());
}

double NMath::Sin(double rad) {

	double t, y;
	int n;

	y = rad;
	t = rad;
	n = 2;

	while (1)
	{
		t = -t*rad*rad / ((2 * n - 2)*(2 * n - 1));
		if (Ads(t) <= 0.00001) break;
		y = y + t;
		n++;
	}
	return y;
}

double NMath::Cos(double rad) {
	double t, y;
	int n;

	y = 1.0;
	t = 1.0;
	n = 1;

	while (1) {
		t = -t*rad*rad / ((2 * n)*(2 * n - 1));
		if (Ads(t) <= 0.00001) break;
		y = y + t;
		n++;
	}
	return y;

}

double NMath::Tan(double rad) {
	
	return Sin(rad) / Cos(rad);
}
//できていない
double NMath::ASin(double rad) {
	if (rad <= -1 || rad >= 1) return 0;
	
	return 1;

}
//できていない
double NMath::ACos(double rad) {
	if (rad <= -1 || rad >= 1) return 0;

	return 1;

}

double NMath::ATan2(double a , double b) {
	if (a < 0) {
		// 引数がマイナスのケースをなくしておく
		if (b < 0) {
			// 両方マイナスなら、符号を入れ替えてそのまま計算
			a = -a;
			b = -b;
		}
		else {
			return -ATan2(-a, b);
		}
	}
	else if (b < 0) {
		return -ATan2(a, -b);
	}
	else if (a > b) {
		// 45度以上の場合は収束しないので逆数を使う
		return 90 - ATan2(b, a);
	}

	double u = (double)a / b;

	if (a * 3 >= b * 2) {
		// 45度に近いと収束が悪いので、2倍角の公式から導出される代替式を使う
		double v = (Sqrt(1.0 + u * u) - 1.0) / u;
		return 2.0 * ATan2((int)(v * 2000 + 0.5), 2000);

		return v;
	}
	/*
	double p = 57.295778965948;  // 180 / π
	double ret = 0.0;
	double v = u;
	double d = 99.0;
	int c = 1;
	while (d >= 0.1 || d <= -0.1) {
		d = p * v / c;
		ret += d;
		v *= u * u;
		c = (c < 0 ? 2 : -2) - c;
	}
	//return ret;
	return NMath::DegToRad(ret);
	*/
}
