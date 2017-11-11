/************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/02/15
*File: HeapNode.h
*Course: EECS560 - Data Structure
*Project: Lab8 - Comparing the Performance of Leftist Heap and Skew Heap
*************************************************************************/

#ifndef HEAPNODE_H_
#define HEAPNODE_H_
#include <iostream>

class HeapNode
{
private:
	int item;
	int rank;
	HeapNode* leftChild;
	HeapNode* rightChild;

public:
	HeapNode();

	HeapNode(int newItem);

	HeapNode(int newItem, int newRank);

	HeapNode(int newItem, HeapNode* newLeftChild, HeapNode* newRighrChild);

	~HeapNode();
	
	int getItem();

	void setItem(const int newItem);

	int getRank();

	void setRank(const int newRank);

	HeapNode* getLeftChild();

	void setLeftChild(HeapNode* newLeftChild);

	HeapNode* getRightChild();

	void setRightChild(HeapNode* newRightChild);
};

#endif