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
#include "BinomialNode.h"

class QueueNode
{
private:
	QueueNode* nextPtr;
	BinomialNode* newEntry;
public:
	QueueNode();
	~QueueNode();
	BinomialNode* getEntry();
	void setEntry(BinomialNode* newNode);
	QueueNode* getNext();
	void setNext(QueueNode* newNextPtr);
};

#endif;
