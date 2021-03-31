#include "pch.h"
#include <stdlib.h>
#include "Graph.h"
#include <iostream>

using namespace std;

struct Point {
	int x;
	int y;
};

//Initialize variables
int startX;
int startY;
int endX;
int endY;
int xList[];
int yList[];
vector<Point> step;
int currentPos = 0;
int** mazeData;
Graph graph;
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
		mazeHeight = height;
		mazeWidth = width;
		currentPos = 0;

		mazeData = new int* [width];
		for (size_t i = 0; i < width; i++) {

			mazeData[i] = new int[height];
			for (size_t j = 0; j < height; j++) {
				mazeData[i][j] = data[i][j];
			}

		}

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
		return mazeData;
	}
}

//return the next position when called
__declspec(dllexport) bool GetNextPosition(int& xPos, int& yPos) {
	
	for (size_t i = 0; i < mazeWidth; i++) {

		for (size_t j = 0; j < mazeHeight; j++) {
		
			if (mazeData[i][j] != 1) {

				Vertex* tempNode = new Vertex;
				tempNode->xPos = i;
				tempNode->yPos = j;
				tempNode->heuristic = abs((int)(endX - 1)) + abs((int)(endY - 1));

				if (mazeData[i][j] == 0) {
					tempNode->weight = 1;
				}
				else {
					tempNode->weight = mazeData[i][j];
				}

				tempNode->lowestCost = INT_MAX;
				graph.AddNode(tempNode);

			}

		}

	}


	for (size_t i = 0; i < mazeWidth; i++) {

		for (size_t j = 0; j < mazeHeight; j++) {

			if (mazeData[i][j] != 1) {

				int firstPoint = graph.getNodeIndex(i, j);

				//4 regular directions
				if (i - 1 >= 0 && mazeData[i - 1][j] != 1) {
					int secondPoint = graph.getNodeIndex(i - 1, j);
					graph.AddEdge(firstPoint, secondPoint, graph.getNode(i-1, j)->weight);
				}
				if (i + 1 >= 0 && mazeData[i + 1][j] != 1) {
					int secondPoint = graph.getNodeIndex(i + 1, j);
					graph.AddEdge(firstPoint, secondPoint, graph.getNode(i + 1, j)->weight);
				}
				if (i - 1 >= 0 && mazeData[i][j - 1] != 1) {
					int secondPoint = graph.getNodeIndex(i, j - 1);
					graph.AddEdge(firstPoint, secondPoint, graph.getNode(i, j - 1)->weight);
				}
				if (i - 1 >= 0 && mazeData[i][j + 1] != 1) {
					int secondPoint = graph.getNodeIndex(i, j + 1);
					graph.AddEdge(firstPoint, secondPoint, graph.getNode(i, j + 1)->weight);
				}

				//4 diagonal directions
				if (i - 1 >= 0 && mazeData[i + 1][j + 1] != 1) {
					int secondPoint = graph.getNodeIndex(i + 1, j + 1);
					graph.AddEdge(firstPoint, secondPoint, graph.getNode(i + 1, j + 1)->weight);
				}
				if (i - 1 >= 0 && mazeData[i - 1][j + 1] != 1) {
					int secondPoint = graph.getNodeIndex(i - 1, j + 1);
					graph.AddEdge(firstPoint, secondPoint, graph.getNode(i - 1, j + 1)->weight);
				}
				if (i - 1 >= 0 && mazeData[i + 1][j - 1] != 1) {
					int secondPoint = graph.getNodeIndex(i + 1, j - 1);
					graph.AddEdge(firstPoint, secondPoint, graph.getNode(i + 1, j - 1)->weight);
				}
				if (i - 1 >= 0 && mazeData[i - 1][j - 1] != 1) {
					int secondPoint = graph.getNodeIndex(i - 1, j - 1);
					graph.AddEdge(firstPoint, secondPoint, graph.getNode(i - 1, j - 1)->weight);
				}

			}

		}

	}
	graph.printMatrix();
	graph.setStart(startX, startY);
	graph.setGoal(endX, endY);

	graph.aStar();

	Vertex* goalVert = graph.goal;
	while (goalVert != nullptr) {

		Point stp;
		stp.x = goalVert->xPos;
		stp.y = goalVert->yPos;
		step.insert(step.begin(), stp);
		goalVert = goalVert->prevVert;

	}

	xPos = xList[currentPos];
	yPos = yList[currentPos];
	currentPos++;
	currentPos++;

	return true;
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