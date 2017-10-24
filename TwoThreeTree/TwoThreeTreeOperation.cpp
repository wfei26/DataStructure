/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 03/20/15
*File: TwoThreeTreeOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab6 - Two Three Tree
***********************************************************/

#include "TwoThreeTreeOperation.h"
using namespace std;


TwoThreeTreeOperation::TwoThreeTreeOperation()
{
	treeRoot = NULL;
}


/*
* Destructor
*/
TwoThreeTreeOperation::~TwoThreeTreeOperation()
{
	destructor(treeRoot);
}


/*
* Read all item entries from the file and insert them into hash table by hashing algorithm
* @return     the root of binary tree
*/
void TwoThreeTreeOperation::readfile()
{
	ifstream file;
	file.open("data.txt");
	if (!file)
	{
		cout << "Error! File does not exist." << endl;
	}
	else
	{
		int newEntry;
		//read each number and insert them into the tree one by one
		while (file >> newEntry)
		{
			//cout << "insert:" << newEntry << endl;
			insert(newEntry);
			//levelorder();
			//cout << "\n-----------------------" << endl;
		}
	}
	file.close();
}


Node* TwoThreeTreeOperation::search(int newItem)
{
	Node* curNode = searchParent(newItem);
	if (newItem == curNode->getFirst()->getItem())
	{
		return curNode->getFirst();
	}
	if (newItem == curNode->getSecond()->getItem())
	{
		return curNode->getSecond();
	}
	if (curNode->getMinThird() != -1)
	{
		if (newItem == curNode->getThird()->getItem())
		{
			return curNode->getThird();
		}
	}
	return NULL;
}


Node* TwoThreeTreeOperation::searchParent(const int newItem)
{
	Node* tempNode = treeRoot;
	while (tempNode->getFirst()->getTag() != true)
	{
		if (tempNode->getMinThird() == -1)
		{
			if (newItem < tempNode->getMinSecond())
			{
				tempNode = tempNode->getFirst();
			}
			else
			{
				tempNode = tempNode->getSecond();
			}
		}
		else
		{
			if (newItem < tempNode->getMinSecond())
			{
				tempNode = tempNode->getFirst();
			}
			else
			{
				if (newItem >= tempNode->getMinThird())
				{
					tempNode = tempNode->getThird();
				}
				else
				{
					tempNode = tempNode->getSecond();
				}
			}
		}
	}
	return tempNode;
}


void TwoThreeTreeOperation::resetItem(Node* parentPtr)
{
	int tempValue = 0;
	Node* tempPtr = NULL;
	Node* curPtr = parentPtr;
	while (curPtr != treeRoot)
	{
		curPtr = curPtr->getParent();
		tempPtr = curPtr->getSecond();
		while (tempPtr->getTag() != true)
		{
			tempPtr = tempPtr->getFirst();
		}
		tempValue = tempPtr->getItem();
		curPtr->setMinSecond(tempValue);
		if (curPtr->getThird() != NULL)
		{
			tempPtr = curPtr->getThird();
			while (tempPtr->getTag() != true)
			{
				tempPtr = tempPtr->getFirst();
			}
			tempValue = tempPtr->getItem();
			curPtr->setMinThird(tempValue);
		}
	}
}


void TwoThreeTreeOperation::insert(const int newItem)
{
	
	Node* newTreeNode = new Node(newItem, true);
	if (treeRoot == NULL)
	{
		treeRoot = newTreeNode;
	}
	else
	{
		if (treeRoot->getTag() == true)
		{
			Node* newInterNode = new Node(-1, false);
			newTreeNode->setParent(newInterNode);
			if (newItem < treeRoot->getItem())
			{
				newInterNode->setMinSecond(treeRoot->getItem());
				newInterNode->setSecond(treeRoot);
				newInterNode->getSecond()->setParent(newInterNode);
				treeRoot = newInterNode;
				newInterNode->setFirst(newTreeNode);
			}
			else
			{
				newInterNode->setNodePtrWithMinSecond(newItem, treeRoot, newTreeNode);
				newInterNode->getFirst()->setParent(newInterNode);
				treeRoot = newInterNode;
			}
		}
		else
		{
			Node* tempNode = searchParent(newItem);
			insert(newTreeNode, tempNode);
		}
	}
}


