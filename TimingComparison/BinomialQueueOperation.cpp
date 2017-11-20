/********************************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/23/15
*File: BinomialQueueOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab10 - Comparing the performance of Binomial queue with Leftist Heap and Skew Heap
*********************************************************************************************/

#include "BinomialQueueOperation.h"
using namespace std;

BinomialQueueOperation::BinomialQueueOperation()
{
	BinomialQueueRoot = NULL;
}


BinomialQueueOperation::~BinomialQueueOperation()
{
}

/*
* Read all item entries from the file and insert them into the Leftist Heap
*/
/*void BinomialQueueOperation::readfile()
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
			insert(newEntry);
		}

		//levelorder();
	}
	file.close();
}*/


/*
* merge Binomial Queues together (insert and deletemin will call merge)
* @param q1   the first binomial queue
* @param q2   the second binomial queue
*/
void BinomialQueueOperation::merge(BinomialNode* q1, BinomialNode* q2)
{
	BinomialNode* tempNode = q2;
	while ((q1 != NULL) && (q2 != NULL))
	{
		if (q1->getOrder() < q2->getOrder())
		{
			q1 = q1->getRightSibling();
		}
		else if (q1->getOrder() == q2->getOrder())
		{
			if (q1->getItem() > q2->getItem())
			{
				BinomialNode* rightMostNode1 = BinomialQueueRoot->getLeftSibling();
				BinomialNode* rightMostNode2 = q1->getLeftSibling();
				BinomialNode* newRightNode1 = tempNode->getLeftSibling();
				BinomialNode* newRightNode2 = q2->getLeftSibling();
				if ((q1->getLeftSibling()->getRightSibling() == NULL) && (q2->getLeftSibling()->getRightSibling() == NULL))
				{
					BinomialNode* bufPtr = q1;
					q1 = q2;
					q2 = bufPtr;
					BinomialQueueRoot = q1;
				}
				else if ((q1->getLeftSibling()->getRightSibling() != NULL) && (q2->getLeftSibling()->getRightSibling() != NULL))
				{
					rightMostNode2->setRightSibling(q2);
					q2->setLeftSibling(rightMostNode2);
					BinomialQueueRoot->setLeftSibling(newRightNode1);
					newRightNode2->setRightSibling(q1);
					q1->setLeftSibling(newRightNode2);
					tempNode->setLeftSibling(rightMostNode1);
					q1 = rightMostNode2->getRightSibling();
					q2 = newRightNode2->getRightSibling();
				}

				else if (q2->getLeftSibling()->getRightSibling() == NULL)
				{
					BinomialNode* rightMostNode1 = BinomialQueueRoot->getLeftSibling();
					BinomialNode* newRightNode1 = tempNode->getLeftSibling();
					BinomialNode* rightMostNode2 = q1->getLeftSibling();
					rightMostNode2->setRightSibling(q2);
					q2->setLeftSibling(rightMostNode2);
					BinomialQueueRoot->setLeftSibling(newRightNode1);
					q2 = q1;
					q1 = rightMostNode2->getRightSibling();
					q2->setLeftSibling(rightMostNode1);
					tempNode = q2;
				}
			}
			BinomialNode* nextPtr = q2->getRightSibling();
			q2->setRightSibling(NULL);
			if (nextPtr != NULL)
			{
				nextPtr->setLeftSibling(q2->getLeftSibling());
			}
			if (q1->getOrder() != 0)
			{
				q2->setLeftSibling(q1->getFirstChild()->getLeftSibling());
				q2->getLeftSibling()->setRightSibling(q2);
				q1->getFirstChild()->setLeftSibling(q2);
			}
			else
			{
				q1->setFirstChild(q2);
				q2->setLeftSibling(q2);
			}
			q1->setOrder(q1->getOrder() + 1);
			q1 = q1->getRightSibling();
			q2 = nextPtr;
		}
		else
		{	
			BinomialNode* nextPtr = q2->getRightSibling();
			if (q1->getLeftSibling()->getRightSibling() != NULL)
			{
				q1->getLeftSibling()->setRightSibling(q2);
				q2->setLeftSibling(q1->getLeftSibling());
				q2->setRightSibling(q1);
				q1->setLeftSibling(q2);
			}
			else
			{
				q2->setLeftSibling(q1->getLeftSibling());
				q2->setRightSibling(q1);
				q1->setLeftSibling(q2);
				BinomialQueueRoot = q2;
			}
			q2 = nextPtr;
		}
	}
	if (q2 != NULL)
	{
		if (BinomialQueueRoot == NULL)
		{
			BinomialQueueRoot = q2;
		}
		else
		{
			BinomialNode* tempPtr = BinomialQueueRoot->getLeftSibling();
			tempPtr->setRightSibling(q2);
			BinomialQueueRoot->setLeftSibling(q2->getLeftSibling());
			q2->setLeftSibling(tempPtr);
		}
	}
	q1 = BinomialQueueRoot;
	while (q1 != NULL)
	{

		BinomialNode* nextRightNode = q1->getRightSibling();

		if ((nextRightNode == NULL) || (q1->getOrder() != nextRightNode->getOrder()))
		{
			q1 = q1->getRightSibling();
		}
		else
		{
			if (q1->getItem() < nextRightNode->getItem())
			{
				if (q1->getOrder() == 0)
				{
					q1->setFirstChild(nextRightNode);
					q1->setRightSibling(nextRightNode->getRightSibling());
					if (q1->getRightSibling() != NULL){
						q1->getRightSibling()->setLeftSibling(q1);
					}
					nextRightNode->setRightSibling(NULL);
					nextRightNode->setLeftSibling(nextRightNode);
				}
				else
				{
					q1->setRightSibling(nextRightNode->getRightSibling());
					if (q1->getRightSibling() != NULL)
					{
						q1->getRightSibling()->setLeftSibling(q1);
					}
					if (q1->getLeftSibling() == nextRightNode)
					{
						q1->setLeftSibling(q1);
					}
					nextRightNode->setLeftSibling(q1->getFirstChild()->getLeftSibling());
					nextRightNode->getLeftSibling()->setRightSibling(nextRightNode);
					q1->getFirstChild()->setLeftSibling(nextRightNode);
					nextRightNode->setRightSibling(NULL);
				}
				q1->setOrder(q1->getOrder() + 1);
			}
			else
			{
				if (q1->getOrder() == 0){
					nextRightNode->setFirstChild(q1);
					nextRightNode->setLeftSibling(q1->getLeftSibling());
					if (nextRightNode->getLeftSibling() != nextRightNode)
					{
						nextRightNode->getLeftSibling()->setRightSibling(q1);
					}
					q1->setRightSibling(NULL);
					q1->setLeftSibling(q1);
				}
				else
				{
					nextRightNode->setLeftSibling(q1->getLeftSibling());
					if (nextRightNode->getLeftSibling()->getRightSibling() == q1)
					{
						nextRightNode->getLeftSibling()->setRightSibling(nextRightNode);
					}
					q1->setLeftSibling(nextRightNode->getFirstChild()->getLeftSibling());
					q1->getLeftSibling()->setRightSibling(q1);
					nextRightNode->getFirstChild()->setLeftSibling(q1);
					q1->setRightSibling(NULL);
				}
				nextRightNode->setOrder(nextRightNode->getOrder() + 1);
				q1 = nextRightNode;
				if (q1->getLeftSibling()->getRightSibling() == NULL)
				{
					BinomialQueueRoot = q1;
				}
			}
		}
	}
}


