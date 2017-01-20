#include "DefaultScene.h"
#include "Input.h"
/////////////////////////////////
//シーン突入時に呼ばれる
/////////////////////////////////
void DefaultScene::OnEnter() {
	std::cout << ">-- \"default scene\" entered..." << std::endl;
}

/////////////////////////////////
//シーン再生中、毎フレーム呼ばれる
/////////////////////////////////
void DefaultScene::OnUpdate() {
	if (Input::IsKeyDown(0x39)) {
		std::cout << "スペースが押されたお" << std::endl;
	}
}

/////////////////////////////////
//シーン終了時に呼ばれる
/////////////////////////////////
void DefaultScene::OnExit() {
	std::cout << ">-- \"default scene\" exited..." << std::endl;
}
