/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 05/03/15
*File: QueueOperation.h
*Course: EECS560 - Data Structure
*Project: Lab9 - Minimum Spanning Tree
******************************************/

#ifndef QUEUEOPERATION_H_
#define QUEUEOPERATION_H_

#include <iostream>
#include "QueueNode.h"
#include "Edge.h"

class QueueOperation
{
private:
	int sizeOfQueue;
	QueueNode* frontPtr;
	QueueNode* backPtr;

public:
	QueueOperation();
	~QueueOperation();
	int getSize();
	void enqueue(int newPrimBuf[][100], Edge** myQueue, int* tempBuf, int size);
	Edge* dequeue(Edge** myQueue, int num);
	bool isEmpty(Edge** myQueue, int num);
	Edge* getFront();
};

#endif
