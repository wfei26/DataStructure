/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 05/03/15
*File: QueueNode.h
*Course: EECS560 - Data Structure
*Project: Lab9 - Minimum Spanning Tree
******************************************/

#ifndef QUEUENODE_H_
#define QUEUENODE_H_

#include <iostream>
#include "Edge.h"

class QueueNode
{
private:
	QueueNode* nextPtr;
	Edge* newEntry;
public:
	QueueNode();
	~QueueNode();
	Edge* getEntry();
	void setEntry(Edge* newNode);
	QueueNode* getNext();
	void setNext(QueueNode* newNextPtr);
};

#endif;
