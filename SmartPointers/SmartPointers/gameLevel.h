#pragma once
class gameLevel
{

public:
	gameLevel();
	gameLevel(int num, char* name, char* enemies[], char* treasures[]);
	~gameLevel();

private:

	int levelNum;
	char* levelName;
	char* treasure[10];
	char* enemies[10];



};

