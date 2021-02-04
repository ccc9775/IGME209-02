// PE4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    //variable for the counting of the i's in the string
    int numI = 0;

    //add the first part of the string and print its length to the console
    char longWord[100] = "supercalifraglistic";
    cout << strlen(longWord) << endl;

    char secondWord[100] = "expialidocious";
    //add the second part of the word to the longWord variable, then print it to the console
    strcat_s(longWord, secondWord);
    cout << longWord << endl;

    //for each character in the string, check to see if it is an I
    for (char letter : longWord) {

        //if the character is an I, add 1 to the variable
        if (letter == 'i') {
            numI++;
        }

       /* if (strchr(longWord, 'i')) {
            numI++;
        }*/

    }

    //prints the counted number of i's to the console
    cout << numI << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