void TwoThreeTreeOperation::insert(Node* childPtr, Node* parentPtr)
{
	int tempItem1, tempItem2;
	if (childPtr->getTag() == false)
	{
		tempItem1 = childPtr->getMinSecond();
	}
	else
	{
		tempItem1 = childPtr->getItem();
	}
	
	//the node has three children
	if (parentPtr->getMinThird() != -1)
	{
		Node* newTreeNode = new Node(-1, false);
		if (tempItem1 >= parentPtr->getMinSecond())
		{
			if (tempItem1 < parentPtr->getMinThird())
			{
				newTreeNode->setNodePtrWithMinSecond(parentPtr->getMinThird(), childPtr, parentPtr->getThird());
				newTreeNode->getFirst()->setParent(newTreeNode);
				newTreeNode->getSecond()->setParent(newTreeNode);
				parentPtr->setMinThird(-1);
				parentPtr->setThird(NULL);
			}
			else
			{
				int tempValue = 0;
				Node* tempPtr = childPtr;
				while (tempPtr->getTag() != true)
				{
					tempPtr = tempPtr->getFirst();
				}
				tempValue = tempPtr->getItem();
				newTreeNode->setNodePtrWithMinSecond(tempValue, parentPtr->getThird(), childPtr);
				newTreeNode->getFirst()->setParent(newTreeNode);
				newTreeNode->getSecond()->setParent(newTreeNode);
				parentPtr->setMinThird(-1);
				parentPtr->setThird(NULL);
			}
		}
		else
		{
			if (childPtr->getTag() == false)
			{
				tempItem2 = parentPtr->getFirst()->getMinSecond();
			}
			else
			{
				tempItem2 = parentPtr->getFirst()->getItem();
			}
			if (tempItem2 > tempItem1)
			{
				newTreeNode->setNodePtrWithMinSecond(parentPtr->getMinThird(), parentPtr->getSecond(), parentPtr->getThird());
				newTreeNode->getFirst()->setParent(newTreeNode);
				newTreeNode->getSecond()->setParent(newTreeNode);
				int tempValue = 0;
				Node* tempPtr = parentPtr->getSecond();
				while (tempPtr->getTag() != true)
				{
					tempPtr = tempPtr->getFirst();
				}
				tempValue = tempPtr->getItem();
				parentPtr->setNodeStructure(tempValue, -1, childPtr, parentPtr->getFirst(), NULL);
				childPtr->setParent(parentPtr);
			}
			else
			{
				newTreeNode->setNodePtrWithMinSecond(parentPtr->getMinThird(), parentPtr->getSecond(), parentPtr->getThird());
				newTreeNode->getFirst()->setParent(newTreeNode);
				newTreeNode->getSecond()->setParent(newTreeNode);
				int tempValue = 0;
				Node* tempPtr = NULL;
				parentPtr->setSecond(childPtr);
				tempPtr = parentPtr->getSecond();
				while (tempPtr->getTag() != true)
				{
					tempPtr = tempPtr->getFirst();
				}
				tempValue = tempPtr->getItem();
				parentPtr->setNodePtrWithMinSecondAndMinThird(tempValue, -1, childPtr, NULL);
				childPtr->setParent(parentPtr);
			}
		}
		if (parentPtr != treeRoot)
		{
			insert(newTreeNode, parentPtr->getParent());
		}
		else
		{
			Node* newTempNode = new Node(-1, false);
			int tempValue = 0;
			Node* tempPtr = NULL;
			newTempNode->setFirstAndSecondPtr(parentPtr, newTreeNode);
			parentPtr->setParent(newTempNode);
			newTreeNode->setParent(newTempNode);
			tempPtr = newTreeNode;
			while (tempPtr->getTag() != true)
			{
				tempPtr = tempPtr->getFirst();
			}
			tempValue = tempPtr->getItem();
			newTempNode->setMinSecond(tempValue);
			treeRoot = newTempNode;
		}
	}

	//the node has two children
	else
	{
		if (tempItem1 < parentPtr->getMinSecond())
		{
			if (childPtr->getTag() == false)
			{
				tempItem2 = parentPtr->getFirst()->getMinSecond();
			}
			else
			{
				tempItem2 = parentPtr->getFirst()->getItem();
			}
			if (tempItem2 <= tempItem1)
			{
				int tempValue = 0;
				Node* tempPtr = childPtr;
				while (tempPtr->getTag() != true)
				{
					tempPtr = tempPtr->getFirst();
				}
				tempValue = tempPtr->getItem();
				parentPtr->setNodePtrWithMinSecondAndMinThird(tempValue, parentPtr->getMinSecond(), childPtr, parentPtr->getSecond());
				childPtr->setParent(parentPtr);
			}
			else
			{
				parentPtr->setNodeStructure(parentPtr->getFirst()->getItem(), parentPtr->getMinSecond(), childPtr, parentPtr->getFirst(), parentPtr->getSecond());
				childPtr->setParent(parentPtr);
			}
		}
		else
		{
			parentPtr->setThird(childPtr);
			childPtr->setParent(parentPtr);
			int tempValue = 0;
			Node* tempPtr = parentPtr->getThird();
			while (tempPtr->getTag() != true)
			{
				tempPtr = tempPtr->getFirst();
			}
			tempValue = tempPtr->getItem();
			parentPtr->setMinThird(tempValue);
		}
	}
}

