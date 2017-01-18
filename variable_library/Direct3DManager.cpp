#include "Direct3DManager.h"

bool Direct3DManager::Init() {
	// デバイスとスワップチェーンの作成
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = 640;
	sd.BufferDesc.Height = 480;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = m_handle;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;

	D3D_FEATURE_LEVEL  FeatureLevel = D3D_FEATURE_LEVEL_11_0;


	if (FAILED(D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_REFERENCE, NULL, 0,
		&FeatureLevel, 1,
		D3D11_SDK_VERSION, &sd, &m_swapChain, &m_device, NULL, &m_deviceContext)))
	{
		return false;
	}
	//レンダーターゲットビューの作成
	ID3D11Texture2D *pBackBuffer;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	m_device->CreateRenderTargetView(pBackBuffer, NULL, &m_renderTargetView);
	pBackBuffer->Release();
	m_deviceContext->OMSetRenderTargets(1, &m_renderTargetView, NULL);

	//ビューポートの設定
	D3D11_VIEWPORT vp;
	vp.Width = 400;
	vp.Height = 300;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	m_deviceContext->RSSetViewports(1, &vp);


	return true;
}

void Direct3DManager::Render(){
	float ClearColor[4] = { 0,0,1,1 }; // クリア色作成　RGBAの順
	m_deviceContext->ClearRenderTargetView(m_renderTargetView, ClearColor);//画面クリア    
	m_swapChain->Present(0, 0);//画面更新（バックバッファをフロントバッファに）	
}