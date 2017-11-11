/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 03/30/15
*File: MinMaxHeapOperation.h
*Course: EECS560 - Data Structure
*Project: Lab7 - Min-Max Heap
*****************************************/

#ifndef MINMAXHEAPOPERATION_H_
#define MINMAXHEAPOPERATION_H_

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

class MinMaxHeapOperation
{
private:
	int size;
	int NumOfChilren;
	int MinMaxHeap[100];

public:
	/*
	* Default constructor
	*/
	MinMaxHeapOperation();

	/*
	* Destructor
	*/
	~MinMaxHeapOperation();

	/*
	* Read all item entries from the file and insert them into the MinMaxHeap
	*/
	void readfile();


	/*
	* Create new Heap by using TrickleDown method
	*/
	void CreateHeap(const int mysize);


	/*
	* Check if a tree node has children
	* @param pos   the index number of the checked item
	*/
	bool hasChildren(int pos);


	/*
	* Get the value of current level of checked item
	* @param pos       the index number of the checked item
	* @return level    the value of current level of checked item
	*/
	int getLevel(int pos);


	/*
	* Search the current position of checked item
	* @param newItem      the value of checked item
	* @return i			  the index number of the checked item
	*/
	int searchNumber(const int newItem);


	/*
	* To be used for building the heap(bottom up approach, delete min and delete max)
	* @param level    the current level of checked item
	*/
	void TrickleDown(int level);


	/*
	* To be used for building the heap and delete operation
	* @param index    the current index number of checked item
	*/
	void TrickleDownMin(int index);


	/*
	* To be used for building the heap and delete operation
	* @param index    the current index number of checked item
	*/
	void TrickleDownMax(int index);
	
	
	/*
	* To be used for insert
	* @param index    the current index number of checked item
	*/
	void BubbleUp(int index);


	/*
	* To be used for insert
	* @param index    the current index number of checked item
	*/
	void BubbleUpMin(int index);


	/*
	* To be used for insert
	* @param index    the current index number of checked item
	*/
	void BubbleUpMax(int index);


	/*
	* Insert new entry into the MinMaxHeap by using the BubbleUp method
	* @param newItem   the value of new entry
	*/
	void insert(const int newItem);


	/*
	* Delete the smallest value from the MinMaxHeap
	*/
	void deletemin();


	/*
	* Delete the largest value from the MinMaxHeap
	*/
	void deletemax();


	/*
	* Print out all the elements of the MinMaxHeap using level order 
	*/
	void levelorder();


	/*
	* Combine all functions to execute the program
	*/
	void finalOutput();
};

#endif
