// PE-Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"

int main()
{
    //calling the class in main
    Player();

    //initializing player objects
    Player firstPlayer;
    Player secondPlayer((char*)"Named", 7, 3, 12);
    Player* thirdPlayer = new Player();
    Player* fourthPlayer = new Player((char*)"Unnamed", 15, 8, 2);

    //printing player objects to the console
    firstPlayer.printPlayer();
    secondPlayer.printPlayer();
    thirdPlayer->printPlayer();
    fourthPlayer->printPlayer();

    //deleting players from heap
    delete thirdPlayer;
    delete fourthPlayer;
}


