#include "Main.h"
using namespace mainNS;
using namespace std;

Main::Main() {
	//���������܂�
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
	//���[�h���܂�
	if (m_loaded) return;
	m_loaded = true;
	return;
}

void Main::Update(){
	//���t���[���X�V
	cout << "s";
	return;
}

void Main::UnLoad() {
	//�I������
	if (m_done) return;
	m_done = true;
	return;
}