/*
* Insert an new entry into the Leftist Heap
* @param newItem   the value of new entry
*/
void BinomialQueueOperation::insert(int newItem)
{
	BinomialNode* newNode = new BinomialNode(newItem);
	newNode->setLeftSibling(newNode);
	merge(BinomialQueueRoot, newNode);	
}


/*
* Delete the smallest value from the Leftist Heap
*/
void BinomialQueueOperation::deletemin()
{
	BinomialNode* minNode = BinomialQueueRoot;
	if (BinomialQueueRoot == NULL)
	{
		cout << "Empty Queue!" << endl;
	}
	else
	{
		BinomialNode* rightNode = BinomialQueueRoot->getRightSibling();
		while (rightNode != NULL)
		{
			if (rightNode->getItem() < minNode->getItem())
			{
				minNode = rightNode;
			}
			rightNode = rightNode->getRightSibling();
		}
		if ((minNode->getLeftSibling()->getRightSibling() == NULL) && (minNode->getRightSibling() == NULL))
		{
			BinomialQueueRoot = NULL;
		}
		else if (minNode->getRightSibling() == NULL)
		{
			BinomialQueueRoot->setLeftSibling(minNode->getLeftSibling());
			minNode->getLeftSibling()->setRightSibling(NULL);
		}
		else if (minNode->getLeftSibling()->getRightSibling() == NULL)
		{
			BinomialQueueRoot = minNode->getRightSibling();
			minNode->getRightSibling()->setLeftSibling(minNode->getLeftSibling());
		}
		else
		{	
			minNode->getLeftSibling()->setRightSibling(minNode->getRightSibling());
			minNode->getRightSibling()->setLeftSibling(minNode->getLeftSibling());
		}
		BinomialNode* minNodeFirstChild = minNode->getFirstChild();
		while (minNodeFirstChild != NULL)
		{
			BinomialNode* bufNode = minNodeFirstChild->getRightSibling();
			minNodeFirstChild->setLeftSibling(minNodeFirstChild);
			minNodeFirstChild->setRightSibling(NULL);
			merge(BinomialQueueRoot, minNodeFirstChild);
			minNodeFirstChild = bufNode;
		}
		delete minNode;
	}
}


