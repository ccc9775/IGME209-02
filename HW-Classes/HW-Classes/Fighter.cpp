#include "Fighter.h"
#include "Player.h"
#include <iostream>
using namespace std;


//declare default fighter constructor
Fighter::Fighter() : Player() {

	skill = (char*)"SHIELD BASH";

}

//declare parameterized fighter constructor
Fighter::Fighter(char* name, int strength, int speed, int intellect, char* skill) : Player(name, strength, speed, intellect) {

	Player(name, strength, speed, intellect);
	this->skill = skill;

}

//declare printFighter
void Fighter::printFighter(){

	printPlayer();
	cout<< "Skill: " << skill << endl;

}

//fighter destructor
Fighter::~Fighter() { std::cout << "Destroying fighter object" << endl; }