#include"Random.h"
using namespace variableNS;
using namespace std;

//Value�̏���
float Random::Value() {

	//�񌈒�_�I�ȗ��������G���W���ɂ���āArd�ɗ������Ăяo���B
	random_device randomDevice;
	
	//��L�݂̂��Ɩ���n�[�h�E�F�A�G���g���s�[�\�[�X�����W���邽�߁A���s���x���x��
	//�����V�[�h���璷�����̗�����������ɐ������郁���Z���k�E�c�C�X�^�[���Ăяo���܂��B
	mt19937 mersenneTwister(randomDevice());

	//1 �`�@9�͈̔͂Ɉ�l�ɕ��z���鐮���̗����𐶐��B
	uniform_int_distribution<int> range(0,10);

	//0.1�������邱�Ƃŏ����_���o���߂�l�Ƃ��ēn��
	return range(mersenneTwister) * 0.1f;

}

//Range�̏���
int   Random::Range(int min, int max) {

	random_device randomDevice;
	mt19937 mersenneTwister(randomDevice());

	//2�͈̔͂Ɉ�l�ɕ��z����int�̗����𐶐��B
	uniform_int_distribution<int> range(min, max);

	//�������������̐�����߂�l�Ƃ��ēn��
	return range(mersenneTwister);
}

//Range�̃I�[�o�[���[�h�̏���
float Random::Range(float min, float max) {

	//�����_�ɂ��邽�߂ɂP�x�A�l���i�[���邽�߂̕ϐ�
	float dimension;

	random_device randomDevice;
	mt19937 mersenneTwister(randomDevice());

	//2�͈̔͂Ɉ�l�ɕ��z����float�̗����𐶐��B
	uniform_real_distribution<float> range(min, max);

	//�����_��Q�ʂɂ��邽�߂̕ϊ���1�x10�{���܂��B
	dimension = range(mersenneTwister) * 10;

	//���̂��Ƃ�float����int�ɕϊ�
	dimension = (float)(int)(dimension);

	//int�ɕϊ������l��0.1�������邱�Ƃŏ����_���o���߂�l�Ƃ��ēn��
	return dimension * 0.1f;

} 