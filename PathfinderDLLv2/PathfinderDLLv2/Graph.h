#pragma once
#include "Vertex.h"


class Graph
{
public:
	Graph();
	~Graph();

	void AddNode(Vertex* node);
	void AddEdge(int firstVert, int secondVert, int weight = 1);




};

