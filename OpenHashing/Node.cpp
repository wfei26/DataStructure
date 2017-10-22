/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/05/14
*File: Node.cpp
*Course: EECS560 - Data Structure
*Project: Lab2 - Open Hashing with Separate Chaining
***********************************************************/

#include "Node.h"

/*
* Default Constructor
*/
Node::Node()
{
	nextPtr = NULL;
}


/*
* Destructor
*/
Node::~Node(){}


/*
* Constructor with the entry of a node
* @param newItem    the value of new entry
*/
Node::Node(int newItem)
{
	item = newItem;
	nextPtr = NULL;
}


/*
* Constructor with the entry and pointer of a node
* @param newItem         value of new entry
* @param nextNodePtr     the pointer in a node
*/
Node::Node(int anItem, Node* newNodePtr)
{
	item = anItem;
	nextPtr = newNodePtr;
}


/*
* Set new entry into a node
* @param newItem    value of new entry
*/
void Node::setItem(int newItem)
{
	item = newItem;
}


/*
* Set the pointer to connect next node
* @param  newNodePtr      the pointer that points next node
*/
void Node::setNext(Node* newNodePtr)
{
	nextPtr = newNodePtr;
}


/*
* Get the entry of current node
* @return item     the value of entry of current node
*/
int Node::getItem()
{
	return item;
}


/*
* Get next pointer that connected with current node
* @return  nextPtr      next pointer of current node
*/
Node* Node::getNext()
{
	return nextPtr;
}

