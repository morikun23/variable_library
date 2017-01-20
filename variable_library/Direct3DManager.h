#ifndef DIRECT_3D_MANAGER
#define DIRECT_3D_MANAGER

/////////////////////////////////////
//クラス名：Direct3DManager
//作成者　：森田　勝
//概要　　：Direct3Dの機能
//更新　　：
//H29/01/15：クラスの作成
/////////////////////////////////////

#include <D3D11.h>
#include <Windows.h>
#include "WindowBase.h"

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")
class Direct3DManager {
private:
	//ウィンドウ
	variableNS::WindowBase* _window;
	//デバイス
	ID3D11Device* _device = NULL;
	ID3D11DeviceContext* _deviceContext = NULL;

	//スワップチェーン
	IDXGISwapChain* _swapChain = NULL;
	ID3D11RenderTargetView* _renderTargetView = NULL;
public:

	Direct3DManager(variableNS::WindowBase* arg_window) {
		_window = arg_window;
	}
	virtual ~Direct3DManager() {}

	bool Init();
	bool CreateSwapChainDesc();
	void CreateRenderTargetView();
	void CreateViewPort();
	void Render();

};


#endif // !DIRECT_3D_MANAGER
