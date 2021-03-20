// HW-Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Fighter.h"
using namespace std;

int main()
{
    //say the name of the battle
    cout << "Welcome to the Tournament of Champions!" << endl;

    //create the ten battlers
    Player* battlers[10];

    //create a player or fighter object for each battler
    for (int i = 0; i < 10; i++) {

        int playerType = (rand() % 2 + 1);

        if (playerType == 1) {
            battlers[i] = new Player((char*)"player ", 10, 10, 10);
        }
        else if (playerType == 2) {
            battlers[i] = new Fighter((char*)"player ", 10, 10, 10, (char*)"Big Hit");
        }

    }

    
    //loop through each battler
    for (int i = 1; i < 10; i++) {
        battlers[0]->Attack(battlers[i]);
        battlers[i] = nullptr;
    }
    
    //declare the winner
    cout << battlers[0]->getName() << " is the winner!" << endl;
    //delete the final battler
    delete battlers[0];


}


