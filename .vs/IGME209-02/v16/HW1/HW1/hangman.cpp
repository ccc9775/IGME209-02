#include <iostream>
#include <cstring>
#include "hangman.h"
using namespace std;


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

void showSolved(char word[], char guesses[], char badLetters[]) {


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
		else
		{
			
			if (strchr(badLetters, guesses[0])) {

				cout << endl << "You have already checked for " << guesses[0] << ", and it is still wrong" << endl;
			}
			else
			{
				cout << endl << guesses[0] << " is not in the word" << endl;

				int length = strlen(badLetters);

				badLetters[length] = guesses[0];
			}

			cout << "Wrong Letters: " << badLetters << endl << endl;
		}

}