/*
void TwoThreeTreeOperation::insert(const int newItem, Node* childPtr, Node* parentPtr)
{

	int tempItem;
	if (childPtr->getTag() == 1)
	{
		tempItem = childPtr->getItem();
		//if the node has three children
		if (parentPtr->getMinThird() != -1)
		{
			int tempNum;
			Node* newTreeNode = new Node();
			if (tempItem < parentPtr->getMinSecond())
			{
				Node *first = parentPtr->getFirst(), *second = parentPtr->getSecond(), *third = parentPtr->getThird();
				newTreeNode->setTag(false);
				childPtr->setParent(newTreeNode);
				if (tempItem > first->getItem())
				{
					newTreeNode->setNodePtrWithMinSecond(tempItem, first, childPtr);
					first->setParent(newTreeNode);	
				}
				else
				{
					newTreeNode->setNodePtrWithMinSecond(first->getItem(), childPtr, first);
					first->setParent(newTreeNode);
				}
				parentPtr->setNodeStructure(parentPtr->getMinThird(), -1, second, third, NULL);
				tempNum = second->getItem();
			}
			else if (tempItem < parentPtr->getMinThird())
			{
				newTreeNode->setTag(false);
				Node *first = parentPtr->getFirst(), *second = parentPtr->getSecond(), *third = parentPtr->getThird();
				newTreeNode->setNodePtrWithMinSecond(second->getItem(), first, second);
				first->setParent(newTreeNode);
				second->setParent(newTreeNode);
				parentPtr->setNodeStructure(parentPtr->getMinThird(), -1, childPtr, third, NULL);
				childPtr->setParent(parentPtr);
				tempNum = tempItem;
			}
			else
			{
				newTreeNode->setTag(false);
				Node *first = parentPtr->getFirst(), *second = parentPtr->getSecond(), *third = parentPtr->getThird();
				newTreeNode->setNodePtrWithMinSecond(second->getItem(), first, second);
				first->setParent(newTreeNode);
				second->setParent(newTreeNode);
				parentPtr->setNodeStructure(tempItem, -1, third, childPtr, NULL);
				childPtr->setParent(parentPtr);
			}
		}

		//if the node only has one or two children, or may have no children
		else
		{
			//if the node only has one child
			if ((tempItem > parentPtr->getFirst()->getItem()) && (tempItem < parentPtr->getMinSecond()))
			{
				parentPtr->setThird(parentPtr->getSecond());
				parentPtr->setSecond(childPtr);
				childPtr->setParent(parentPtr);
			}
			//if the node has two children
			else if (tempItem > parentPtr->getMinSecond())
			{
				parentPtr->setThird(childPtr);
				childPtr->setParent(parentPtr);
			}
			//if the node has no children
			else
			{
				Node* myFirst = parentPtr->getFirst();
				parentPtr->setSecond(myFirst);
				Node* mySecond = parentPtr->getSecond();
				parentPtr->setThird(mySecond);
				parentPtr->setFirst(childPtr);
				childPtr->setParent(parentPtr);
				tempItem = myFirst->getItem();
			}
			if (tempItem < parentPtr->getMinSecond())
			{
				parentPtr->setMinThird(parentPtr->getMinSecond());
				parentPtr->setMinSecond(tempItem);
			}
			else
			{
				parentPtr->setMinThird(tempItem);
			}
		}
	}

	//if the node is an interior node
	else
	{
		tempItem = childPtr->getMinSecond();
		if (parentPtr->getMinThird() != -1)
		{
			int tempNum;
			Node* newTreeNode = new Node(); 
			Node *first = parentPtr->getFirst(), *second = parentPtr->getSecond(), *third = parentPtr->getThird();
			if (tempItem < first->getMinSecond())
			{
				newTreeNode->setNodePtrWithTag(false, childPtr, first);
				childPtr->setParent(newTreeNode);
				first->setParent(newTreeNode);
				Node* curPtr = first;
				while (curPtr->getFirst() != NULL)
				{
					curPtr = curPtr->getFirst();
				}
				tempItem = curPtr->getItem();
				newTreeNode->setMinSecond(tempItem);
				parentPtr->setNodeStructure(parentPtr->getMinSecond(), -1, second, third, NULL);
				tempNum = second->getItem();
			}
			else if (tempItem < second->getMinSecond())
			{
				newTreeNode->setNodePtrWithTag(false, first, childPtr);
				newTreeNode->setTag(false);
				childPtr->setParent(newTreeNode);
				first->setParent(newTreeNode);
				Node* curPtr = childPtr;
				while (curPtr->getFirst() != NULL)
				{
					curPtr = curPtr->getFirst();
				}
				tempItem = curPtr->getItem();
				newTreeNode->setMinSecond(tempItem);
				parentPtr->setNodeStructure(parentPtr->getMinThird(), -1, second, third, NULL);
				tempNum = second->getItem();
			}
			else if (tempItem < third->getMinSecond())
			{
				newTreeNode->setNodePtrWithTag(false, first, second);
				first->setParent(newTreeNode);
				second->setParent(newTreeNode);
				Node* curPtr = second;
				while (curPtr->getFirst() != NULL)
				{
					curPtr = curPtr->getFirst();
				}
				tempItem = curPtr->getItem();
				newTreeNode->setMinSecond(tempItem);
				parentPtr->setNodeStructure(parentPtr->getMinThird(), -1, childPtr, third, NULL);
				childPtr->setParent(parentPtr);
				tempNum = tempItem;
			}
		}
		else
		{
			Node* first = parentPtr->getFirst(), *second = parentPtr->getSecond();
			//if the node has two children
			if (tempItem > second->getMinSecond())
			{
				parentPtr->setThird(childPtr);
				childPtr->setParent(parentPtr);
			}
			//if the node only has one child
			else if (tempItem > first->getMinSecond())
			{
				parentPtr->setSecond(childPtr);
				parentPtr->setThird(second);
				childPtr->setParent(parentPtr);
			}
			//if the node has no children
			else
			{
				parentPtr->setNodePtr(childPtr, first, second);
				childPtr->setParent(parentPtr);
			}
			if (parentPtr->getThird() == NULL)
			{
				Node* curPtr = parentPtr->getSecond();
				while (curPtr->getFirst() != NULL)
				{
					curPtr = curPtr->getFirst();
				}
				tempItem = curPtr->getItem();
			}
			else
			{
				Node* curPtr = parentPtr->getThird();
				while (curPtr->getFirst() != NULL)
				{
					curPtr = curPtr->getFirst();
				}
				tempItem = curPtr->getItem();
			}
		}
	}	
}
*/

