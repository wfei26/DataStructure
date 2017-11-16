/************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/02/15
*File: SkewHeapOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab8 - Comparing the Performance Difference Between Leftist Heap and Skew Heap
*************************************************************************/

#include "SkewHeapOperation.h"
using namespace std;

/*
* Default constructor
*/
SkewHeapOperation::SkewHeapOperation()
{
	SkewHeap = NULL;
}


/*
* Destructor
*/
SkewHeapOperation::~SkewHeapOperation()
{
}


/*
* Read all item entries from the file and insert them into the Skew Heap
*/
void SkewHeapOperation::readfile()
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


/*
* Merge two heaps into one heap
* @param h1   the first heap
* @param h2   the second heap
*/
HeapNode* SkewHeapOperation::concate(HeapNode* h1, HeapNode* h2)
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
	HeapNode* tempNode = h1->getRightChild();
	h1->setRightChild(h1->getLeftChild());
	h1->setLeftChild(concate(tempNode, h2));
	return h1;
}


/*
* Insert an new entry into the Skew Heap
* @param newItem   the value of new entry
*/
void SkewHeapOperation::insert(int newItem)
{
	HeapNode* newHeapNode = new HeapNode(newItem);
	SkewHeap = concate(SkewHeap, newHeapNode);
}


/*
* Delete the smallest value from the Skew Heap
*/
void SkewHeapOperation::deletemin()
{
	HeapNode* leftChild = NULL;
	HeapNode* rightChild = NULL;
	if (SkewHeap == NULL)
	{
		cout << "Empty Heap. No more items can be removed!" << endl;
	}
	else
	{
		leftChild = SkewHeap->getLeftChild();
		rightChild = SkewHeap->getRightChild();
		delete SkewHeap;
		SkewHeap = concate(leftChild, rightChild);
	}
}


/*
* Print out all the elements of the Skew Heap by using preorder
*/
void SkewHeapOperation::preorder(HeapNode* curPtr)
{
	if (curPtr != NULL)
	{
		cout << curPtr->getItem() << " ";
		preorder(curPtr->getLeftChild());
		preorder(curPtr->getRightChild());
	}
}


/*
* Print out all the elements of the Skew Heap by using inorder
*/
void SkewHeapOperation::inorder(HeapNode* curPtr)
{
	if (curPtr != NULL)
	{
		inorder(curPtr->getLeftChild());
		cout << curPtr->getItem() << " ";
		inorder(curPtr->getRightChild());
	}
}


/*
* Print out all the elements of the Skew Heap by using level order
*/
void SkewHeapOperation::levelorder()
{
	if (SkewHeap == NULL)
	{
		cout << "Empty Heap!" << endl;;
		return;
	}
	else
	{
		QueueOperation myQueue;
		myQueue.enqueue(SkewHeap);
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


/*
* Combine all functions to execute the program
*/
void SkewHeapOperation::finalOutput()
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
			preorder(SkewHeap);
			cout << endl;
		}

		if (index == 4)
		{
			cout << "inorder: " << endl;
			inorder(SkewHeap);
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
