#include "Resources.h"

using namespace variableNS;
using namespace std;


//char Resources::text[256];

/*
void *Resources::Load(char pass[]) {

	FILE *fp = Resources::FilePointLoad(pass);


	//txt�g���q�̃t�@�C����ǂ݂���Ŋi�[
	if (strstr(pass, ".txt") != NULL) {
		fgets(Resources::text, 256, fp);//�@�e�L�X�g�������o��text�Ɋi�[����
	}
	//png�g���q�̃t�@�C�����i�[
	else if (strstr(pass, ".png") != NULL) {

	}
	//jpng�Awav�@���̑��i�[����g���q�ɉ��������̂�ǉ����Ă����\��ł�

	return 0;

}

FILE *Resources::FilePointLoad(char pass[]) {

	FILE *fp;

	//�p�X������point��ǂݍ���
	fopen_s(&fp, pass, "r+");

	return fp;
}
*/

//template���g�p����version������
template<>
string Resources<string>::Load(char arg_pass[]) {
	/*
	FILE *fp;
	string stringBuffer;
	string a = pass;
	a = "c:root/Resources/" + a;
	cout << a << "\n";
	char cary[80];
	strcpy_s(cary, a.c_str());
	
	//strcpy_s(cary,a.c_str());

	//cout << cary;
	//"c:root/Resources/"	

	//�p�X������point��ǂݍ���
	fopen_s(&fp,a.c_str(), "r");
	
	if (&fp == NULL) {
		cout << "Error \n";
		return "0";
	}

	cout <<  "FILEPASS_OK... \n";
	cout << &fp << "\n";
	
	char charBuffer[256];
	fgets(charBuffer, 256, fp);

	stringBuffer = string(charBuffer);
	fclose(fp);

	return stringBuffer;

	return "0";*/

	string pass = "c:root/Reources/" + (string)arg_pass;

	std::ifstream ifs(pass);
	if (ifs.fail())
	{
		std::cerr << "ERROR" << std::endl;
		return "0";
	}

	std::istreambuf_iterator<char> it(ifs);
	std::istreambuf_iterator<char> last;
	std::string str(it, last);

	return str;
}
template<>
int Resources<int>::Load(char arg_pass[]) {

	return 10;
}

template<>
string Resources<string>::Loads(char arg_pass[]) {


	return "0";
}










