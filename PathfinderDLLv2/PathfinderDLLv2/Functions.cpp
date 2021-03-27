#include "pch.h"
#include <iostream>

using namespace std;

//Initialize variables
int startX;
int startY;
int endX;
int endY;
int xList[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int yList[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int currentPos = 0;
const int** mazeData;
int mazeWidth;
int mazeHeight;

//return names of team members when called
__declspec(dllexport) char* GetTeam() {
	return (char*)"Chase Call";
}

//save the width, height, and data of the maze when called
__declspec(dllexport) bool SetMaze(const int** data, int width, int height) {

	if (height <= 0 || width <= 0) {
		return false;
	}
	else {
		mazeData = data;
		mazeHeight = height;
		mazeWidth = width;
		return true;
	}
}

//set the height, width, and data form the DLL for the maze when called
__declspec(dllexport) int** GetMaze(int& width, int& height) {
	if (SetMaze == false) {
		return nullptr;
	}
	else {
		width = mazeWidth;
		height = mazeHeight;
		return (int**)mazeData;
	}
}

//return the next position when called
__declspec(dllexport) void GetNextPosition(int& xPos, int& yPos) {
	
	xPos = xList[currentPos];
	yPos = yList[currentPos];
	currentPos++;
	currentPos++;


}

//save the x and y start position when called
__declspec(dllexport) bool SetStart(int xPos, int yPos) {

	if (xPos < 0 || yPos < 0) {
		return false;
	}
	else {
		startX = xPos;
		startY = yPos;
		return true;
	}
}

//set the x and y position of the start when called
__declspec(dllexport) bool GetStart(int& xPos, int& yPos) {

	if (SetStart == false) {
		return false;
	}
	else {

		if (startX == NULL && startY == NULL) {
			xPos = -1;
			yPos = -1;
			return false;
		}
		else
		{
			xPos = startX;
			yPos = startY;
			return true;
		}
	}
}

//save the x and y end position when called
__declspec(dllexport) bool SetEnd(int xPos, int yPos) {

	if (xPos < 0 || yPos < 0) {
		return false;
	}
	else {
		endX = xPos;
		endY = yPos;
		return true;
	}
}

//set the x and y end position when called
__declspec(dllexport) bool GetEnd(int& xPos, int& yPos) {

	if (SetEnd == false) {
		return false;
	}
	else {
		if (endX == NULL && endY == NULL) {
			xPos = -1;
			yPos = -1;
			return false;
		}
		else
		{
			xPos = endX;
			yPos = endY;
			return true;
		}
	}
}

__declspec(dllexport) bool Restart() {

	currentPos = 0;
	return true;

}