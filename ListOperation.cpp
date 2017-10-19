/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 01/31/14
*File: ListOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab1 - Designing a class for a singly linked list
***********************************************************/

#include "ListOperation.h"
using namespace std;

/*
* Constructor with the size of list and the position of node
* @param listSize     the size of list
* @param position     the position of an exact node
*/
ListOperation::ListOperation()
{
	position = 0; //count the position of an exact node
	listSize = 0; //count number of nodes in list
}


/*
* Destructor
*/
ListOperation::~ListOperation()
{
	while (listSize > 0)
	{
		Node* postPtr = headPtr->getNext();
		delete headPtr;
		headPtr = postPtr;
		listSize--;
	}
}


/*
* Read all item entries from the file and insert them into each node to combine a list
* @return headPtr     the headPtr can access all information of the whole list
*/
Node* ListOperation::readfile()
{
	ifstream file;
	file.open("data.txt");
	if (!file)
	{
		cout << "Error! File does not exist." << endl;
	}
	else
	{
		int x;

		//read each number and insert them into list one by one
		while (file >> x)
		{
			insert(x);
		}
	}
	file.close();
	return headPtr;
}


/*
* Get the node by passing the position of node
* @param pos   the position of the node 
* @return      current pointer of the node of this position
*/
Node* ListOperation::getNodeAt(int pos)
{
	Node* curPtr = headPtr;
	for(int i = 1; i < pos; i++)
	{
		curPtr = curPtr->getNext();
	}
	return curPtr;
}


/*
* Insert new entry into the end of the list
* @param newItem   the value of new entry
* @return          the head pointer of the whole list
*/
Node* ListOperation::insert(const int newItem)
{
	//get new memory in order to assign to headPtr
	Node* newNode = new Node(newItem);

	//check if the list is empty
	if (headPtr == NULL)
	{
		headPtr = newNode;
		headPtr->setNext(NULL);
		listSize++;
	}
	else
	{
		//if the list is not empty, insert new node at the end of the list
		Node* prevPtr = getNodeAt(listSize);
		prevPtr->setNext(newNode);
		listSize++;
	}
	return headPtr;
}


/*
* Check if the list is empty
* @return    true if the list is empty
*            false if the list is not empty
*/
bool ListOperation::isEmpty()
{
	if (headPtr == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*
* Delete the exact node from the list
* @param deleteItem   the value of delete entry
* @param curPtr       usually pass head pointer in order to find the delete node recursively
*/
void ListOperation::erase(const int deleteItem, Node* curPtr)
{
	curPtr = find(deleteItem, curPtr);
	//if the tester type a number not in the list, show error
	if (curPtr == NULL)
	{
		cout << "Please re-make your choice!" << endl;
		position = 0;
	}
	else
	{
		//if the delete number if in the head node
		if (position == 1)
		{
			curPtr = headPtr->getNext();
			delete headPtr;
			headPtr = curPtr;
		}
		else if ((curPtr->getNext() != NULL) && (position > 1))
		{
			//set previous pointer and post pointer of delete pointer
			Node* prevPtr = getNodeAt(position - 1);
			Node* postPtr = prevPtr->getNext()->getNext();
			//connect previous pointer and post pointer
			prevPtr->setNext(postPtr);
			//delete current pointer
			delete curPtr;
			curPtr = NULL;
		}
		//if the delete number is at the end of the list
		else
		{
			delete curPtr;
			Node* prevPtr = getNodeAt(position - 1);
			prevPtr->setNext(NULL);
			curPtr = NULL;
		}
		position = 0;
		listSize--;
	}
}


/*
* Print the whole list 
* @param curPtr   pass current pointer to print each node recursively
*/
void ListOperation::print(Node* curPtr)
{
	if (curPtr == NULL)
	{
		cout << " " << endl;
	}
	else
	{
		cout << curPtr->getItem() << " ";
		//print each node recursively
		print(curPtr->getNext());
	}
}


/*
* Recursively find the item we need
* @param newItem   the value of the item we want to find
* @param curPtr    pass current pointer in order to recursively find the node we want
* @return          the pointer that points the item we want to find
*/
Node* ListOperation::find(const int newItem, Node* curPtr)
{
	//if the program cannot find the item in list
	if (curPtr == NULL)
	{
		cout << "No such item can be found!" << endl;
		return NULL;
	}
	else if (curPtr->getItem() == newItem)
	{
		position++;
		return curPtr;
	}
	else
	{
		position++;
		//find each node recursively
		find(newItem, curPtr->getNext());
	}
}


/*
* Combine all functions to execute the program
*/
void ListOperation::finalOutput()
{
	cout << "Welcome to use my program!\n" << endl;
	int index = 0;
	readfile();

	while (index != 4)
	{
		cout << "..............................................." << endl;
		cout << "Please choose one of the following commands: " << endl;
		cout << "1 - insert\n2 - delete\n3 - print\n4 - exit\n" << endl;
		cout << "Your choice: ";
		cin >> index;

		if (index == 1)
		{
			int newInsertItem;
			cout << "Please choose a number to be inserted to the list:" << endl;
			cin >> newInsertItem;
		    insert(newInsertItem);
		}

		if (index == 2)
		{
			//check if the list is empty
			if (isEmpty())
			{
				cout << "The list has no items can be deleted!" << endl;
			}
			else
			{
				int deleteNum;
				cout << "Choose a number to be deleted from the list:" << endl;
				cin >> deleteNum;
				erase(deleteNum, headPtr);
			}
		}

		if (index == 3)
		{
			//pass head pointer into print function in order to print the list recursively
			print(headPtr);
		}

	  	if ((index != 1) && (index != 2) && (index != 3) && (index != 4))
		{
			cout << "Ooooops, typo! Please type the number 1 to 4." << endl;
		}
	}
	cout << "\nThank you for using my program!\n" << endl;
}
