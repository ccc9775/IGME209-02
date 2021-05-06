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
vector<Point> step;
int currentPos = 0;
int** mazeData;
Graph graph;
int mazeWidth;
int mazeHeight;
bool init = false;


//return names of team members when called
extern "C" __declspec(dllexport) char* GetTeam() {
	return (char*)"Chase Call";
}

void DeleteMaze() {

	if (mazeData == nullptr) {
		return;
	}

	for (size_t i = 0; i < mazeWidth; i++) {

		delete[] mazeData[i];

	}
	delete[] mazeData;

	mazeWidth = 0;
	mazeHeight = 0;

}

//save the width, height, and data of the maze when called
extern "C" __declspec(dllexport) bool SetMaze(const int** data, int width, int height) {
	//cout << "starting SetMaze" << endl;

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
		//cout << "exiting SetMaze" << endl;
		return true;
	}



}

//set the height, width, and data form the DLL for the maze when called
extern "C" __declspec(dllexport) int** GetMaze(int& width, int& height) {
	if (!SetMaze) {
		return nullptr;
	}
	else {
		width = mazeWidth;
		height = mazeHeight;
		return mazeData;
	}
}

extern "C" __declspec(dllexport) bool Restart() {

	currentPos = 0;
	return true;

}

//return the next position when called
extern "C" __declspec(dllexport) bool GetNextPosition(int& xPos, int& yPos) {
	
	//cout << "starting getNextPosition" << endl;

	if (init == false) {

		for (size_t i = 0; i < mazeWidth; i++) {

			for (size_t j = 0; j < mazeHeight; j++) {

				if (mazeData[i][j] != 0) {

					Vertex* tempNode = new Vertex;
					tempNode->xPos = i;
					tempNode->yPos = j;
					tempNode->heuristic = abs((int)(endX - i)) + abs((int)(endY - j));
					tempNode->visited = false;

					if (mazeData[i][j] != 0) {
						tempNode->weight = mazeData[i][j];
					}

					tempNode->prevVert = nullptr;
					tempNode->lowestCost = INT_MAX;
					graph.AddNode(tempNode);

				}

			}

		}

		graph.fillMatrix();
		//graph.printNodes();

		for (size_t i = 0; i < mazeWidth; i++) {

			for (size_t j = 0; j < mazeHeight; j++) {

				if (mazeData[i][j] != 0) {

					int firstPoint = graph.getNodeIndex(i, j);
					int lowX = i - 1;
					int lowY = j - 1;


					//4 regular directions
					if (lowX >= 0 && mazeData[i - 1][j] != 0) {
						int secondPoint = graph.getNodeIndex(i - 1, j);
						graph.AddEdge(firstPoint, secondPoint, graph.getNode(i - 1, j)->weight);
					}
					if (i + 1 < mazeWidth && mazeData[i + 1][j] != 0) {
						int secondPoint = graph.getNodeIndex(i + 1, j);
						graph.AddEdge(firstPoint, secondPoint, graph.getNode(i + 1, j)->weight);
					}
					if (lowY >= 0 && mazeData[i][j - 1] != 0) {
						int secondPoint = graph.getNodeIndex(i, j - 1);
						graph.AddEdge(firstPoint, secondPoint, graph.getNode(i, j - 1)->weight);
					}
					if (j + 1 < mazeHeight && mazeData[i][j + 1] != 0) {
						int secondPoint = graph.getNodeIndex(i, j + 1);
						graph.AddEdge(firstPoint, secondPoint, graph.getNode(i, j + 1)->weight);
					}

				}

			}

		}
		//graph.printMatrix();
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
		init = true;
	}

	xPos = step[currentPos].x;
	//cout << step[currentPos].x << " " << step[currentPos].y << endl;
	yPos = step[currentPos].y;
	currentPos++;

	if (currentPos >= step.size()) {
		Restart();
	}

	//cout << "exitting getNextPosition" << endl;
	return true;

}

//save the x and y start position when called
extern "C" __declspec(dllexport) bool SetStart(int xPos, int yPos) {
	//cout << "starting setStart" << endl;

	if (xPos < 0 || yPos < 0) {
		return false;
	}
	else {
		startX = xPos;
		startY = yPos;
		//cout << startX << "," << startY << endl;
		//cout << "exiting setStart" << endl;
		return true;
	}
}

//set the x and y position of the start when called
extern "C" __declspec(dllexport) bool GetStart(int& xPos, int& yPos) {

	if (!SetStart) {
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
extern "C" __declspec(dllexport) bool SetEnd(int xPos, int yPos) {
	//cout << "starting setEnd" << endl;

		endX = xPos;
		endY = yPos;
		//cout << endX << "," << endY << endl;
		//cout << "exiting setEnd" << endl;
		return true;

}

//set the x and y end position when called
extern "C" __declspec(dllexport) bool GetEnd(int& xPos, int& yPos) {


			xPos = endX;
			yPos = endY;
			return true;
		
	
}

