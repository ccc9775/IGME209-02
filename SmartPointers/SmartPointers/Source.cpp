#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include<iostream>
#include<memory>
#include "gameLevel.h"
using namespace std;


void createSmartLevel() {

	shared_ptr<gameLevel> base(new gameLevel());

}

void createNormLevel() {

	gameLevel* newLevel = new gameLevel();

}


int main(){



	createSmartLevel();
	_CrtDumpMemoryLeaks();
	

	createNormLevel();
	_CrtDumpMemoryLeaks();

	return 0;
}