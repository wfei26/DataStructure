/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/05/14
*File: HashOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab2 - Open Hashing with Separate Chaining
***********************************************************/

#include "HashOperation.h"
using namespace std;

/*
* Constructor with the size of list and the position of node
* @param tableSize     the size of hash table
* @param position     the position of an exact node
*/
HashOperation::HashOperation()
{
	position = 0; //count the position of an exact node
	tableSize = 0;
}


/*
* Destructor
*/
HashOperation::~HashOperation()
{
	//Node* curPtr = NULL;
	for (int i = 0; i < tableSize; i++)
	{
		/*
		curPtr = hashTable[i];
		while (curPtr->getNext() != NULL)
		{
			Node* postPtr = curPtr->getNext();
			delete curPtr;
			curPtr = postPtr;
		}*/
		delete hashTable[i];
		hashTable[i] = NULL;
	}
}


/*
* Read all item entries from the file and insert them into each node to combine a list
*/
void HashOperation::readfile()
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
		
		//read first number from file as the size of hash table
		if (file >> newEntry)
		{
			tableSize = newEntry;
		}

		//dynamically allocate memory for hash table
		hashTable = new Node* [tableSize];

		//set the head pointer of each list as null pointer in hash table
		for (int i = 0; i < tableSize; i++)
		{
			hashTable[i] = NULL;
		}

		//read each number and insert them into list one by one
		while (file >> newEntry)
		{
			if (!find(newEntry))
			{
				insert(newEntry);
			}
		}
	}
}


/*
* Insert new entry into the end of the correct list in hash table
* @param newItem   the value of new entry
*/
int HashOperation::hash(int newItem)
{
	//hashing algorithm implementation
	int list_pos = newItem % tableSize;
	return list_pos;
}


/*
* Insert new entry into the end of the correct list in hash table
* @param newItem   the value of new entry
*/
void HashOperation::insert(const int newItem)
{
	Node* curPtr = hashTable[hash(newItem)];

	//constructor for new node
	Node* newNode = new Node(newItem);

	//check if the exact list is empty
	if (curPtr == NULL)
	{
		hashTable[hash(newItem)] = newNode;
	}

	//if the list is not empty, insert new node at the end of the list
	else
	{
		while (curPtr->getNext() != NULL)
		{
			curPtr = curPtr->getNext();
		}
		curPtr->setNext(newNode);
	}
}


/*
* Check if the hash table is empty
* @return    true if the hash table is empty
*            false if the hash table is not empty
*/
bool HashOperation::isEmpty()
{
	int counter = 0;
	for (int i = 0; i < tableSize; i++)
	{
		if (hashTable[i] == NULL)
		{
			counter++;
		}
	}
	if (counter == tableSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*
* Delete the exact node from the the correct list in hash table
* @param deleteItem   the value of delete entry
*/
void HashOperation::remove(int newItem)
{
	//check if the input number exist in hash table
	if (find(newItem))
	{
		//initialize current pointer into the head pointer of the list of input item by using hashing algorithm
		Node* curPtr = hashTable[hash(newItem)];
		Node* tempPtr = NULL;

		if (curPtr->getItem() != newItem)
		{
			while (curPtr->getNext()->getItem() != newItem)
			{
				curPtr = curPtr->getNext();
			}

			//save the pointer that need to be deleted in a temporary pointer
			tempPtr = curPtr->getNext();

			//connect current pointer with next and next pointer
			curPtr->setNext(curPtr->getNext()->getNext());
			delete tempPtr;
			tempPtr = NULL; 
		}
		else
		{
			//set next pointer as new head pointer for current list 
			hashTable[hash(newItem)] = curPtr->getNext();
			delete curPtr;
			curPtr = NULL;
		}
	}

	//if the input number does not exist, output error
	else 
	{
		cout << "\n";
		cout << "The number does not exist in the hash table, please make your choice again!\n" << endl;
	}
}


/*
* Print the whole hash table
*/
void HashOperation::print()
{
	Node* curPtr;
	for (int i = 0; i < tableSize; i++)
	{
		cout << "\n";
		cout << i << ": ";
		curPtr = hashTable[i];
		if (curPtr == NULL)
		{
			cout << " ";
		}
		else
		{
			while (curPtr != NULL)
			{
				cout << curPtr->getItem() << " ";
				curPtr = curPtr->getNext();
			}
		}
	}
	cout << "\n\n";
}


/*
* Recursively find the item we need
* @param newItem   the value of the item we want to find
* @return true     if find the item
*		  false    if do not find it
*/
bool HashOperation::find(const int newItem)
{
	Node* curPtr = hashTable[hash(newItem)];
	while (curPtr != NULL)
	{
		if (curPtr->getItem() != newItem)
		{
			curPtr = curPtr->getNext();
		}
		else
		{
			return true;
		}
	}
	return false;
}


/*
* Combine all functions to execute the program
*/
void HashOperation::finalOutput()
{
	cout << "\nWelcome to use my program!\n" << endl;
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
			if (!find(newInsertItem))
			{
				insert(newInsertItem);
			}
			else
			{
				cout << "The number is existing in the hash table, please make your choice again!" << endl;
			}
		}

		if (index == 2)
		{
			int deleteNum;
			cout << "Choose a number to be deleted from the list:" << endl;
			cin >> deleteNum;
			remove(deleteNum);
			
		}

		if (index == 3)
		{
			print();
		}
		if ((index != 1) && (index != 2) && (index != 3) && (index != 4))
		{
			cout << "Please make your choice with No. 1 to 4. Thank you!" << endl;
		}
	}
	cout << "\nThank you for using my program!\n" << endl;
}
