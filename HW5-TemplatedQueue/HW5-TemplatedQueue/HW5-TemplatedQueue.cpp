// HW5-TemplatedQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

struct Player {
    string name;
    int health;
}one, two, three;

int main()
{
    
    Queue<int> intTest;
    Queue<string> stringTest;
    Queue<Player> playerTest;

   /* cout << intTest.IsEmpty() << endl;
    intTest.Push(27);
    intTest.Print();
    intTest.Push(13);
    intTest.Push(1000);
    intTest.Print();
    intTest.Pop();
    intTest.Print();
    cout << intTest.IsEmpty() << endl;
    */

    /*stringTest.IsEmpty();
    stringTest.Print();
    stringTest.Push("cat");
    stringTest.Push("hat");
    stringTest.Push("bat");
    stringTest.Push("rat");
    stringTest.Print();
    stringTest.Pop();
    stringTest.Pop();
    stringTest.Print();
    */

    one.health = 30;
    one.name = "Jedd";
    two.health = 100;
    two.name = "Viktor";
    three.health = 60;
    three.name = "Salazar";

    playerTest.Push(one);
    playerTest.Push(two);
    playerTest.Pop();
    playerTest.Push(three);
   // playerTest.Print();


}


