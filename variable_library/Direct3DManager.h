#ifndef DIRECT_3D_MANAGER
#define DIRECT_3D_MANAGER

/////////////////////////////////////
//�N���X���FDirect3DManager
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�FDirect3D�̋@�\
//�X�V�@�@�F
//H29/01/15�F�N���X�̍쐬
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
