/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 05/03/15
*File: GraphNode.h
*Course: EECS560 - Data Structure
*Project: Lab9 - Minimum Spanning Tree
******************************************/

#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <iostream>

class GraphNode
{
private:
	int item;
	int rank;
	GraphNode* parentPtr;

public:
	GraphNode();

	GraphNode(int newItem, int newRank);

	GraphNode(int newItem, int newRank, GraphNode* newParentPtr);

	~GraphNode();

	int getItem();

	void setItem(int newItem);

	int getRank();

	void setRank(int newRank);

	GraphNode* getParent();

	void setParent(GraphNode* newParentPtr);
};

#endif

