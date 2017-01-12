#include "Main.h"
#include"Quaternion.h"
using namespace variableNS;
using namespace std;

Main::Main() {
	//初期化します
	m_loaded = false;
	m_done = false;
	
	if (!m_loaded) {
		this->Load();
		m_loaded = true;
	}
	return;
}

Main::~Main() {
	//終了します
	if (!m_done) {
		this->UnLoad();
		m_done = true;
	}
	return;
}
///////////////////////////////////
//ロード処理
//起動時に１度だけ呼ばれます
///////////////////////////////////
void Main::Load(){
	//ロードします
	return;
}

//////////////////////////////////
//毎フレーム更新
//毎フレーム呼び出されます
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
//終了時に１度だけ呼ばれます
/////////////////////////////////
void Main::UnLoad() {
	return;
}