void TwoThreeTreeOperation::remove(const int delItem)
{
	if (treeRoot == NULL)
	{
		cout << "The tree is empty, no such items can be removed." << endl;
		return;
	}
	else
	{
		if (treeRoot->getTag() == false)
		{
			Node* curPtr = search(delItem);
			if (curPtr != NULL)
			{
				remove(curPtr, curPtr->getParent());
			}
		}
		else
		{
			if (delItem == treeRoot->getItem())
			{
				delete treeRoot;
				treeRoot = NULL;
			}
		}
	}
}


void TwoThreeTreeOperation::remove(Node* childPtr, Node* parentPtr)
{
	int tempValue = 0;
	Node* tempPtr = NULL;
	//if the node has two children
	if (parentPtr->getMinThird() == -1)
	{
		if (parentPtr == treeRoot)
		{
			if (parentPtr == childPtr)
			{
				delete parentPtr;
				treeRoot = NULL;
			}
			else
			{
				if (childPtr == parentPtr->getFirst())
				{
					delete parentPtr->getFirst();
					parentPtr->setFirst(NULL);
					treeRoot = parentPtr->getSecond();
					parentPtr->getSecond()->setParent(treeRoot);
					delete parentPtr;
					
				}
				else
				{
					delete parentPtr->getSecond();
					parentPtr->setSecond(NULL);
					treeRoot = parentPtr->getFirst();
					parentPtr->getFirst()->setParent(treeRoot);
					delete parentPtr;
					cout << "NO.3" << endl;
					levelorder();
					cout << endl;
				}
			}
		}
		else
		{
			Node* curPtr = parentPtr->getParent();
			if (parentPtr != curPtr->getFirst())
			{
				Node* tempNode;
				if (parentPtr == curPtr->getSecond())
				{
					tempNode = curPtr->getFirst();
				}
				else
				{
					tempNode = curPtr->getSecond();
				}
				if (tempNode->getMinThird() == -1)
				{
					if (curPtr == parentPtr->getFirst())
					{
						tempNode->setNodePtrWithMinThird(parentPtr->getMinSecond(), parentPtr->getSecond());
						tempNode->getThird()->setParent(tempNode);
						delete parentPtr->getFirst();
						parentPtr->setFirstAndSecondPtr(NULL, NULL);
						remove(parentPtr, parentPtr->getParent());
						cout << "NO.10" << endl;
						levelorder();
						cout << endl;
					}
					else
					{
						tempNode->setThird(parentPtr->getFirst());
						tempNode->getThird()->setParent(tempNode);
						tempPtr = tempNode->getThird();
						while (tempPtr->getTag() != true)
						{
							tempPtr = tempPtr->getFirst();
						}
						tempValue = tempPtr->getItem();
						tempNode->setMinThird(tempValue);
						//tempNode->setNodePtrWithMinThird(tempValue, parentPtr->getFirst());
						//tempNode->getThird()->setParent(tempNode);
						delete parentPtr->getSecond();
						parentPtr->setFirstAndSecondPtr(NULL, NULL);
						cout << "NO.11" << endl;
						levelorder();
						cout << endl;
						remove(parentPtr, parentPtr->getParent());
					}
				}
				else
				{
					if (childPtr == parentPtr->getFirst())
					{
						delete parentPtr->getFirst();
						parentPtr->setFirst(tempNode->getThird());
						parentPtr->getFirst()->setParent(parentPtr);
						tempNode->setMinThird(-1);
						tempNode->setThird(NULL);
						resetItem(parentPtr);
						cout << "NO.8" << endl;
						levelorder();
						cout << endl;
					}
					else
					{
						delete parentPtr->getSecond();
						parentPtr->setFirstAndSecondPtr(tempNode->getThird(), parentPtr->getFirst());
						parentPtr->getFirst()->setParent(parentPtr);
						tempPtr = parentPtr->getSecond();
						while (tempPtr->getTag() != true)
						{
							tempPtr = tempPtr->getFirst();
						}
						tempValue = tempPtr->getItem();
						parentPtr->setMinSecond(tempValue);
						//parentPtr->setNodePtrWithMinSecond(tempValue, tempNode->getThird(), parentPtr->getFirst());
						//parentPtr->getFirst()->setParent(parentPtr);
						tempNode->setMinThird(-1);
						tempNode->setThird(NULL);
						resetItem(parentPtr);
						cout << "NO.9" << endl;
						levelorder();
						cout << endl;
					}
				}
			}
			else
			{
				if (curPtr->getSecond()->getMinThird() == -1)
				{
					if (childPtr == parentPtr->getFirst())
					{
						curPtr->getSecond()->setNodePtr(parentPtr->getSecond(), curPtr->getSecond()->getFirst(), curPtr->getSecond()->getSecond());
						parentPtr->getSecond()->setParent(curPtr->getSecond());
						tempPtr = curPtr->getSecond()->getSecond();
						curPtr->getSecond()->setMinThird(curPtr->getSecond()->getMinSecond());
						while (tempPtr->getTag() != true)
						{
							tempPtr = tempPtr->getFirst();
						}
						tempValue = tempPtr->getItem();
						//curPtr->getSecond()->setNodeStructure(tempValue, curPtr->getSecond()->getMinSecond(), parentPtr->getSecond(), curPtr->getSecond()->getFirst(), curPtr->getSecond()->getSecond());
						curPtr->getSecond()->setMinSecond(tempValue);
						delete parentPtr->getFirst();
						parentPtr->setFirstAndSecondPtr(NULL, NULL);
						cout << "NO.4" << endl;
						levelorder();
						cout << endl;
						remove(parentPtr, parentPtr->getParent());
					}
					else
					{
						curPtr->getSecond()->setNodePtr(parentPtr->getFirst(), curPtr->getSecond()->getFirst(), curPtr->getSecond()->getSecond());
						parentPtr->getFirst()->setParent(curPtr->getSecond());
						tempPtr = curPtr->getSecond()->getSecond();
						while (tempPtr->getTag() != true)
						{
							tempPtr = tempPtr->getFirst();
						}
						tempValue = tempPtr->getItem();
						//curPtr->getSecond()->setNodeStructure(tempValue, curPtr->getSecond()->getMinSecond(), parentPtr->getFirst(), curPtr->getSecond()->getFirst(), curPtr->getSecond()->getSecond());
						//parentPtr->getFirst()->setParent(curPtr->getSecond());
						curPtr->getSecond()->setMinSecond(tempValue);
						curPtr->getSecond()->setMinThird(curPtr->getSecond()->getMinSecond());
						delete parentPtr->getSecond();
						parentPtr->setFirstAndSecondPtr(NULL, NULL);
						cout << "NO.5" << endl;
						levelorder();
						cout << endl;
						remove(parentPtr, parentPtr->getParent());
					}
				}
				else
				{
					if (childPtr == parentPtr->getFirst())
					{
						delete parentPtr->getFirst();
						parentPtr->setFirstAndSecondPtr(parentPtr->getSecond(), curPtr->getSecond()->getFirst());
						parentPtr->getSecond()->setParent(parentPtr);
						tempPtr = parentPtr->getSecond();
						while (tempPtr->getTag() != true)
						{
							tempPtr = tempPtr->getFirst();
						}
						tempValue = tempPtr->getItem();
						parentPtr->setMinSecond(tempValue);
						//parentPtr->setNodePtrWithMinSecond(tempValue, parentPtr->getSecond(), curPtr->getSecond()->getFirst());
						//parentPtr->getSecond()->setParent(parentPtr);
						curPtr->getSecond()->setNodeStructure(curPtr->getSecond()->getMinSecond(), -1, curPtr->getSecond()->getSecond(), curPtr->getSecond()->getThird(), NULL);
						resetItem(parentPtr);
						cout << "NO.6" << endl;
						levelorder();
						cout << endl;
					}
					else
					{
						delete parentPtr->getSecond();
						parentPtr->setSecond(curPtr->getSecond()->getFirst());
						parentPtr->getSecond()->setParent(parentPtr);
						tempPtr = parentPtr->getSecond();
						while (tempPtr->getTag() != true)
						{
							tempPtr = tempPtr->getFirst();
						}
						tempValue = tempPtr->getItem();
						parentPtr->setMinSecond(tempValue);
						curPtr->getSecond()->setNodeStructure(curPtr->getSecond()->getMinThird(), -1, curPtr->getSecond()->getSecond(), curPtr->getSecond()->getThird(), NULL);
						resetItem(parentPtr);
						cout << "NO.7" << endl;
						levelorder();
						cout << endl;
					}
				}
			}
		}
	}

	//if the node has three children
	else
	{
		if (childPtr != parentPtr->getThird())
		{
			if (childPtr == parentPtr->getSecond())
			{
				delete parentPtr->getSecond();
				parentPtr->setNodePtrWithMinSecondAndMinThird(parentPtr->getMinThird(), -1, parentPtr->getThird(), NULL);
				resetItem(parentPtr);
			}
			else
			{
				delete parentPtr->getFirst();
				parentPtr->setNodeStructure(parentPtr->getMinThird(), -1, parentPtr->getSecond(), parentPtr->getThird(), NULL);
				resetItem(parentPtr);
			}
			cout << "NO.2" << endl;
			levelorder();
			cout << endl;
		}
		else
		{
			delete parentPtr->getThird();
			parentPtr->setMinThird(-1);
			parentPtr->setThird(NULL);
			cout << "NO.1" << endl;
			levelorder();
			cout << endl;
		}
	}
}


