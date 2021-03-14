#include "Player.h"
#include <iostream>
using namespace std;

//default constructor for player objects
Player::Player() {

	name = (char*)"UNKNOWN";
	strength = 10;
	speed = 10;
	intellect = 10;
}

//parameterized constructor for player objects
Player::Player(char* name, int strength, int speed, int intellect) {

	this->name = name;
	this->strength = strength;
	this->speed = speed;
	this->intellect = intellect;

}

//method to print player to the console
void Player::printPlayer() {

	cout << "Player Name: " << name << endl;
	cout << "Strength: " << strength << endl;
	cout << "Speed: " << speed << endl;
	cout << "Intellect: " << intellect << endl;

}