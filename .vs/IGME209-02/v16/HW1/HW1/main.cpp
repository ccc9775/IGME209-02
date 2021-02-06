// HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include "hangman.h"
using namespace std;



int main()
{
    //initialize variables
    char guessedWord[100] = "trash";
    char correctLetters[6] = "_____";
    char incorrectLetters[100] = {};
    char guessLetter[2];

    //introduce the game
    cout << "Let's play some Hangman!" << endl << endl;

    //loop through this code until the user guesses the word, or runs out of guesses
    while (strcmp(guessedWord, correctLetters) != 0 && strlen(incorrectLetters) < 6 )
    {
        
        //shows instructions for the game, and the gallows
        cout << "Type a letter to guess and press enter: " << endl;
        showGallows(strlen(incorrectLetters));

        //shows the correctly guessed letters in order
        cout << "Word so far: " << correctLetters << endl;

        //takes user input for a guess
        cin >> guessLetter;

        //will add correct letters to the array and incorrect letters to an array. checks for repeat wrong guesses
        showSolved(correctLetters, guessLetter, incorrectLetters);


    }

    //if the user correctly guessed the word, tell them they have won
    if (strcmp(guessedWord, correctLetters) == 0) {

        cout << "You have won! the word was in fact " << guessedWord << endl;

    }
    //if the user ran out of guesses, tell them they have lost, and give them the word
    else {

        cout << "You have lost :( the word was " << guessedWord << endl;

    }

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
