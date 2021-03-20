#pragma once
class Player
{

public:
	char* getName() { return name; }
	Player();
	Player(char* name, int strength, int speed, int intellect);
	void printPlayer();
	~Player() { std::cout << "Destroying player object" << endl; }

	virtual void Attack(Player* enemy) {

		std::cout << this->name << " attacks " << enemy->name << endl;

	}

private:
	char* name;
	int strength;
	int speed;
	int intellect;


};



