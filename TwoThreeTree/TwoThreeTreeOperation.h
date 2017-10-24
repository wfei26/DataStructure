/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 03/20/15
*File: TwoThreeTreeOperation.h
*Course: EECS560 - Data Structure
*Project: Lab6 - Two Three Tree
***********************************************************/

#ifndef _TWOTHREETREEOPERATION_H_
#define _TWOTHREETREEOPERATION_H_

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "Node.h"
#include "QueueNode.h"
#include "QueueOperation.h"

class TwoThreeTreeOperation
{
private:
	Node* treeRoot;
public:
	TwoThreeTreeOperation();
	~TwoThreeTreeOperation();
	void readfile();
	Node* search(int newItem);
	Node* searchParent(const int newItem);
	void resetItem(Node* parentPtr);
	void insert(const int newItem);
	void insert(Node* childPtr, Node* parentPtr);
	//void insert(const int newItem, Node* childPtr, Node* parentPtr);
	void remove(const int delItem);
	void remove(Node* childPtr, Node* parentPtr);
	void deletemin();
	void deletemax();
	void levelorder();
	void destructor(Node* curPtr);
	void finalOutput();
};

#endif