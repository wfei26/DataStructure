/************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/02/15
*File: QueueNode.cpp
*Course: EECS560 - Data Structure
*Project: Lab8 - Comparing the Performance of Leftist Heap and Skew Heap
*************************************************************************/


#include "QueueNode.h"


QueueNode::QueueNode()
{
	nextPtr = NULL;
	newEntry = NULL;
}

QueueNode::~QueueNode()
{
}

HeapNode* QueueNode::getEntry()
{
	return newEntry;
}

void QueueNode::setEntry(HeapNode* newNode)
{
	newEntry = newNode;
}

QueueNode* QueueNode::getNext()
{
	return nextPtr;
}

void QueueNode::setNext(QueueNode* newNextPtr)
{
	nextPtr = newNextPtr;
}
