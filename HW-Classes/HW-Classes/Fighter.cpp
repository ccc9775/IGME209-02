#include "Fighter.h"
#include "Player.h"
#include <iostream>
using namespace std;



Fighter::Fighter() : Player() {

	skill = (char*)"SHIELD BASH";

}

Fighter::Fighter(char* name, int strength, int speed, int intellect, char* skill) : Player(name, strength, speed, intellect) {

	Player(name, strength, speed, intellect);
	this->skill = skill;

}

void Fighter::printFighter(){

	printPlayer();
	cout<< "Skill: " << skill << endl;

}