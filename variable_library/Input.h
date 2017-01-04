#ifndef  INPUT
#define INPUT
//////////////////////////////////////////
//クラス名：Input
//作成者　：森田　勝
//概要　　：デバイスの入力状態などを扱っています。
//			対応デバイスは以下の通りです。
//			・マウス
//			・キーボード
//			・ジョイスティック
//更新　　：
//
//////////////////////////////////////////

#include<dinput.h>
namespace variableNS {

	//キーコード一覧
	enum KeyCode {
		A = DIK_A, B = DIK_B, C = DIK_C, D = DIK_D, E = DIK_E,
		F = DIK_F, G = DIK_G, H = DIK_H, I = DIK_I, J = DIK_J,
		K = DIK_K, L = DIK_L, M = DIK_M, N = DIK_N, O = DIK_O,
		P = DIK_P, Q = DIK_Q, R = DIK_R, S = DIK_S, T = DIK_T,
		U = DIK_U, V = DIK_V, W = DIK_W, X = DIK_X, Y = DIK_Y,
		Z = DIK_Z, Space = DIK_SPACE,
		LeftAlt = DIK_LALT, RightAlt = DIK_RALT,
	};

	class Input {
	private:

		//キーの長さ(一般的に256)
		static const int KEY_LENGTH = 256;
		//キーが押されていることを格納（継続）
		static bool keyIsDown[KEY_LENGTH];
		static bool keyIsPressed[KEY_LENGTH];
		
		
	public:

		//////////////////////////////////////
		//初期化
		/////////////////////////////////////
		void Initialize();
		void GetDeviceState();
		
		static void InputKeyCode(int);
		static bool GetKeyDown(KeyCode);
	};
}
#endif // ! INPUT
