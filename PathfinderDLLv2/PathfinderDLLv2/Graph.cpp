#include "pch.h"
#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph() {
	adjMatrix = nullptr;
}

Graph::~Graph() {
	if (adjMatrix != nullptr) {
		for (size_t i = 0; i < nodes.size(); i++) {
			delete[] adjMatrix[i];
		}
		delete[] adjMatrix;
	}

	for (int i = 0; i < nodes.size(); i++) {
		delete nodes[i];
	}
	nodes.clear();
}

void Graph::setStart(int x, int y) {
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i]->xPos == x && nodes[i]->yPos == y) {
			start = nodes[i];
			break;
		}
	}
}

void Graph::setGoal(int x, int y) {
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i]->xPos == x && nodes[i]->yPos == y) {
			goal = nodes[i];
			break;
		}
	}
}


void Graph::aStar() {

	reset();

	//openList.push_back(start);
	Vertex* current = nullptr;

	for (int i = 0; i < nodes.size(); i++) {
		openList.push_back(nodes[i]);
	}

	while (openList.front() != goal)
	{
		
		Vertex* tempVert = getClosest();
		//current = openList.front();
		current = tempVert;

		openList.pop_back();
		closedList.push_back(current);

		Vertex* neighbor = getUnivisited(current);

		while (neighbor != nullptr) {



			int cost = current->lowestCost + neighbor->weight;
			bool openTrue = false;
			bool closedTrue = false;
			int vectorIndex = NULL;


			for (int i = 0; i < openList.size(); i++) {
				if (openList[i] == neighbor) {
					openTrue = true;
					vectorIndex = i;
					break;
				}
				else {
					openTrue = false;
				}
			}
			for (int i = 0; i < closedList.size(); i++) {
				if (closedList[i] == neighbor) {
					closedTrue = true;
					vectorIndex = i;
					break;
				}
				else {
					closedTrue = false;
				}
			}

			if (openTrue == true && cost < neighbor->lowestCost) {

				openList.erase(openList.begin() + vectorIndex);

			}
			if (closedTrue == true && cost < neighbor->lowestCost) {

				closedList.erase(closedList.begin() + vectorIndex);

			}
			if (openTrue == false && closedTrue == false) {

				neighbor->lowestCost = cost;
				openList.push_back(neighbor);
				neighbor->prevVert = current;
				current = neighbor;

			}

			break;
		}

	}


}

void Graph::fillMatrix() {
	
	int size = nodes.size();

	adjMatrix = new int* [size];
	for (size_t i = 0; i < size; i++) {

		adjMatrix[i] = new int[size];
		for (size_t j = 0; j < size; j++) {
			adjMatrix[i][j] = 0;
		}

	}

}

bool Graph::isAdjacent(int x, int y) {
	return adjMatrix[x][y] != 0;
}

void Graph::AddNode(Vertex* node) {
	nodes.push_back(node);
}

void Graph::AddEdge(int firstVert, int secondVert, int weight) {

	//add the connection for the two vertices to the adjacency matrix
	//find the index of the first vert, then the index of the second vert, check these ont he adjacency matric, if it is a one they are adjacent, if not they are not  adjacent
	
	adjMatrix[firstVert][secondVert] = weight;

	//isAdjacent(firstVert, secondVert);



}

Vertex* Graph::getNode(int x, int y) {

	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i]->xPos == x && nodes[i]->yPos == y) {
			return nodes[i];
			break;
		}
	}
}

int Graph::getNodeIndex(int x, int y) {

	int nodeIndex = NULL;

	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i]->xPos == x && nodes[i]->yPos == y) {
			nodeIndex = i;
			break;
		}

	}

	return nodeIndex;

}


Vertex* Graph::getUnivisited(Vertex* v) {

	int x = v->xPos;
	int size = nodes.size();
	Vertex* unvisitedVert = nullptr;
	

	for (int i = 0; i < size; i++) {

		if (adjMatrix[x][i] == 1) {
			for (int j = 0; j < nodes.size(); j++) {

				if (nodes[j]->xPos == x && nodes[j]->yPos == i && nodes[j]->visited == false) {

					unvisitedVert = nodes[j];
					nodes[j]->visited = true;
					return unvisitedVert;
				}

			}
		}

	}

	return unvisitedVert;

}

Vertex* Graph::getClosest() {
	
	Vertex* closestVert = nullptr;
	int closest = INT_MAX;

	for (int i = 0; i < openList.size(); i++) {
		if (nodes[i]->heuristic < closest) {
			closest = nodes[i]->heuristic;
			closestVert = nodes[i];
		}
	}

	return closestVert;
}

void Graph::removeVert(Vertex* v, bool open) {

	openList.push_back(v);

}



void Graph::printNodes() {

	if (nodes.size() > 0) {

		cout << "nodes" << endl;
		for (size_t i = 0; i < nodes.size(); i++) {
			auto ptr = nodes[i];
			cout << ptr->xPos << "," << ptr->yPos << " " << ptr->heuristic << endl;
		}

	}
	else {
		cout << "there are no nodes" << endl;
	}

}




void Graph::printMatrix() {

	if (nodes.size() > 0) {
		cout << "matrix" << endl;
		int cnt = nodes.size();
		for (size_t i = 0; i < cnt; i++) {

			for (size_t j = 0; j < cnt; j++) {
				cout << adjMatrix[i][j] << " ";
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
