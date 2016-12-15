#include "NMath.h"

using namespace variableNS;

double NMath::pow_result = 1;
int NMath::cnt = 1;

double NMath::Pi() {
	return 3.14159265359;
}

double NMath::Floor(double x) {
	return (int)(x < 0.0 ? x - 0.9 : x);
}

double NMath::Round(double x) {
	return (int)(x < 0.0 ? x : x + 0.9);
}

float NMath::Max(float x, float y) {

	if (x > y) {
		return x;
	}
	
		return y;
	
}
//‚Ü‚¾‚Å‚«‚Ä‚È‚¢
float NMath::Max(float x[],int y) {
	
	if (x[0] < x[cnt]) {
		x[0] = x[cnt];
	}
	cnt++;
	y--;
	if (y == 0) {
		cnt = 1;
		return x[0];
	}

	return NMath::Max(x, y);
}

float NMath::Min(float x, float y) {

	if (x < y) {
		return x;
	}

	return y;

}
//‚Ü‚¾‚Å‚«‚Ä‚È‚¢
float NMath::Min(float x[],int y) {
	
	if (x[0] > x[cnt-1]) {
		x[0] = x[cnt-1];
	}
	cnt++;
	y--;
	if (y == 0) {
		cnt = 1;
		return x[0];
	}

	return NMath::Min(x, y);
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

double NMath::Sqrt(double x) {

	double s1 = 1, s2;
	if (x <= 0) {
		return 0;/*ƒGƒ‰[ˆ—*/
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
		return NMath::Repeat(x, min, max);
	}

	return x;

}

double NMath::Lerp(float a, float b, float t) {
	
	if (t == 0)return a;
	else if (t == 1) return b;

	return (a+b)*t;

}

//‚Ü‚¾‚Å‚«‚Ä‚È‚¢
double NMath::Log(double x) {
	return 0;
}

double NMath::Pow(double x, int y) {


	if (y == 0) return 1;
		
	NMath::pow_result *= x;
	y--;
	if (y != 0) return NMath::Pow(x, y);

	double i = NMath::pow_result;
	NMath::pow_result = 1;
		return i;
}

double NMath::DegToRad(double x) {
	return x*(NMath::Pi() / 180);
}

double NMath::RadToDeg(double x) {
	return x*(180 / NMath::Pi());
}

double NMath::Sin(double x) {
	return 0;

}

double NMath::Cos(double x) {
	return 0;

}

double NMath::Tan2(double x) {
	return 0;

}

double NMath::ASin(double x) {
	return 0;

}

double NMath::ACos(double x) {
	return 0;

}

double NMath::ATan2(double x) {
	return 0;

}
