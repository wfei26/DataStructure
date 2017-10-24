/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 03/20/15
*File: QueueNode.h
*Course: EECS560 - Data Structure
*Project: Lab6 - Two Three Tree
***********************************************************/

#ifndef QUEUENODE_H_
#define QUEUENODE_H_

#include <iostream>
#include "Node.h"

class QueueNode
{
private:
	QueueNode* nextPtr;
	Node* newEntry;
public:
	QueueNode();
	~QueueNode();
	Node* getEntry();
	void setEntry(Node* newNode);
	QueueNode* getNext();
	void setNext(QueueNode* newNextPtr);
};

#endif;
