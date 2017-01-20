#ifndef DIRECT_3D_MANAGER
#define DIRECT_3D_MANAGER

/////////////////////////////////////
//�N���X���FDirect3DManager
//�쐬�ҁ@�F�X�c�@��
//�T�v�@�@�FDirect3D�̋@�\
//�X�V�@�@�F
//H29/01/15�F�N���X�̍쐬
/////////////////////////////////////

#include <D3D11.h>
#include <Windows.h>
#include "WindowBase.h"

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")
class Direct3DManager {
private:
	//�E�B���h�E
	variableNS::WindowBase* _window;
	//�f�o�C�X
	ID3D11Device* _device = NULL;
	ID3D11DeviceContext* _deviceContext = NULL;

	//�X���b�v�`�F�[��
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
