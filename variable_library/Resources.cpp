#include "Resources.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace variableNS;
using namespace std;


char Resources::text[256];

void *Resources::Load(char pass[]) {

	FILE *fp;

	//�p�X������point��ǂݍ���
	fopen_s(&fp, pass, "r");

	//txt�g���q�̃t�@�C����ǂ݂���Ŋi�[
	if (strstr(pass, ".txt") != NULL) {
		fgets(Resources::text, 256, fp);//�@�e�L�X�g�������o��text�Ɋi�[����
	}
	//png�g���q�̃t�@�C�����i�[
	else if (strstr(pass, ".png") != NULL) {

	}
	//jpng�Awav�@���̑��i�[����g���q�ɉ��������̂�ǉ����Ă����\��ł�
}

FILE *Resources::FilePointLoad(char pass[]) {

	FILE *fp;

	//�p�X������point��ǂݍ���
	fopen_s(&fp, pass, "r");

	return fp;
}

//template���g�p����version������
/*template<template T>
T *Resources::Load(char pass[]) {

	FILE *fp;
	//vector<char> text(256);
	char text[256];

	fopen_s(&fp, pass, "r");

	if (strstr(pass, "txt") != NULL) {

		fgets(text, 256, fp);

		return *text;
	}

	//return text;
}
*/


bool Resources::Close(FILE *fp) {

	//Error����
	if (fp == NULL) {
		return false;
	}
	//filepoint�����
	fclose(fp);

	return true;
}





