#include "Main.h"
#include"Quaternion.h"
using namespace variableNS;
using namespace std;

Main::Main() {
	//初期化します
	m_loaded = false;
	m_done = false;
	this->Load();
	return;
}

Main::~Main() {
	this->UnLoad();
	return;
}
///////////////////////////////////
//ロード処理
///////////////////////////////////
void Main::Load(){
	//ロードします
	if (m_loaded) return;
	m_loaded = true;
	return;
}

//////////////////////////////////
//毎フレーム更新
//////////////////////////////////
void Main::Update(){

	Quaternion one(1, 1, 1, 1);
	Quaternion two(3, 2, 4, 1);
	Quaternion newQ(0, 0, 0, 0);

	newQ = one * two;

	cout << newQ.w << " " << newQ.x << " " << newQ.y << " " << newQ.z << endl;

	return;
}

/////////////////////////////////
//終了処理
/////////////////////////////////
void Main::UnLoad() {
	//終了処理
	if (m_done) return;
	m_done = true;
	return;
}