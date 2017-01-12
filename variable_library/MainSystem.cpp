#include"MainSystem.h"

void MainSystem::Load() {
	//デバッグ用コンソールの表示
	Console::Instance().Open();
	std::cout << ">-- System start up" << std::endl;
	
	//ウィンドウの生成
	window = new MainWindow();
	
	//Direct3Dの初期化
	//※今後、森田が実装予定

	//DirectInputの初期化
	//今後、小野のクラスから一部統合予定

	//DirectSoundの初期化
	//今後、甲斐のクラスから統合予定

	//シーンの再生
	SceneManager::Instance().ScenePlay(new DefaultScene());
}

void MainSystem::Update() {
	//現在再生中のシーンを更新
	SceneManager::Instance().SceneUpdate();
}

void MainSystem::UnLoad() {
	//シーンの終了
	SceneManager::Instance().SceneEnd();
	delete window;
	Console::Instance().Close();
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {
	
	MainSystem system;

	///////////////////////////////
	//システム起動
	//各APIなどを初期化
	/////////////-//////////////////
	system.Load();

	///////////////////////////////
	//ゲーム再生
	//メッセージループによって
	//毎フレーム更新される
	///////////////////////////////
	MSG msg;

	while (true) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			system.Update();
			if (msg.message == WM_QUIT) break;
		}
	}

	//////////////////////////////
	//システム終了
	//各APIなどを解放する
	//////////////////////////////
	system.UnLoad();

	return 0;
}
