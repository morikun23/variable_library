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
	// デバイスとスワップチェーンの作成
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));

	//バックバッファ―の数
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
	//レンダーターゲットビューの作成
	//バックバッファのポインタ
	ID3D11Texture2D* backBuffer;

	//スワップチェーンからバックバッファのポインタを取得
	_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);
	//取得したバックバッファに対するレンダーターゲットビューを作成
	_device->CreateRenderTargetView(backBuffer, NULL, &_renderTargetView);
	//バックバッファを解放（※破棄ではない）
	backBuffer->Release();
	//レンダーターゲットをパイプラインに関連付ける
	_deviceContext->OMSetRenderTargets(1, &_renderTargetView, NULL);
}

void Direct3DManager::CreateViewPort() {
	//ビューポートの設定
	D3D11_VIEWPORT vp;

	//画面の横幅
	vp.Width = _window->GetWidth();
	//画面の縦幅
	vp.Height = _window->GetHeight();
	//Z軸の幅(MinとMaxの距離で最大1単位の厚さにできる)
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;

	//画面の左上の座標
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	_deviceContext->RSSetViewports(1, &vp);
}

void Direct3DManager::Render(){

	// クリア色作成　RGBAの順
	float ClearColor[4] = { 0,0,1,1 }; 

	//画面クリア
	_deviceContext->ClearRenderTargetView(_renderTargetView, ClearColor);    
	
	//画面更新（バックバッファをフロントバッファに）
	_swapChain->Present(0, 0);
}