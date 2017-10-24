/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 03/20/15
*File: Node.h
*Course: EECS560 - Data Structure
*Project: Lab6 - Two Three Tree
***********************************************************/

#ifndef NODE_H_
#define NODE_H_

#include <iostream>

class Node
{
private:
	int minSecond;
	int minThird;
	int item;
	bool tag;
	Node* parentPtr;
	Node* firstPtr;
	Node* secondPtr;
	Node* thirdPtr;

public:
	Node();
	Node(int newItem);
	Node(bool newTag);
	Node(int newItem, bool newTag);
	Node(int newItem, bool newTag, Node* myParent);
	~Node();

	int getItem();
	void setItem(int newItem);

	int getMinSecond();
	void setMinSecond(int newMinSecond);

	int getMinThird();
	void setMinThird(int newMinThird);

	bool getTag();
	void setTag(bool newTag);

	Node* getParent();
	void setParent(Node* parent);

	Node* getFirst();
	void setFirst(Node* first);

	Node* getSecond();
	void setSecond(Node* second);

	Node* getThird();
	void setThird(Node* third);

	void setMinNumberInNode(int newMinSecond, int newMinThird);
	void setFirstAndSecondPtr(Node* newFirst, Node* newSecond);
	void setSecondAndThirdPtr(Node* newSecond, Node* newThird);
	void setNodePtrWithMinThird(int newMinThird, Node* newThid);
	void setNodePtr(Node* newFirst, Node* newSecond, Node* newThird);
	void setNodePtrWithMinSecond(int newMinSecond, Node* newFirst, Node* newSecond);
	void setNodePtrWithTag(bool newTag, Node* newFirst, Node* newSecond);
	void setNodePtrWithMinSecondAndMinThird(int secondMin, int thirdMin, Node* newSecond, Node* newThird);
	void setNodeStructure(int secondMin, int thirdMin, Node* newFirst, Node* newSecond, Node* newThird);
};

#endif