void TwoThreeTreeOperation::deletemin()
{
	Node* tempPtr = treeRoot;
	if (tempPtr == NULL)
	{
		cout << "Empty tree. No item can be deleted!" << endl;
		return;
	}
	while (tempPtr->getTag() != true)
	{
		tempPtr = tempPtr->getFirst();
	}
	remove(tempPtr->getItem());
}


void TwoThreeTreeOperation::deletemax()
{
	Node* tempPtr = treeRoot;
	if (tempPtr == NULL)
	{
		cout << "Empty tree. No item can be deleted!" << endl;
		return;
	}

	while (tempPtr->getTag() == 0)
	{
		if (tempPtr->getThird() != NULL)
		{
			tempPtr = tempPtr->getThird();
		}
		else
		{
			tempPtr = tempPtr->getSecond();
		}
	}
	remove(tempPtr->getItem());
}


void TwoThreeTreeOperation::levelorder()
{
	if (treeRoot == NULL)
	{
		cout << "The tree is empty, no such items can be printed." << endl;
		return;
	}
	Node* curPtr = NULL;
	QueueOperation myQueue;
	myQueue.enqueue(treeRoot);

	while (!myQueue.isEmpty())
	{
		curPtr = myQueue.getFront();
		myQueue.dequeue();
		if (curPtr->getFirst() != NULL)
		{
			myQueue.enqueue(curPtr->getFirst());
		}
		if (curPtr->getSecond() != NULL)
		{
			myQueue.enqueue(curPtr->getSecond());
		}
		if (curPtr->getThird() != NULL)
		{
			myQueue.enqueue(curPtr->getThird());
		}
		if (curPtr->getTag() == true)
		{
			cout << curPtr->getItem() << " ";
		}
		else
		{
			cout << curPtr->getMinSecond() << " " << curPtr->getMinThird() << " ";
			if (curPtr->getParent() == NULL)
			{
				cout << "\n";
			}
			else if (curPtr->getParent()->getParent() == NULL)
			{
				if ((curPtr == curPtr->getParent()->getSecond()) && (curPtr->getParent()->getThird() == NULL))
				{
					cout << "\n";
				}
				else if (curPtr == curPtr->getParent()->getThird())
				{
					cout << "\n";
				}
				else
				{
					cout << "";
				}
			}
			else if (curPtr->getParent()->getParent() != NULL)
			{
				if (curPtr->getParent()->getParent()->getThird() == NULL)
				{
					if ((curPtr == curPtr->getParent()->getParent()->getSecond()->getSecond()) && (curPtr->getParent()->getParent()->getSecond()->getThird() == NULL))
					{
						cout << "\n";
					}
					else if (curPtr == curPtr->getParent()->getParent()->getSecond()->getThird())
					{
						cout << "\n";
					}
				}
				else if (curPtr->getParent()->getParent()->getThird() != NULL)
				{
					if (curPtr == curPtr->getParent()->getParent()->getThird()->getThird())
					{
						cout << "\n";
					}
					else if ((curPtr == curPtr->getParent()->getParent()->getThird()->getSecond()) && (curPtr->getParent()->getParent()->getThird()->getThird() == NULL))
					{
						cout << "\n";
					}
				}
			}
		}
	}
}


