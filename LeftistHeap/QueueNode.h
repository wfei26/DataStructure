/************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/02/15
*File: QueueNode.h
*Course: EECS560 - Data Structure
*Project: Lab8 - Comparing the Performance of Leftist Heap and Skew Heap
*************************************************************************/
#ifndef QUEUENODE_H_
#define QUEUENODE_H_

#include <iostream>
#include "HeapNode.h"

class QueueNode
{
private:
	QueueNode* nextPtr;
	HeapNode* newEntry;
public:
	QueueNode();
	~QueueNode();
	HeapNode* getEntry();
	void setEntry(HeapNode* newNode);
	QueueNode* getNext();
	void setNext(QueueNode* newNextPtr);
};

#endif;
