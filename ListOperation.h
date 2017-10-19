/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 01/31/14
*File: ListOperation.h
*Course: EECS560 - Data Structure
*Project: Lab1 - Designing a class for a singly linked list
***********************************************************/

#ifndef _LISTOPERATION_H_
#define _LISTOPERATION_H_

#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"

class ListOperation
{
private:
	Node* headPtr = NULL;
	int listSize;
	int position;

public:
	/*
	* Constructor with the size of list and the position of node
	* @param listSize     the size of list
	* @param position     the position of an exact node
	*/
	ListOperation();


	/*
	* Destructor
	*/
	~ListOperation();


	/*
	* Read all item entries from the file and insert them into each node to combine a list
	* @return headPtr     the headPtr can access all information of the whole list
	*/
	Node* readfile();


	/*
	* Get the node by passing the position of node
	* @param pos   the position of the node
	* @return      current pointer of the node of this position
	*/
	Node* getNodeAt(int pos);


	/*
	* Insert new entry into the end of the list
	* @param newItem   the value of new entry
	* @return          the head pointer of the whole list
	*/
	Node* insert(const int newItem);


	/*
	* Check if the list is empty
	* @return    true if the list is empty
	*            false if the list is not empty
	*/
	bool isEmpty();


	/*
	* Delete the exact node from the list
	* @param deleteItem   the value of delete entry
	* @param curPtr       usually pass head pointer in order to find the delete node recursively
	*/
	void erase(int deleteItem, Node* curPtr);


	/*
	* Print the whole list
	* @param curPtr   pass current pointer to print each node recursively
	*/
	void print(Node* curPtr);


	/*
	* Recursively find the item we need
	* @param newItem   the value of the item we want to find
	* @param curPtr    pass current pointer in order to recursively find the node we want
	* @return          the pointer that points the item we want to find
	*/
	Node* find(const int newItem, Node* curPtr);


	/*
	* Combine all functions to execute the program
	*/
	void finalOutput();
};

#endif