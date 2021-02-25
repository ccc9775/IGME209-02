#include "pch.h"
#include <iostream>

using namespace std;

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

__declspec(dllexport) char* GetTeam() {
	return (char*)"Chase Call";
}

__declspec(dllexport) void SetMaze(const int** data, int width, int height) {

	mazeData = data;
	mazeHeight = height;
	mazeWidth = width;

}

__declspec(dllexport) int** GetMaze(int& width, int& height) {

	width = mazeWidth;
	height = mazeHeight;
	return (int**)mazeData;

}

__declspec(dllexport) void GetNextPosition(int& xPos, int& yPos) {
	
	xPos = xList[currentX + 1];
	yPos = yList[currentY + 1];


}

__declspec(dllexport) void SetStart(int xPos, int yPos) {

	startX = xPos;
	startY = yPos;

}

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

__declspec(dllexport) void SetEnd(int xPos, int yPos) {

	endX = xPos;
	endY = yPos;

}

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