void TwoThreeTreeOperation::destructor(Node* curPtr)
{
	if (curPtr != NULL)
	{
		if (curPtr->getFirst() != NULL)
		{
			destructor(curPtr->getFirst());
		}
		if (curPtr->getSecond() != NULL)
		{
			destructor(curPtr->getSecond());
		}
		if (curPtr->getThird() != NULL)
		{
			destructor(curPtr->getThird());
		}
		delete curPtr;
	}
}


/*
* Combine all functions to execute the program
*/
void TwoThreeTreeOperation::finalOutput()
{
	cout << "Welcome to use my program!\n" << endl;
	int index = 0;
	readfile();

	while (index != 6)
	{
		cout << "..............................................." << endl;
		cout << "Please choose one of the following commands: " << endl;
		cout << "1 - insert\n2 - remove\n3 - deletemin\n4 - deletemax\n5 - levelorder\n6 - exit\n" << endl;
		cout << "Your choice: ";
		cin >> index;

		if (index == 1)
		{
			int newInsertItem;
			cout << "Please insert the number that you want to be inserted in the tree:" << endl;
			cin >> newInsertItem;
			insert(newInsertItem);
			cout << endl;
		}

		if (index == 2)
		{
			int deleteNum;
			cout << "Which number do you want to be removed" << endl;
			cin >> deleteNum;
			remove(deleteNum);
		}

		if (index == 3)
		{
			deletemin();
			cout << endl;
		}

		if (index == 4)
		{
			deletemax();
			cout << endl;
		}

		if (index == 5)
		{
			cout << "level order: " << endl;
			levelorder();
			cout << "\n" << endl;
		}

		if ((index < 1) || (index > 6))
		{
			cout << "Ooooops, typo! Please type the number 1 to 8." << endl;
		}
	}
	cout << "\nThank you for using my program!\n" << endl;
}
