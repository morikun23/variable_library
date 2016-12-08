#include "Main.h"
using namespace mainNS;
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

void Main::Load(){
	//ロードします
	if (m_loaded) return;
	m_loaded = true;
	return;
}

void Main::Update(){
	//毎フレーム更新
	cout << "s";
	return;
}

void Main::UnLoad() {
	//終了処理
	if (m_done) return;
	m_done = true;
	return;
}