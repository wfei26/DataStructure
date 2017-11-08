/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 05/03/15
*File: SpanningTreeOperation.h
*Course: EECS560 - Data Structure
*Project: Lab9 - Minimum Spanning Tree
******************************************/

#ifndef SPANNINGTREEOPERATION_H_
#define SPANNINGTREEOPERATION_H_

#include <iostream>
#include <fstream>
#include "GraphNode.h"
#include "Edge.h"
#include "QueueOperation.h"

class SpanningTreeOperation
{
private:
	int graphCount;
	//int edgeCount;
	int nodeCount;
	GraphNode** bufferArray;
	Edge* myEdge;
	Edge** primEdge;
	int primBuf[100][100];

public:
	SpanningTreeOperation();

	~SpanningTreeOperation();

	void readfile();

	void sortEdge(Edge* newEdge, int n);

	int findItem(int index);

	void unionTree(int tree1, int tree2);

	void kruskalAlgorithm(Edge* bufEdge, int nodeCount, int edgeCount);

	void primAlgorithm(int newPrimBuf[][100], int nodeNum, int temp);

	void printKruskalAlgorithm(int numNode, int numTemp, Edge* newEdge);

	void printPrimAlgorithm(Edge* primEdgeBuf, int nodeNum);

	void finalOutput();
};

#endif