/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 03/20/15
*File: Node.cpp
*Course: EECS560 - Data Structure
*Project: Lab6 - Two Three Tree
***********************************************************/

#include "Node.h"

Node::Node()
{
	minSecond = -1;
	minThird = -1;
	item = -1;
	tag = false;
	parentPtr = NULL;
	firstPtr = NULL;
	secondPtr = NULL;
	thirdPtr = NULL;
}


Node::Node(int newItem)
{
	item = newItem;
	minSecond = -1;
	minThird = -1;
	tag = false;
	parentPtr = NULL;
	firstPtr = NULL;
	secondPtr = NULL;
	thirdPtr = NULL;
}


Node::Node(bool newTag)
{
	tag = newTag;
	minSecond = -1;
	minThird = -1;
	item = -1;
	parentPtr = NULL;
	firstPtr = NULL;
	secondPtr = NULL;
	thirdPtr = NULL;
}


Node::Node(int newItem, bool newTag)
{
	item = newItem;
	tag = newTag;
	minSecond = -1;
	minThird = -1;
	parentPtr = NULL;
	firstPtr = NULL;
	secondPtr = NULL;
	thirdPtr = NULL;
}


Node::Node(int newItem, bool newTag, Node* myParent)
{
	item = newItem;
	tag = newTag;
	parentPtr = myParent;
	minSecond = -1;
	minThird = -1;
	firstPtr = NULL;
	secondPtr = NULL;
	thirdPtr = NULL;
}


Node::~Node()
{
}


int Node::getItem()
{
	return item;
}


void Node::setItem(int newItem)
{
	item = newItem;
}


int Node::getMinSecond()
{
	return minSecond;
}


void Node::setMinSecond(int newMinSecond)
{
	minSecond = newMinSecond;
}


int Node::getMinThird()
{
	return minThird;
}


void Node::setMinThird(int newMinThird)
{
	minThird = newMinThird;
}


bool Node::getTag()
{
	return tag;
}


void Node::setTag(bool newTag)
{
	tag = newTag;
}


Node* Node::getParent()
{
	return parentPtr;
}


void Node::setParent(Node* parent)
{
	parentPtr = parent;
}


Node* Node::getFirst()
{
	return firstPtr;
}


void Node::setFirst(Node* first)
{
	firstPtr = first;
}


Node* Node::getSecond()
{
	return secondPtr;
}


void Node::setSecond(Node* second)
{
	secondPtr = second;
}


Node* Node::getThird()
{
	return thirdPtr;
}


void Node::setThird(Node* third)
{
	thirdPtr = third;
}


void Node::setMinNumberInNode(int newMinSecond, int newMinThird)
{
	minSecond = newMinSecond;
	minThird = newMinThird;
}


void Node::setFirstAndSecondPtr(Node* newFirst, Node* newSecond)
{
	firstPtr = newFirst;
	secondPtr = newSecond;
}


void Node::setSecondAndThirdPtr(Node* newSecond, Node* newThird)
{
	secondPtr = newSecond;
	thirdPtr = newThird;
}


void Node::setNodePtrWithMinThird(int newMinThird, Node* newThid)
{
	minThird = newMinThird;
	thirdPtr = newThid;
}


void Node::setNodePtr(Node* newFirst, Node* newSecond, Node* newThird)
{
	firstPtr = newFirst;
	secondPtr = newSecond;
	thirdPtr = newThird;
}


void Node::setNodePtrWithMinSecond(int newMinSecond, Node* newFirst, Node* newSecond)
{
	minSecond = newMinSecond;
	firstPtr = newFirst;
	secondPtr = newSecond;
}


void Node::setNodePtrWithTag(bool newTag, Node* newFirst, Node* newSecond)
{
	tag = newTag;
	firstPtr = newFirst;
	secondPtr = newSecond;
}


void Node::setNodePtrWithMinSecondAndMinThird(int secondMin, int thirdMin, Node* newSecond, Node* newThird)
{
	minSecond = secondMin;
	minThird = thirdMin;
	secondPtr = newSecond;
	thirdPtr = newThird;
}


void Node::setNodeStructure(int secondMin, int thirdMin, Node* newFirst, Node* newSecond, Node* newThird)
{
	minSecond = secondMin;
	minThird = thirdMin;
	firstPtr = newFirst;
	secondPtr = newSecond;
	thirdPtr = newThird;
}