/*
* print out all the elements of the Binomial queue using level order traversal(each level in one line)
*/
/*
void BinomialQueueOperation::levelorder()
{
	if (BinomialQueueRoot != NULL)
	{
		QueueOperation newQueue;
		BinomialNode* descendant = BinomialQueueRoot;
		BinomialNode* temp = new BinomialNode();
		temp->setItem(0);
		newQueue.enqueue(BinomialQueueRoot);
		newQueue.enqueue(temp);
		while (!newQueue.isEmpty())
		{
			BinomialNode* tempNode = newQueue.dequeue();
			if ((!newQueue.isEmpty()) && (tempNode->getItem() == 0))
			{
				BinomialNode* bufNode = new BinomialNode();
				bufNode->setItem(0);
				newQueue.enqueue(bufNode);
			}
			else if (tempNode->getFirstChild() != NULL)
			{
				BinomialNode* tempPtr = tempNode->getFirstChild();
				newQueue.enqueue(tempPtr);
				while (tempPtr->getRightSibling() != NULL)
				{
					tempPtr = tempPtr->getRightSibling();
					newQueue.enqueue(tempPtr);
				}	
			}
			if (tempNode->getItem() != 0)
			{
				cout << tempNode->getItem() << " ";
			}
			else
			{
				delete tempNode;
				cout << endl;
			}
		}
		while (descendant->getRightSibling() != NULL)
		{
			descendant = descendant->getRightSibling();
			cout << "---" << endl;
			if (descendant != NULL)
			{
				newQueue.enqueue(descendant);
				BinomialNode* temp = new BinomialNode();
				temp->setItem(0);
				newQueue.enqueue(temp);
			}
			while (!newQueue.isEmpty())
			{
				BinomialNode* tempNode = newQueue.dequeue();
				if ((!newQueue.isEmpty()) && (tempNode->getItem() == 0))
				{
					BinomialNode* bufNode = new BinomialNode();
					bufNode->setItem(0);
					newQueue.enqueue(bufNode);
				}
				else if (tempNode->getFirstChild() != NULL)
				{
					BinomialNode* tempPtr = tempNode->getFirstChild();
					newQueue.enqueue(tempPtr);
					while (tempPtr->getRightSibling() != NULL)
					{
						tempPtr = tempPtr->getRightSibling();
						newQueue.enqueue(tempPtr);
					}
				}
				if (tempNode->getItem() != 0)
				{
					cout << tempNode->getItem() << " ";
				}
				else
				{
					delete tempNode;
					cout << endl;
				}
			}
		}
	}
}*/


/*
* Combine all functions to execute the program
*/
/*
void BinomialQueueOperation::finalOutput()
{
	cout << "Welcome to use my program!\n" << endl;
	int index = 0;
	readfile();

	while (index != 4)
	{
		cout << "..............................................." << endl;
		cout << "Please choose one of the following commands: " << endl;
		cout << "1 - insert\n2 - deletemin\n3 - levelorder\n4 - exit\n" << endl;
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
			deletemin();
			cout << endl;
		}

		if (index == 3)
		{
			cout << "Level order: " << endl;
			levelorder();
			cout << endl;
		}

		if ((index < 1) || (index > 4))
		{
			cout << "Ooooops, typo! Please type the number 1 to 8." << endl;
		}
	}
	cout << "\nThank you for using my program!\n" << endl;
}*/