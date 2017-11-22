/********************************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/23/15
*File: LeftistHeapOperation.h
*Course: EECS560 - Data Structure
*Project: Lab10 - Comparing the performance of Binomial queue with Leftist Heap and Skew Heap
*********************************************************************************************/


#ifndef LEFTISTHEAPOPERATION_H_
#define LEFTISTHEAPOPERATION_H_

#include <iostream>
#include <string>
#include <fstream>
#include "HeapNode.h"
//#include "QueueOperation.h"

class LeftistHeapOperation
{
public:
	HeapNode* LeftistHeap;

	/*
	* Default constructor
	*/
	LeftistHeapOperation();


	/*
	* Destructor
	*/
	~LeftistHeapOperation();


	/*
	* Read all item entries from the file and insert them into the Leftist Heap
	*/
	//void readfile();


	/*
	* Update all value of ranks recursively
	* @param curNode   the current node
	*/
	void adjustRank(HeapNode* curNode);


	/*
	* Merge two heaps into one heap
	* @param h1   the first heap
	* @param h2   the second heap
	*/
	HeapNode* concate(HeapNode* h1, HeapNode* h2);


	/*
	* Insert an new entry into the Leftist Heap 
	* @param newItem   the value of new entry
	*/
	void insert(int newItem);


	/*
	* Delete the smallest value from the Leftist Heap
	*/
	void deletemin();


	/*
	* Print out all the elements of the Leftist Heap by using preorder
	*/
	//void preorder(HeapNode* curPtr);


	/*
	* Print out all the elements of the Leftist Heap by using inorder
	*/
	//void inorder(HeapNode* curPtr);


	/*
	* Print out all the elements of the Leftist Heap by using level order
	*/
	//void levelorder();


	/*
	* Combine all functions to execute the program
	*/
	//void finalOutput();
};


#endif
