#include "pch.h"
#include "Graph.h"


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

}

bool Graph::isAdjacent(int x, int y) {
	return matrix[x][y] != 0;
}

void Graph::AddNode(Vertex* node) {
	nodes.push_back(node);
}

void Graph::AddEdge(int firstVert, int secondVert, int weight = 1) {

}

Vertex* Graph::getNode(int x, int y) {

}

int Graph::getNodeIndex(Vertex* v) {
	
}


Vertex* Graph::getUnivisited(Vertex* v) {

}

Vertex* Graph::getClosest() {

}

void Graph::removeVert(Vertex* v, bool open = true) {

}