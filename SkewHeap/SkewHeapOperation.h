/************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/02/15
*File: SkewHeapOperation.h
*Course: EECS560 - Data Structure
*Project: Lab8 - Comparing the Performance of Leftist Heap and Skew Heap
*************************************************************************/


#ifndef SHEWHEAPOPERATION_H_
#define SHEWHEAPOPERATION_H_

#include <iostream>
#include <string>
#include <fstream>
#include "HeapNode.h"
#include "QueueOperation.h"

class SkewHeapOperation
{
public:
	HeapNode* SkewHeap;

	/*
	* Default constructor
	*/
	SkewHeapOperation();


	/*
	* Destructor
	*/
	~SkewHeapOperation();


	/*
	* Read all item entries from the file and insert them into the Skew Heap
	*/
	void readfile();


	/*
	* Merge two heaps into one heap
	* @param h1   the first heap
	* @param h2   the second heap
	*/
	HeapNode* concate(HeapNode* h1, HeapNode* h2);


	/*
	* Insert an new entry into the Skew Heap 
	* @param newItem   the value of new entry
	*/
	void insert(int newItem);


	/*
	* Delete the smallest value from the Skew Heap
	*/
	void deletemin();


	/*
	* Print out all the elements of the Skew Heap by using preorder
	*/
	void preorder(HeapNode* curPtr);


	/*
	* Print out all the elements of the Skew Heap by using inorder
	*/
	void inorder(HeapNode* curPtr);


	/*
	* Print out all the elements of the Skew Heap by using level order
	*/
	void levelorder();


	/*
	* Combine all functions to execute the program
	*/
	void finalOutput();
};


#endif
