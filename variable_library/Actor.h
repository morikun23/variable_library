#ifndef ACTOR
#define ACTOR

//////////////////////////////////////////////////////////////////
//�N���X���F Actor
//�쐬�� �F��R�@�� 
//�T�v  �F�I�u�W�F�ɕK�v�ȗv�f���܂Ƃ߂��N���X
//       �����b��Unity��GameObject
//�X�V  �FH29/01/04/ �N���X�̍쐬
//////////////////////////////////////////////////////////////////

#include<string>
#include"Transform.h"

namespace variableNS {

	class Actor {

	private:
		//���̃I�u�W�F�̖��O
		std::string name;
		Transform transform;

	public:
		Actor();
		Actor(std::string inName);
		~Actor();

	};
}

#endif