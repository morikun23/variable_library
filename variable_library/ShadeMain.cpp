//ヘッダーファイルのインクルード
#include <windows.h>
#include <d3dx10.h>
//ライブラリファイルのロード
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d10.lib")
#pragma comment(lib,"d3dx10.lib")
//定数
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
//グローバル変数
HWND g_hWnd=NULL;
ID3D10Device*			g_pDevice = NULL;
IDXGISwapChain*			g_pSwapChain = NULL;
ID3D10RenderTargetView* g_pRenderTargetView = NULL;
ID3D10Effect*           g_pEffect = NULL;
ID3D10EffectTechnique*  g_pTechnique = NULL;
ID3D10InputLayout*      g_pVertexLayout = NULL;
ID3D10Buffer*           g_pVertexBuffer = NULL;

ID3D10EffectMatrixVariable* g_pShaderWorld = NULL;//アプリ←→シェーダー架け橋　ワールド変換行列
ID3D10EffectMatrixVariable* g_pShaderWorldViewProjection = NULL;//アプリ←→シェーダー架け橋　ワールドから射影までの変換行列

D3DXVECTOR3 g_vLightDir(1,1,-1);//ライト方向
ID3D10EffectVectorVariable* g_pShaderLightDir=NULL;//アプリ←→シェーダー架け橋　ライト方向

//頂点用の構造体
struct SimpleVertex
{
    D3DXVECTOR3 Pos;  //オブジェクト座標
	D3DXVECTOR3 Normal; //法線　シェーディング（陰影計算）には法線は必須
};

