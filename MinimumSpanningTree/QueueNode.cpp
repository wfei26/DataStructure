/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 05/03/15
*File: QueueNode.cpp
*Course: EECS560 - Data Structure
*Project: Lab9 - Minimum Spanning Tree
******************************************/

#include "QueueNode.h"


QueueNode::QueueNode()
{
	nextPtr = NULL;
	newEntry = NULL;
}

QueueNode::~QueueNode()
{
}

Edge* QueueNode::getEntry()
{
	return newEntry;
}

void QueueNode::setEntry(Edge* newNode)
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
