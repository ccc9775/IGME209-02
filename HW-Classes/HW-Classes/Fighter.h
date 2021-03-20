#pragma once
#include "Player.h"
class Fighter :
    public Player
{

    public:
        Fighter();
        Fighter(char* name, int strength, int speed, int intellect, char* skill);
        void printFighter();
        ~Fighter() { std::cout << "Destroying fighter object" << endl; }

    private: 
        char* skill;
};

