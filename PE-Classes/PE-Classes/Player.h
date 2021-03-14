#pragma once
class Player
{

public:
	Player();
	Player(char* name, int strength, int speed, int intellect);
	void printPlayer();


private:
	char* name;
	int strength;
	int speed;
	int intellect;


};

