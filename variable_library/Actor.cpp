#include"Actor.h"
using namespace variableNS;

//コンストラクタ、デストラクタ
Actor::Actor() {
	name = "GameObject";
}

Actor::Actor(std::string inName) {
	name = inName;
}

Actor::~Actor() {

}