/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/05/14
*File: Node.h
*Course: EECS560 - Data Structure
*Project: Lab2 - Open Hashing with Separate Chaining
***********************************************************/

#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>

class Node
{
private:
	int item;
	Node* nextPtr;

public:
	/*
	* Default Constructor
	*/
	Node();


	/*
	* Destructor
	*/
	~Node();


	/*
	* Constructor with the entry of a node
	* @param newItem    the value of new entry
	*/
	Node(int newItem);


	/*
	* Constructor with the entry and pointer of a node
	* @param newItem         value of new entry
	* @param nextNodePtr     the pointer in a node
	*/
	Node(int newItem, Node* nextNodePtr);


	/*
	* Set new entry into a node
	* @param newItem    value of new entry
	*/
	void setItem(int newItem);


	/*
	* Set the pointer to connect next node
	* @param  newNodePtr      the pointer that points next node
	*/
	void setNext(Node* newNodePtr);


	/*
	* Get the entry of current node
	* @return item     the value of entry of current node
	*/
	int getItem();


	/*
	* Get next pointer that connected with current node
	* @return  nextPtr      next pointer of current node
	*/
	Node* getNext();
};

#endif
