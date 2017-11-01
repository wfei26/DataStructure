/************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/02/15
*File: QueueOperation.h
*Course: EECS560 - Data Structure
*Project: Lab8 - Comparing the Performance of Leftist Heap and Skew Heap
*************************************************************************/

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

void QueueOperation::enqueue(BinomialNode* newNode)
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

BinomialNode* QueueOperation::dequeue()
{
	if (!isEmpty())
	{
		BinomialNode* tempPtr;
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

BinomialNode* QueueOperation::getFront()
{
	if (!isEmpty())
	{
		return frontPtr->getEntry();
	}
}