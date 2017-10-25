/************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/02/15
*File: HeapNode.cpp
*Course: EECS560 - Data Structure
*Project: Lab8 - Comparing the Performance of Leftist Heap and Skew Heap
*************************************************************************/

#include "HeapNode.h"

HeapNode::HeapNode()
{
	item = 0;
	rank = 0;
	leftChild = NULL;
	rightChild = NULL;
}


HeapNode::HeapNode(int newItem)
{
	item = newItem;
	rank = 0;
	leftChild = NULL;
	rightChild = NULL;
}


HeapNode::HeapNode(int newItem, int newRank)
{
	item = newItem;
	rank = newRank;
	leftChild = NULL;
	rightChild = NULL;
}


HeapNode::HeapNode(int newItem, HeapNode* newLeftChild, HeapNode* newRighrChild)
{
	item = newItem;
	rank = 0;
	leftChild = newLeftChild;
	rightChild = newRighrChild;
}


HeapNode::~HeapNode()
{
}


int HeapNode::getItem()
{
	return item;
}


void HeapNode::setItem(const int newItem)
{
	item = newItem;
}


int HeapNode::getRank()
{
	return rank;
}


void HeapNode::setRank(const int newRank)
{
	rank = newRank;
}


HeapNode* HeapNode::getLeftChild()
{
	return leftChild;
}


void HeapNode::setLeftChild(HeapNode* newLeftChild)
{
	leftChild = newLeftChild;
}


HeapNode* HeapNode::getRightChild()
{
	return rightChild;
}


void HeapNode::setRightChild(HeapNode* newRightChild)
{
	rightChild = newRightChild;
}
