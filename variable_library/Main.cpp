#include "Main.h"
#include"Quaternion.h"
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

	Quaternion one(1, 1, 1, 1);
	Quaternion two(3, 2, 4, 1);
	Quaternion newQ(0, 0, 0, 0);

	newQ = one * two;

	cout << newQ.w << " " << newQ.x << " " << newQ.y << " " << newQ.z << endl;

	return;
}

/////////////////////////////////
//�I������
//�I�����ɂP�x�����Ă΂�܂�
/////////////////////////////////
void Main::UnLoad() {
	return;
}