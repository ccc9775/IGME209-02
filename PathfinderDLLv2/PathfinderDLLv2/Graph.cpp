#include <iostream>
#include "pch.h"
#include "Graph.h"
using namespace std;

Graph::Graph() {
	matrix = nullptr;
}

Graph::~Graph() {
	if (matrix != nullptr) {
		for (size_t i = 0; i < nodes.size(); i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	for (int i = 0; i < nodes.size(); i++) {
		delete nodes[i];
	}
	nodes.clear();
}

void Graph::setStart(int x, int y) {
	start->xPos = x;
	start->yPos = y;
}

void Graph::setGoal(int x, int y) {
	goal->xPos = x;
	goal->yPos = y;
}


void Graph::aStar() {

	reset();

	openList.push_back(start);
	Vertex* current = nullptr;


	while (openList.front() != goal)
	{
		
		Vertex* tempVert = getClosest();
		current = tempVert;

		openList.pop_back();
		closedList.push_back(current);

		while (getUnivisited(current) != nullptr) {

			Vertex* neighbor = getUnivisited(current);

			int cost = current->lowestCost + neighbor->weight;


		}

	}


}

bool Graph::isAdjacent(int x, int y) {
	return matrix[x][y] != 0;
}

void Graph::AddNode(Vertex* node) {
	nodes.push_back(node);
}

void Graph::AddEdge(int firstVert, int secondVert, int weight = 1) {

	if (nodes.size() > 0) {

			nodes[secondVert]->prevVert = nodes[firstVert];
	}

}

Vertex* Graph::getNode(int x, int y) {
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i]->xPos == x && nodes[i]->yPos == y) {
			return nodes[i];
		}
	}
}

int Graph::getNodeIndex(int x, int y) {
	
	return matrix[x][y];

}


Vertex* Graph::getUnivisited(Vertex* v) {

}

Vertex* Graph::getClosest() {
	
}

void Graph::removeVert(Vertex* v, bool open = true) {

			openList.push_back(v);

}








void Graph::printMatrix() {

	if (nodes.size() > 0) {
		cout << "matrix" << endl;
		int cnt = nodes.size();
		for (size_t i = 0; i < cnt; i++) {

			for (size_t j = 0; j < cnt; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "there are no nodes" << endl;
	}
}



void Graph::reset() {

	if (nodes.size() > 0) {

		for (size_t i = 0; i < nodes.size(); i++) {

			nodes[i]->visited = false;
			nodes[i]->prevVert = nullptr;
		}
	}

}
