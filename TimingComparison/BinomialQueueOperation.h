/********************************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/23/15
*File: BinomialQueueOperation.h
*Course: EECS560 - Data Structure
*Project: Lab10 - Comparing the performance of Binomial queue with Leftist Heap and Skew Heap
*********************************************************************************************/
#ifndef BINOMIALQUEUEOPERATION_H_
#define BINOMIALQUEUEOPERATION_H_

#include <iostream>
#include <string>
#include <fstream>
#include "BinomialNode.h"

class BinomialQueueOperation
{
public:
	BinomialNode* BinomialQueueRoot;

	/*
	* Default constructor
	*/
	BinomialQueueOperation();


	/*
	* Destructor
	*/
	~BinomialQueueOperation();


	/*
	* Read all item entries from the file and insert them into the Leftist Heap
	*/
	//void readfile();


	/*
	* merge Binomial Queues together (insert and deletemin will call merge)
	* @param q1   the first binomial queue
	* @param q2   the second binomial queue
	*/
	void merge(BinomialNode* q1, BinomialNode* q2);


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
	* print out all the elements of the Binomial queue using level order traversal(each level in one line)
	*/
	//void levelorder();


	/*
	* Combine all functions to execute the program
	*/
	//void finalOutput();
};

#endif
