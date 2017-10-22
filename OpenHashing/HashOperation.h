/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/05/14
*File: HashOperation.h
*Course: EECS560 - Data Structure
*Project: Lab2 - Open Hashing with Separate Chaining
***********************************************************/

#ifndef _HashOperation_H_
#define _HashOperation_H_

#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"

class HashOperation
{
private:
	Node ** hashTable;
	int position;
	int tableSize;

public:
	/*
	* Constructor with the size of list and the position of node
	* @param tableSize     the size of hash table
	* @param position     the position of an exact node
	*/
	HashOperation();


	/*
	* Destructor
	*/
	~HashOperation();


	/*
	* Read all item entries from the file and insert them into hash table by hashing algorithm
	*/
	void readfile();


	/*
	* Use hash function to calculate the index number of position of new entry in hash table
	* @param newItem   the value of new entry
	* @return		   remainder of newItem mod the size of hash table
	*/
	int hash(int newItem);


	/*
	* Insert new entry into the end of the correct list in hash table
	* @param newItem   the value of new entry
	*/
	void insert(const int newItem);


	/*
	* Check if the hash table is empty
	* @return    true if the hash table is empty
	*            false if the hash table is not empty
	*/
	bool isEmpty();


	/*
	* Delete the exact node from the the correct list in hash table 
	* @param deleteItem   the value of delete entry
	*/
	void remove(int deleteItem);


	/*
	* Print the whole hash table
	*/
	void print();


	/*
	* Recursively find the item we need
	* @param newItem   the value of the item we want to find
	* @return          true    if find the item
	*				   false   if do not find it
	*/
	bool find(const int newItem);


	/*
	* Combine all functions to execute the program
	*/
	void finalOutput();
};

#endif