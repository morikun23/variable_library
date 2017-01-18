#ifndef DIRECT_3D_MANAGER
#define DIRECT_3D_MANAGER

/////////////////////////////////////
//クラス名：Direct3DManager
//作成者　：森田　勝
//概要　　：Direct3Dの機能
//更新　　：
//H29/01/15：クラスの作成
/////////////////////////////////////

#include <d3dx11.h>
#include <Windows.h>

class Direct3DManager {
public:

	Direct3DManager(HWND hwnd) {
		m_handle = hwnd;
	}
	virtual ~Direct3DManager() {

	}

	HWND m_handle;
	ID3D11Device* m_device = NULL;
	ID3D11DeviceContext* m_deviceContext = NULL;
	IDXGISwapChain* m_swapChain = NULL;
	ID3D11RenderTargetView* m_renderTargetView = NULL;

	bool Init();

	void Render();
};


#endif // !DIRECT_3D_MANAGER
