#include "Main.h"
using namespace variableNS;
using namespace std;

Main::Main() {
	//���������܂�
	m_loaded = false;
	m_done = false;
	
	if (!m_loaded) {
		this->Load();
		m_loaded = true;
	}
	return;
}

Main::~Main() {
	//�I�����܂�
	if (!m_done) {
		this->UnLoad();
		m_done = true;
	}
	return;
}
///////////////////////////////////
//���[�h����
//�N�����ɂP�x�����Ă΂�܂�
///////////////////////////////////
void Main::Load(){
	//���[�h���܂�
	return;
}

//////////////////////////////////
//���t���[���X�V
//���t���[���Ăяo����܂�
//////////////////////////////////
void Main::Update(){
	return;
}

/////////////////////////////////
//�I������
//�I�����ɂP�x�����Ă΂�܂�
/////////////////////////////////
void Main::UnLoad() {
	return;
}