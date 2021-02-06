#include <iostream>
#include <cstring>
#include "hangman.h"
using namespace std;


//each time the user fails a guess, a body part is added to the gallows and printed out
void showGallows(int guessLimit) {

	if (guessLimit == 1) {
		cout << "		______X___" << endl;
		cout << "		|     |   " << endl;
		cout << "		|     O   " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
	}
	else if (guessLimit == 2) {
		cout << "		______X___" << endl;
		cout << "		|     |   " << endl;
		cout << "		|     O   " << endl;
		cout << "		|     |   " << endl;
		cout << "		|     |   " << endl;
		cout << "		|     |   " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
	}
	else if (guessLimit == 3) {
		cout << "		______X___" << endl;
		cout << "		|     |   " << endl;
		cout << "		|     O   " << endl;
		cout << "		|    /|   " << endl;
		cout << "		|     |   " << endl;
		cout << "		|     |   " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
	}
	else if (guessLimit == 4) {
		cout << "		______X___" << endl;
		cout << "		|     |   " << endl;
		cout << "		|     O   " << endl;
		cout << "		|    /|\\  " << endl;
		cout << "		|     |   " << endl;
		cout << "		|     |   " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
	}
	else if (guessLimit == 5) {
		cout << "		______X___" << endl;
		cout << "		|     |   " << endl;
		cout << "		|     O   " << endl;
		cout << "		|    /|\\  " << endl;
		cout << "		|     |   " << endl;
		cout << "		|     |   " << endl;
		cout << "		|      \\  " << endl;
		cout << "		|         " << endl;
	}
	else if (guessLimit == 6) {
		cout << "		______X___" << endl;
		cout << "		|     |   " << endl;
		cout << "		|     O   " << endl;
		cout << "		|    /|\\  " << endl;
		cout << "		|     |   " << endl;
		cout << "		|     |   " << endl;
		cout << "		|    / \\  " << endl;
		cout << "		|         " << endl;
	}
	else {
		cout << "		______X___" << endl;
		cout << "		|     |   " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
		cout << "		|         " << endl;
	}
}

//checks through the correct letters of the word, and prints it to the correct array
void showSolved(char word[], char guesses[], char badLetters[]) {

		
	//if the user guesses the right letter, add it to the array and don't add a body part to the gallows
		if (guesses[0] == 't') {

			word[0] = 't';

		}
		else if (guesses[0] == 'r') {

		word[1] = 'r';

		}
		else if (guesses[0] == 'a') {

		word[2] = 'a';

		}
		else if (guesses[0] == 's') {

		word[3] = 's';

		}
		else if (guesses[0] == 'h') {

		word[4] = 'h';

		}
		//if the user did not guess the correct letter
		else
		{
			//if they have already guessed the letter, let them know and don't add to the gallows 
			if (strchr(badLetters, guesses[0])) {

				cout << endl << "You have already checked for " << guesses[0] << ", and it is still wrong" << endl;
			}
			//if they haven't guessed the letter before, tell them it isn't in the word, and add to the gallows and incorrect letter array
			else
			{
				cout << endl << guesses[0] << " is not in the word" << endl;

				int length = strlen(badLetters);

				badLetters[length] = guesses[0];
			}

			//print out the incorrectly guessed letters
			cout << "Wrong Letters: " << badLetters << endl << endl;
		}

}