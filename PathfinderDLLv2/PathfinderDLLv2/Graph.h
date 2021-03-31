#pragma once
#include <vector>
#include "Vertex.h"
using namespace std;



class Graph
{
public:
	Graph();
	~Graph();

	void AddNode(Vertex* node);
	void AddEdge(int firstVert, int secondVert, int weight = 1);
	int getNodeIndex(int x, int y);
	Vertex* getNode(int x, int y);

	void setStart(int x, int y);
	void setGoal(int x, int y);
	void aStar();
	bool isAdjacent(int x, int y);

	void printMatrix();

	Vertex* goal;

private:
	vector<Vertex*> nodes;
	vector<Vertex*> closedList;
	vector<Vertex*> openList;
	Vertex* start;
	Vertex* current;
	int** matrix;


	Vertex* getUnivisited(Vertex* v);
	Vertex* getClosest();
	void removeVert(Vertex* v, bool open = true);
	void reset();
};

