/********************************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/23/15
*File: BinomialNode.cpp
*Course: EECS560 - Data Structure
*Project: Lab10 - Comparing the performance of Binomial queue with Leftist Heap and Skew Heap
*********************************************************************************************/

#include "BinomialNode.h"

/*
* Default Constructor
* @param item			 value of item in current node
* @param order           order of BT root at x
* @param leftSibling     pointer pointing at the left sibling of x
* @param firstChild      pointer pointing at the lowest order child of x
* @param rightSibling    pointer pointing at the right sibling of x
*/
BinomialNode::BinomialNode()
{
	item = -1;
	order = 0;
	leftSibling = this;
	firstChild = NULL;
	rightSibling = NULL;
}


BinomialNode::BinomialNode(int newItem)
{
	item = newItem;
	order = 0;
	leftSibling = this;
	firstChild = NULL;
	rightSibling = NULL;
}


BinomialNode::BinomialNode(int newItem, BinomialNode* newLeftSibling)
{
	item = newItem;
	order = 0;
	leftSibling = newLeftSibling;
	firstChild = NULL;
	rightSibling = NULL;
}


BinomialNode::BinomialNode(int newItem, BinomialNode* newLeftSibling, BinomialNode* newFirstChild, BinomialNode* newRightSibling)
{
	item = newItem;
	order = 0;
	leftSibling = newLeftSibling;
	firstChild = newFirstChild;
	rightSibling = newRightSibling;
}


BinomialNode::~BinomialNode()
{
}


void BinomialNode::setOrder(int newOrder)
{
	order = newOrder;
}


int BinomialNode::getOrder()
{
	return order;
}


void BinomialNode::setItem(int newItem)
{
	item = newItem;
}


int BinomialNode::getItem()
{
	return item;
}


void BinomialNode::setLeftSibling(BinomialNode* newLeftSibling)
{
	leftSibling = newLeftSibling;
}


BinomialNode* BinomialNode::getLeftSibling()
{
	return leftSibling;
}


void BinomialNode::setFirstChild(BinomialNode* newFirstChild)
{
	firstChild = newFirstChild;
}


BinomialNode* BinomialNode::getFirstChild()
{
	return firstChild;
}


void BinomialNode::setRightSibling(BinomialNode* newRightSibling)
{
	rightSibling = newRightSibling;
}


BinomialNode* BinomialNode::getRightSibling()
{
	return rightSibling;
}