//関数プロトタイプの宣言
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HRESULT InitD3d(HWND);
VOID Render();
//
//INT WINAPI WinMain( HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR szStr,INT iCmdShow)
//アプリケーションのエントリー関数
INT WINAPI WinMain( HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR szStr,INT iCmdShow)
{	
	// ウィンドウの初期化
	static WCHAR szAppName[] = L"D3D10 ポリゴン　陰影";
	WNDCLASSEX  wndclass;

	wndclass.cbSize		 = sizeof (wndclass);
	wndclass.style		    = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc    = WndProc;
	wndclass.cbClsExtra	 = 0;
	wndclass.cbWndExtra	= 0;
	wndclass.hInstance	   = hInst;
	wndclass.hIcon		   = LoadIcon (NULL,  IDI_APPLICATION);
	wndclass.hCursor		= LoadCursor (NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm	    = LoadIcon (NULL,IDI_ASTERISK);
	RegisterClassEx (&wndclass);

	g_hWnd = CreateWindow (szAppName,szAppName,WS_OVERLAPPEDWINDOW,   
				0,0,WINDOW_WIDTH,WINDOW_HEIGHT,NULL,NULL,hInst,NULL);   
    ShowWindow (g_hWnd,SW_SHOW);
    UpdateWindow (g_hWnd);
	// ダイレクト３Dの初期化関数を呼ぶ
	if(FAILED(InitD3d(g_hWnd)))
	{
		return 0;
	}
	// メッセージループ
	MSG msg;
    ZeroMemory( &msg, sizeof(msg) );
    while( msg.message!=WM_QUIT )
	{
		if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
	    {
			TranslateMessage( &msg );
		   DispatchMessage( &msg );
	    }
	    else
		{
			Render();
		}				
	}
	//アプリケーションを終了する時には、Direct3Dオブジェクトをリリースする
	g_pVertexBuffer->Release();
	g_pVertexLayout->Release();
	g_pEffect->Release();
	g_pSwapChain->Release();
	g_pRenderTargetView->Release();
	g_pDevice->Release();

	return (INT)msg.wParam;
}
//
//LRESULT CALLBACK WndProc(HWND hWnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
// ウィンドウプロシージャー関数
LRESULT CALLBACK WndProc(HWND hWnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
{	
	switch(iMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
		break;		
	}
	return DefWindowProc (hWnd, iMsg, wParam, lParam);	
}
//
//HRESULT InitD3d(HWND hWnd)
//ダイレクト3Dの初期化
HRESULT InitD3d(HWND hWnd)
{
	HRESULT hr=NULL;
	// デバイスとスワップチェーンの作成
	DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory( &sd, sizeof(sd) );
    sd.BufferCount = 1;
    sd.BufferDesc.Width = WINDOW_WIDTH;
    sd.BufferDesc.Height = WINDOW_HEIGHT;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = g_hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;

    if( FAILED( D3D10CreateDeviceAndSwapChain( NULL, D3D10_DRIVER_TYPE_HARDWARE, NULL,
                     0, D3D10_SDK_VERSION, &sd, &g_pSwapChain, &g_pDevice ) ) )
    {
        return FALSE;
    }
	//レンダーターゲットビューの作成
	ID3D10Texture2D *pBackBuffer;
    g_pSwapChain->GetBuffer( 0, __uuidof( ID3D10Texture2D ),(LPVOID*)&pBackBuffer);    
    g_pDevice->CreateRenderTargetView( pBackBuffer, NULL, &g_pRenderTargetView );
    pBackBuffer->Release();
	g_pDevice->OMSetRenderTargets(1, &g_pRenderTargetView,NULL);

	//ビューポートの設定
	D3D10_VIEWPORT vp;
    vp.Width = WINDOW_WIDTH;
    vp.Height = WINDOW_HEIGHT;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    g_pDevice->RSSetViewports( 1, &vp );

	//エフェクトを作成
	hr=D3DX10CreateEffectFromFile( L"SimpleShade.fx", NULL, NULL, "fx_4_0", 
		D3D10_SHADER_ENABLE_STRICTNESS | D3D10_SHADER_DEBUG, 0,
                                         g_pDevice, NULL, NULL, &g_pEffect, NULL, NULL );

	if(FAILED(hr))
	{
		MessageBox(0,L"fail",L"",MB_OK);
		//return E_FAIL;
	}

	//テクニックを得る
	g_pTechnique = g_pEffect->GetTechniqueByName( "SimpleShade" );

	//頂点インプットレイアウトを定義	
	D3D10_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0 }, 
		{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0 }, 

	};
	UINT numElements = sizeof(layout)/sizeof(layout[0]);

	//頂点インプットレイアウトを作成
	D3D10_PASS_DESC PassDesc;
	g_pTechnique->GetPassByIndex( 0 )->GetDesc( &PassDesc );
	if( FAILED( g_pDevice->CreateInputLayout( layout, numElements, PassDesc.pIAInputSignature, 
			PassDesc.IAInputSignatureSize, &g_pVertexLayout ) ) )
		return FALSE;
	//頂点インプットレイアウトをセット
	g_pDevice->IASetInputLayout( g_pVertexLayout );


	//バーテックスバッファー作成

	SimpleVertex vertices[] =
	{
		D3DXVECTOR3( -0.5,-0.5,0),D3DXVECTOR3(0,0,-1),//頂点1,
		D3DXVECTOR3(-0.5,0.5,0), D3DXVECTOR3(0,0,-1),//頂点2
		D3DXVECTOR3( 0.5,-0.5,0),D3DXVECTOR3(0,0,-1),  //頂点3
		D3DXVECTOR3(  0.5,0.5,0),D3DXVECTOR3(0,0,-1), //頂点4	
	};

	D3D10_BUFFER_DESC bd;
	bd.Usage = D3D10_USAGE_DEFAULT;
	bd.ByteWidth = sizeof( SimpleVertex ) * 4;
	bd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;
	D3D10_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = vertices;
	if( FAILED( g_pDevice->CreateBuffer( &bd, &InitData, &g_pVertexBuffer ) ) )
		return FALSE;

	//バーテックスバッファーをセット
	UINT stride = sizeof( SimpleVertex );
	UINT offset = 0;
	g_pDevice->IASetVertexBuffers( 0, 1, &g_pVertexBuffer, &stride, &offset );

	//プリミティブ・トポロジーをセット
	g_pDevice->IASetPrimitiveTopology( D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP );

	//ラスタライズ設定
	D3D10_RASTERIZER_DESC rdc;
	ZeroMemory(&rdc,sizeof(rdc));
	rdc.CullMode=D3D10_CULL_NONE;
	rdc.FillMode=D3D10_FILL_SOLID;
	
	ID3D10RasterizerState* pIr=NULL;
	g_pDevice->CreateRasterizerState(&rdc,&pIr);
	g_pDevice->RSSetState(pIr);
	
	return S_OK;
}
//
//VOID Render()
//レンダリングする関数
VOID Render()
{
	D3DXMATRIX mWorld;
	D3DXMATRIX mView;
	D3DXMATRIX mProj;
	//ワールドトランスフォーム（絶対座標変換）
	//回転の計算は(　&mWorld, timeGetTime()/ ○.○f)にする
	D3DXMatrixRotationY( &mWorld, 0.0f );	
	// ビュートランスフォーム（視点座標変換）
	D3DXVECTOR3 vEyePt( 0.0f, 0.0f,-2.0f ); //カメラ（視点）位置
	D3DXVECTOR3 vLookatPt( 0.0f, 0.0f, 0.0f );//注視位置
	D3DXVECTOR3 vUpVec( 0.0f, 1.0f, 0.0f );//上方位置
	D3DXMatrixLookAtLH( &mView, &vEyePt, &vLookatPt, &vUpVec );
	// プロジェクショントランスフォーム（射影変換）
	D3DXMatrixPerspectiveFovLH( &mProj, D3DX_PI/4, (FLOAT)WINDOW_WIDTH/(FLOAT)WINDOW_HEIGHT, 0.1f, 10.0f );	

	//ワールド行列をシェーダーに渡す
	g_pShaderWorld=g_pEffect->GetVariableByName("g_mW")->AsMatrix();
	g_pShaderWorld->SetMatrix((float*)&(mWorld));
	//ワールド・ビュー・プロジェクション行列をシェーダーに渡す
	g_pShaderWorldViewProjection=g_pEffect->GetVariableByName("g_mWVP")->AsMatrix();
	g_pShaderWorldViewProjection->SetMatrix((float*)&(mWorld*mView*mProj));
	//ライトの方向をシェーダーに渡す
	g_pShaderLightDir=g_pEffect->GetVariableByName("g_vLightDir")->AsVector();
	D3DXVec3Normalize(&g_vLightDir,&g_vLightDir);
	g_pShaderLightDir->SetFloatVector((float*)g_vLightDir);
	
	float ClearColor[4] = {1,1,1,1 }; // クリア色作成　RGBAの順
    g_pDevice->ClearRenderTargetView( g_pRenderTargetView, ClearColor );//画面クリア 

	//プリミティブをレンダリング
	D3D10_TECHNIQUE_DESC dc;
    g_pTechnique->GetDesc( &dc );
    for( UINT p = 0; p < dc.Passes; ++p )
    {
        g_pTechnique->GetPassByIndex( p )->Apply( 0 );
        g_pDevice->Draw( 4, 0 );
    }

	g_pSwapChain->Present( 0, 0 );//画面更新（バックバッファをフロントバッファに）	
}