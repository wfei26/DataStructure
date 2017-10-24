/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 03/20/15
*File: QueueOperation.h
*Course: EECS560 - Data Structure
*Project: Lab6 - Two Three Tree
***********************************************************/

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
	void enqueue(Node* newNode);
	Node* dequeue();
	bool isEmpty();
	Node* getFront();
};

#endif
