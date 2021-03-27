#pragma once
struct Vertex {

	int xPos;
	int yPos;
	int lowestCost;
	int weight;
	int heuristic;
	bool visited;
	Vertex* prevVert;

};