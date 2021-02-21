// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	Monster *boss = new Monster();
	Player *pOne = new Player();
	//MovableObject *boss = new Monster();
	//MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	// add code here
	
	//1. the initial problem with the code is that the fake monster pointer is going to the same address as
	//pOne, so when pOne and fakeMonster are deleted, they are attempting to delete the same address twice


	cout << &boss << endl;
	cout << &pOne << endl;
	cout << &fakeMonster << endl;

	boss->xPos = 3;
	boss->yPos = 10;
	pOne->xPos = 1;
	pOne->yPos = 1;
	fakeMonster->xPos = 5;
	fakeMonster->yPos = 5;

	boss->PrintPos();
	pOne->PrintPos();
	fakeMonster->PrintPos();

	//6. When switching the variables to the base class, the pOne variable does not run ~Player
	//becasue it does not have acces to that code black as the base MoveableObject class

	delete boss;
	delete pOne;
	//delete fakeMonster;

	_getch();
    return 0;
}

