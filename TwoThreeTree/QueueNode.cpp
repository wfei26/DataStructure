/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 03/20/15
*File: QueueNode.cpp
*Course: EECS560 - Data Structure
*Project: Lab6 - Two Three Tree
***********************************************************/


#include "QueueNode.h"


QueueNode::QueueNode()
{
	nextPtr = NULL;
	newEntry = NULL;
}

QueueNode::~QueueNode()
{
}

Node* QueueNode::getEntry()
{
	return newEntry;
}

void QueueNode::setEntry(Node* newNode)
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
