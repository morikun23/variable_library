#include "Resources.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace variableNS;
using namespace std;


char Resources::text[256];

FILE  *Resources::Load(char pass[]) {

	FILE *fp;

	//パスを入れてpointを読み込む
	fopen_s(&fp, pass, "r");


	fgets(Resources::text, 256, fp);//　テキストをメンバのtextに格納する


	return fp;

}
//templateを使用したversion未完成
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

	//Error処理
	if (fp == NULL) {
		return true;
	}
	//fileを閉じる
	fclose(fp);

	return false;
}





