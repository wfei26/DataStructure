/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 05/03/15
*File: QueueOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab9 - Minimum Spanning Tree
******************************************/

#include "QueueOperation.h"


QueueOperation::QueueOperation()
{
	sizeOfQueue = 0;
	frontPtr = NULL;
	backPtr = NULL;
}

QueueOperation::~QueueOperation()
{
	/*
	while (!isEmpty())
	{
		dequeue();
	}
	*/
}

int QueueOperation::getSize()
{
	return sizeOfQueue;
}

void QueueOperation::enqueue(int newPrimBuf[][100], Edge** myQueue, int* tempBuf, int size)
{
	bool decider1 = false;
	bool decider2 = false;
	for (int i = 0; i < size * size; i++) 
	{
		myQueue[i] = NULL;
	}

	int a = 0;
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			for (int l = 0; l < i; l++)
			{
				if (tempBuf[l] == i)
				{
					decider1 = true;
				}
			}
			for (int p = 0; p < i; p++)
			{
				if (tempBuf[p] == j)
				{
					decider2 = true;
				}
			}
			if (newPrimBuf[i][j] != 0 && decider1 && !decider2)
			{
				myQueue[a] = new Edge(newPrimBuf[i][j], i, j);
				a++;
			}
		}
	}
}

Edge* QueueOperation::dequeue(Edge** myQueue, int num)
{
	for (int i = 0; i < num; i++) 
	{
		if (myQueue[i] != NULL) 
		{
			return myQueue[i];
		}
	}
	return NULL;
}

bool QueueOperation::isEmpty(Edge** myQueue, int num)
{
	bool empty = true;
	for (int i = 0; i < num; i++) 
	{
		if (myQueue[i] != NULL)
		{
			empty = false;
		}
	}
	return empty;
}

Edge* QueueOperation::getFront()
{
	/*
	if (!isEmpty())
	{
		return frontPtr->getEntry();
	}
	*/
	return NULL;
}