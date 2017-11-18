/********************************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/23/15
*File: BinomialNode.h
*Course: EECS560 - Data Structure
*Project: Lab10 - Comparing the performance of Binomial queue with Leftist Heap and Skew Heap
*********************************************************************************************/

#ifndef BINOMIALNODE_H_
#define BINOMIALNODE_H_

#include <iostream>

class BinomialNode
{
private:
	int item;
	int order;
	BinomialNode* leftSibling;
	BinomialNode* firstChild;
	BinomialNode* rightSibling;

public:
	/*
	* Default Constructor
	* @param item			 value of item in current node
	* @param order           order of BT root at x
	* @param leftSibling     pointer pointing at the left sibling of x
	* @param firstChild      pointer pointing at the lowest order child of x
	* @param rightSibling    pointer pointing at the right sibling of x
	*/
	BinomialNode();

	BinomialNode(int item);

	BinomialNode(int newItem, BinomialNode* newLeftSibling);

	BinomialNode(int item, BinomialNode* newLeftSibling, BinomialNode* newFirstChild, BinomialNode* newRightSibling);

	/*
	* Destructor
	*/
	~BinomialNode();

	void setOrder(int newOrder);

	int getOrder();

	void setItem(int newItem);

	int getItem();

	void setLeftSibling(BinomialNode* newLeftSibling);

	BinomialNode* getLeftSibling();

	void setFirstChild(BinomialNode* newFirstChild);

	BinomialNode* getFirstChild();

	void setRightSibling(BinomialNode* newRightSibling);

	BinomialNode* getRightSibling();
};

#endif