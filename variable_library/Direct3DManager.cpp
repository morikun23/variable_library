#include "Direct3DManager.h"

bool Direct3DManager::Init() {
	
	if (CreateSwapChainDesc()) { 
		//CreateRenderTargetView();
		//CreateViewPort();
		return true;
	}

	return false;
}
bool Direct3DManager::CreateSwapChainDesc() {
	// �f�o�C�X�ƃX���b�v�`�F�[���̍쐬
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));

	//�o�b�N�o�b�t�@�\�̐�
	sd.BufferCount = 1;
	sd.BufferDesc.Width = _window->GetWidth();
	
	sd.BufferDesc.Height = _window->GetHeight();
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = _window->GetHandle();
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;

	D3D_FEATURE_LEVEL  FeatureLevel = D3D_FEATURE_LEVEL_11_0;


	
	
	return true;
}

void Direct3DManager::CreateRenderTargetView() {
	//�����_�[�^�[�Q�b�g�r���[�̍쐬
	//�o�b�N�o�b�t�@�̃|�C���^
	ID3D11Texture2D* backBuffer;

	//�X���b�v�`�F�[������o�b�N�o�b�t�@�̃|�C���^���擾
	_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);
	//�擾�����o�b�N�o�b�t�@�ɑ΂��郌���_�[�^�[�Q�b�g�r���[���쐬
	_device->CreateRenderTargetView(backBuffer, NULL, &_renderTargetView);
	//�o�b�N�o�b�t�@������i���j���ł͂Ȃ��j
	backBuffer->Release();
	//�����_�[�^�[�Q�b�g���p�C�v���C���Ɋ֘A�t����
	_deviceContext->OMSetRenderTargets(1, &_renderTargetView, NULL);
}

void Direct3DManager::CreateViewPort() {
	//�r���[�|�[�g�̐ݒ�
	D3D11_VIEWPORT vp;

	//��ʂ̉���
	vp.Width = _window->GetWidth();
	//��ʂ̏c��
	vp.Height = _window->GetHeight();
	//Z���̕�(Min��Max�̋����ōő�1�P�ʂ̌����ɂł���)
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;

	//��ʂ̍���̍��W
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	_deviceContext->RSSetViewports(1, &vp);
}

void Direct3DManager::Render(){

	// �N���A�F�쐬�@RGBA�̏�
	float ClearColor[4] = { 0,0,1,1 }; 

	//��ʃN���A
	_deviceContext->ClearRenderTargetView(_renderTargetView, ClearColor);    
	
	//��ʍX�V�i�o�b�N�o�b�t�@���t�����g�o�b�t�@�Ɂj
	_swapChain->Present(0, 0);
}