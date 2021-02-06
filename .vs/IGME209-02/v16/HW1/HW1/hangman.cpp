#include <iostream>
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

void showSolved(char word[], char guesses[]) {


}