#include "Main.h"
#include"Quaternion.h"
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

	Quaternion one(1, 1, 1, 1);
	Quaternion two(3, 2, 4, 1);
	Quaternion newQ(0, 0, 0, 0);

	newQ = one * two;

	cout << newQ.w << " " << newQ.x << " " << newQ.y << " " << newQ.z << endl;

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