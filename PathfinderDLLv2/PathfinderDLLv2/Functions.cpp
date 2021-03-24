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
int currentX = xList[0];
int currentY = yList[0];
const int** mazeData;
int mazeWidth;
int mazeHeight;

//return names of team members when called
__declspec(dllexport) char* GetTeam() {
	return (char*)"Chase Call";
}

//save the width, height, and data of the maze when called
__declspec(dllexport) void SetMaze(const int** data, int width, int height) {

	mazeData = data;
	mazeHeight = height;
	mazeWidth = width;

}

//set the height, width, and data form the DLL for the maze when called
__declspec(dllexport) int** GetMaze(int& width, int& height) {

	width = mazeWidth;
	height = mazeHeight;
	return (int**)mazeData;

}

//return the next position when called
__declspec(dllexport) void GetNextPosition(int& xPos, int& yPos) {
	
	xPos = xList[currentX];
	yPos = yList[currentY];


}

//save the x and y start position when called
__declspec(dllexport) void SetStart(int xPos, int yPos) {

	startX = xPos;
	startY = yPos;

}

//set the x and y position of the start when called
__declspec(dllexport) void GetStart(int& xPos, int& yPos) {

	if (startX == NULL && startY == NULL) {
		xPos = -1;
		yPos = -1;
	}
	else
	{
		xPos = startX;
		yPos = startY;
	}

}

//save the x and y end position when called
__declspec(dllexport) void SetEnd(int xPos, int yPos) {

	endX = xPos;
	endY = yPos;

}

//set the x and y end position when called
__declspec(dllexport) void GetEnd(int& xPos, int& yPos) {

	if (endX == NULL && endY == NULL) {
		xPos = -1;
		yPos = -1;
	}
	else
	{
		xPos = endX;
		yPos = endY;
	}

}