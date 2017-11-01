/************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/02/15
*File: QueueOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab8 - Comparing the Performance of Leftist Heap and Skew Heap
*************************************************************************/

#ifndef QUEUEOPERATION_H_
#define QUEUEOPERATION_H_

#include <iostream>
#include "QueueNode.h"

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
	void enqueue(BinomialNode* newNode);
	BinomialNode* dequeue();
	bool isEmpty();
	BinomialNode* getFront();
};

#endif
