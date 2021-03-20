#pragma once
#include <iostream>
using namespace std;


class Player
{

public:
	char* getName() { return name; }
	Player();
	Player(char* name, int strength, int speed, int intellect);
	void printPlayer();
	~Player();

	virtual void Attack(Player* enemy) {

		std::cout << this->name << " attacks " << enemy->name << endl;

	}

private:
	char* name;
	int strength;
	int speed;
	int intellect;


};



