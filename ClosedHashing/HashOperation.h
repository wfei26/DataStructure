/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/12/14
*File: HashOperation.h
*Course: EECS560 - Data Structure
*Project: Lab3 - Closed Hashing with Open Addressing
***********************************************************/

#ifndef HASHOPERATION_H_
#define HASHOPERATION_H_

#include <iostream>
#include <string>
#include <fstream>
#include "HashTable.h"

class HashOperation
{
private:
	HashTable* closeHashTable;
	int tableSize;
	int currentSize;

public:
	/*
	* Default constructor
	* @param tableSize    the size of hash table
	*/
	HashOperation();


	/*
	* Destructor
	*/
	~HashOperation();

	
	/*
	* Read all item entries from the file and insert them into closed hash table
	*/
	void readfile();


	/*
	* Insert new entry into the hash table by using closed hashing algorithm
	* @param newItem   the value of new entry
	* @return true     if the item is inserted successfully
	*         false    if the item is not inserted successfully
	*/
	bool insert(const int newItem);

	
	/*
	* Remove the key from the hash table
	* @param delItem   the value of delete entry
	* @return true     if the item is deleted successfully
	*         false    if the item is not deleted successfully
	*/
	bool remove(const int delItem);


	/*
	* Print out all the elements of the hash table
	*/
	void print();


	/*
	* Use hi(x) = (h(x) +i^2)% m for quadratic probing
	* @param i             parameter in closed hashing algorithm
	* @param newItem       the value of new item
	* @return hashResult   the array index of new item in hash table
	*/
	int hash(int i, const int newItem);


	/*
	* Check if the hash table contains the item 
	* @param newItem   the value of new item to be checked
	* @return true     if the key x is in the hash table
	*         false	   if the key x is not in the hash table
	*/
	bool contains(const int newItem);
	
	
	/*
	* Check if the hash table if full
	* @return true    if the hash table is full
	*         false	  if the hash table is not full
	*/
	bool isfull();


	/*
	* Combine all functions to execute the program
	*/
	void finalOutput();
};


#endif
