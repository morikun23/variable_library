#include "Main.h"
using namespace variableNS;
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
///////////////////////////////////
//���[�h����
///////////////////////////////////
void Main::Load(){
	//���[�h���܂�
	if (m_loaded) return;
	m_loaded = true;
	return;
}

//////////////////////////////////
//���t���[���X�V
//////////////////////////////////
void Main::Update(){
	return;
}

/////////////////////////////////
//�I������
/////////////////////////////////
void Main::UnLoad() {
	//�I������
	if (m_done) return;
	m_done = true;
	return;
}