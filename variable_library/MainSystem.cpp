#include"MainSystem.h"

void MainSystem::Load() {
	
	//デバッグ用コンソールの表示
	Console::Instance().Open();
	std::cout << ">-- System start up" << std::endl;
	
	//ウィンドウの生成
	_window = new MainWindow(_hInstance);
	
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
	delete _window;
	Console::Instance().Close();
}