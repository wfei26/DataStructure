/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 03/20/15
*File: QueueOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab6 - Two Three Tree
***********************************************************/

#include "QueueOperation.h"


QueueOperation::QueueOperation()
{
	sizeOfQueue = 0;
	frontPtr = NULL;
	backPtr = NULL;
}

QueueOperation::~QueueOperation()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

int QueueOperation::getSize()
{
	return sizeOfQueue;
}

void QueueOperation::enqueue(Node* newNode)
{
	QueueNode* newEntry = new QueueNode();
	newEntry->setEntry(newNode);
	newEntry->setNext(NULL);
	if (!isEmpty())
	{
		backPtr->setNext(newEntry);
		backPtr = newEntry;
	}
	else
	{
		frontPtr = newEntry;
		backPtr = newEntry;
	}
	sizeOfQueue++;
}

Node* QueueOperation::dequeue()
{
	if (!isEmpty())
	{
		Node* tempPtr;
		QueueNode* tempEntry = frontPtr;
		tempPtr = tempEntry->getEntry();
		if (sizeOfQueue != 1)
		{
			frontPtr = frontPtr->getNext();
		}
		else
		{
			frontPtr = NULL;
			backPtr = NULL;
		}
		delete tempEntry;
		sizeOfQueue--;
		return tempPtr;
	}
	else
	{
		return NULL;
	}
}

bool QueueOperation::isEmpty()
{
	bool empty;
	if (frontPtr == NULL)
	{
		empty = true;
	}
	else
	{
		empty = false;
	}
	return empty;
}

Node* QueueOperation::getFront()
{
	if (!isEmpty())
	{
		return frontPtr->getEntry();
	}
}