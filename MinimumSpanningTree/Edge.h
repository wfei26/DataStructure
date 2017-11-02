/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 05/03/15
*File: Edge.h
*Course: EECS560 - Data Structure
*Project: Lab9 - Minimum Spanning Tree
******************************************/

#ifndef EDGE_H_
#define EDGE_H_

#include <iostream>

class Edge
{
private:
	int weight;
	int frontVertex;
	int backVertex;

public:
	Edge();

	Edge(int newWeight, int newFrontVertex, int newBackVertex);

	~Edge();

	int getWeight();

	void setWeight(int newWeight);

	int getFrontVertex();

	void setFrontVertex(int newFrontVertex);

	int getBackVertex();

	void setBackVertex(int newBackVertex);
};

#endif