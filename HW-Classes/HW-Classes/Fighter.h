#pragma once
#include "Player.h"
class Fighter :
    public Player
{

    public:
        Fighter();
        Fighter(char* name, int strength, int speed, int intellect, char* skill);
        void printFighter();
        ~Fighter();
        void Attack(Player* enemy) override {

            cout << Player().getName() << " attacks " << enemy->getName() << " with a " << this->skill << endl;

        }

    private: 
        char* skill;
};

