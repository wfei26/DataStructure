/********************************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/23/15
*File: LeftistHeapOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab10 - Comparing the performance of Binomial queue with Leftist Heap and Skew Heap
*********************************************************************************************/

#include "LeftistHeapOperation.h"
using namespace std;

/*
* Default constructor
*/
LeftistHeapOperation::LeftistHeapOperation()
{
	LeftistHeap = NULL;
}


/*
* Destructor
*/
LeftistHeapOperation::~LeftistHeapOperation()
{
}


/*
* Read all item entries from the file and insert them into the Leftist Heap
*/
/*
void LeftistHeapOperation::readfile()
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
}
*/


/*
* Update all value of ranks recursively
* @param curNode   the current node
*/
void LeftistHeapOperation::adjustRank(HeapNode* curNode)
{
	HeapNode* tempNode = NULL;
	if (((curNode->getLeftChild() != NULL) && (curNode->getRightChild() != NULL) 
		&& (curNode->getLeftChild()->getRank() < curNode->getRightChild()->getRank())) 
		|| ((curNode->getLeftChild() == NULL) && (curNode->getRightChild() != NULL)))
	{
		tempNode = curNode->getLeftChild();
		curNode->setLeftChild(curNode->getRightChild());
		curNode->setRightChild(tempNode);
	}
	if (curNode->getRightChild() != NULL)
	{
		curNode->setRank(curNode->getRightChild()->getRank() + 1);
	}
}


/*
* Merge two heaps into one heap
* @param h1   the first heap
* @param h2   the second heap
*/
HeapNode* LeftistHeapOperation::concate(HeapNode* h1, HeapNode* h2)
{
	if (h1 == NULL)
	{
		return h2;
	}
	else if (h2 == NULL)
	{
		return h1;
	}
	else if (h1->getItem() > h2->getItem())
	{
		swap(h1, h2);
	}
	h1->setRightChild(concate(h1->getRightChild(), h2));
	adjustRank(h1);
	return h1;
}


/*
* Insert an new entry into the Leftist Heap
* @param newItem   the value of new entry
*/
void LeftistHeapOperation::insert(int newItem)
{
	HeapNode* newHeapNode = new HeapNode(newItem, 1);
	LeftistHeap = concate(LeftistHeap, newHeapNode);
}


/*
* Delete the smallest value from the Leftist Heap
*/
void LeftistHeapOperation::deletemin()
{
	HeapNode* leftChild = NULL;
	HeapNode* rightChild = NULL;
	if (LeftistHeap == NULL)
	{
		cout << "Empty Heap. No more items can be removed!" << endl;
	}
	else
	{
		leftChild = LeftistHeap->getLeftChild();
		rightChild = LeftistHeap->getRightChild();
		delete LeftistHeap;
		LeftistHeap = concate(leftChild, rightChild);
	}
}


/*
* Print out all the elements of the Leftist Heap by using preorder
*/
/*
void LeftistHeapOperation::preorder(HeapNode* curPtr)
{
	if (curPtr != NULL)
	{
		cout << curPtr->getItem() << " ";
		preorder(curPtr->getLeftChild());
		preorder(curPtr->getRightChild());
	}
}
*/

/*
* Print out all the elements of the Leftist Heap by using inorder
*/
/*
void LeftistHeapOperation::inorder(HeapNode* curPtr)
{
	if (curPtr != NULL)
	{
		inorder(curPtr->getLeftChild());
		cout << curPtr->getItem() << " ";
		inorder(curPtr->getRightChild());
	}
}
*/

/*
* Print out all the elements of the Leftist Heap by using level order
*/
/*
void LeftistHeapOperation::levelorder()
{
	if (LeftistHeap == NULL)
	{
		cout << "Empty Heap!" << endl;;
		return;
	}
	else
	{
		QueueOperation myQueue;
		myQueue.enqueue(LeftistHeap);
		HeapNode* tempNode = new HeapNode();
		tempNode->setItem(0);
		myQueue.enqueue(tempNode);
		while (!myQueue.isEmpty())
		{
			HeapNode* curNode = myQueue.dequeue();
			if ((!myQueue.isEmpty()) && (curNode->getItem() == 0))
			{
				HeapNode* tempNode2 = new HeapNode();
				tempNode2->setItem(0);
				myQueue.enqueue(tempNode2);
			}
			if (curNode->getLeftChild() != NULL)
			{
				myQueue.enqueue(curNode->getLeftChild());
			}
			if (curNode->getRightChild() != NULL)
			{
				myQueue.enqueue(curNode->getRightChild());
			}
			if (curNode->getItem() != 0)
			{
				cout << curNode->getItem() << " ";
			}
			else
			{
				cout << endl;
				delete curNode;
			}
		}
	}
}
*/

/*
* Combine all functions to execute the program
*/
/*
void LeftistHeapOperation::finalOutput()
{
	cout << "Welcome to use my program!\n" << endl;
	int index = 0;
	readfile();

	while (index != 6)
	{
		cout << "..............................................." << endl;
		cout << "Please choose one of the following commands: " << endl;
		cout << "1 - insert\n2 - deletemin\n3 - preorder\n4 - inorder\n5 - levelorder\n6 - end\n" << endl;
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
			cout << "preorder: " << endl;
			preorder(LeftistHeap);
			cout << endl;
		}

		if (index == 4)
		{
			cout << "inorder: " << endl;
			inorder(LeftistHeap);
			cout << endl;
		}

		if (index == 5)
		{
			cout << "Level order: " << endl;
			levelorder();
			cout << endl;
		}

		if ((index < 1) || (index > 6))
		{
			cout << "Ooooops, typo! Please type the number 1 to 8." << endl;
		}
	}
	cout << "\nThank you for using my program!\n" << endl;
}
*/