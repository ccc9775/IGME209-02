// HW-Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Fighter.h"
using namespace std;

int main()
{
    //calling the class in main
    Player();

    //initializing player objects
    Player firstPlayer;
    Player secondPlayer((char*)"Named", 7, 3, 12);
    Player* thirdPlayer = new Player();
    Player* fourthPlayer = new Player((char*)"Unnamed", 15, 8, 2);

    Fighter firstFighter;
    Fighter* secondFighter = new Fighter((char*)"Fred", 20, 15, 3, (char*)"Riposte");

    //printing player objects to the console
    firstPlayer.printPlayer();
    secondPlayer.printPlayer();
    thirdPlayer->printPlayer();
    fourthPlayer->printPlayer();
    firstFighter.printFighter();
    secondFighter->printFighter();

    //deleting players from heap
    delete thirdPlayer;
    delete fourthPlayer;
    delete secondFighter;
}


