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

    //test for integers in the queue
    cout << "Integers" << endl;
    cout << intTest.IsEmpty() << endl;
    intTest.Push(27);
    cout << "first int test (should print 27):" << endl;
    intTest.Print();
    intTest.Push(13);
    intTest.Push(1000);
    intTest.PushFirst(1234);
    cout << "second int test (should print 1234, 27, 13, 1000):" << endl;
    intTest.Print();
    intTest.Pop();
    cout << "third int test (should print 13, 1000):" << endl;
    intTest.Print();
    cout << intTest.IsEmpty() << endl;
    
    cout << "Strings" << endl;
    stringTest.IsEmpty();
    cout << "first string test (should print an error message):" << endl;
    stringTest.Print();
    stringTest.Push("cat");
    stringTest.Push("hat");
    stringTest.Push("bat");
    stringTest.Push("rat");
    cout << "second string test (should print cat, hat, bat, rat):" << endl;
    stringTest.Print();
    stringTest.Pop();
    stringTest.PopLast();
    cout << "third string test (should print hat, bat):" << endl;
    stringTest.Print();


    //test with a custom player struct (was told not to worry about printing for this one)
    one.health = 30;
    one.name = "Jedd";
    two.health = 100;
    two.name = "Viktor";
    three.health = 60;
    three.name = "Salazar";

    cout << "Players" << endl;
    playerTest.Push(one);
    playerTest.Push(two);
    playerTest.Pop();
    playerTest.Push(three);


}


