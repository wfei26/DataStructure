/**********************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 02/12/14
*File: HashOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab3 - Closed Hashing with Open Addressing
***********************************************************/

#include "HashOperation.h"
using namespace std;


/*
* Default constructor
* @param tableSize    the size of hash table 
*/
HashOperation::HashOperation()
{
	tableSize = 0;
	currentSize = 0;
}


/*
* Destructor
*/
HashOperation::~HashOperation()
{
	delete[] closeHashTable;
}


/*
* Read all item entries from the file and insert them into closed hash table
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
		if (file >> newEntry)
		{
			tableSize = newEntry;
		}
		closeHashTable = new HashTable[tableSize];

		while (file >> newEntry)
		{
			//to avoid duplicating, we need to check if the hash table exists same number as new item
			if (!contains(newEntry))
			{
				insert(newEntry);
			}
		}
	}
	file.close();   //close file
}


/*
* Insert new entry into the hash table by using closed hashing algorithm
* @param newItem   the value of new entry
* @return true     if the item is inserted successfully
*         false    if the item is not inserted successfully
*/
bool HashOperation::insert(const int newItem)
{
	int pos = 0;
	if (isfull())
	{
		cout << "\nSorry, the table is full.";
		return false;
	}
	else
	{
		for (int i = 0; i < tableSize; i++)
		{
			//use hashing algorithm to insert every new item
			pos = hash(i, newItem);
			if (closeHashTable[pos].getItem() == -1)
			{
				closeHashTable[pos].setItem(newItem);   //set value
				closeHashTable[pos].setFlag(false);     //set flag
				currentSize++;
				return true;
			}
		}
	}
	return false;
}


/*
* Remove the key from the hash table by using quadratic searching
* @param delItem   the value of delete entry
* @return true     if the item is deleted successfully
*         false    if the item is not deleted successfully
*/
bool HashOperation::remove(const int delItem)
{
	int pos = 0;
	if (!contains(delItem))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < tableSize; i++)
		{
			pos = hash(i, delItem);

			//if the bucket is empty and flag is false, it means bucket is always empty, searching terminates
			if ((closeHashTable[pos].getItem() == -1) && (closeHashTable[pos].getFlag() == false))
			{
				return false;
			}
			else if (closeHashTable[pos].getItem() == delItem)
			{
				closeHashTable[pos].setItem(-1);     //set the value as -1 means empty
				closeHashTable[pos].setFlag(true);	 //set the flag as true means it is deleted
				currentSize--;
				return true;
			}
		}
	}
	return false;
}


/*
* Print out all the elements of the hash table
*/
void HashOperation::print()
{
	for (int i = 0; i < tableSize; i++)
	{
		if (closeHashTable[i].getFlag() == true)
		{
			cout << i << ": " << closeHashTable[i].getItem() << " flag =true" << endl;
		}
		else
		{
			cout << i << ": " << closeHashTable[i].getItem() << " flag =false" << endl;
		}
	}
	cout << "\n";
}


/*
* Use hi(x) = (h(x) +i^2)% m for quadratic probing
* @param i             parameter in closed hashing algorithm
* @param newItem       the value of new item
* @return hashResult   the array index of new item in hash table
*/
int HashOperation::hash(int i, const int newItem)
{
	int hashValue = newItem % tableSize;
	int hashResult = (hashValue + i * i) % tableSize;
	return hashResult;
}


/*
* Check if the hash table contains the item
* @param newItem   the value of new item to be checked
* @return true     if the key x is in the hash table
*         false	   if the key x is not in the hash table
*/
bool HashOperation::contains(const int newItem)
{
	int pos = 0;
	for (int i = 0; i < tableSize; i++)
	{
		pos = hash(i, newItem);
		if (closeHashTable[pos].getItem() == newItem)
		{
			return true;
		}

		//if the bucket is empty and flag is false, it means bucket is always empty, searching terminates
		else if ((closeHashTable[pos].getItem() == -1) && (closeHashTable[pos].getFlag() == false))
		{
			return false;
		}
	}
	return false;
}


/*
* Check if the hash table if full
* @return true    if the hash table is full
*         false	  if the hash table is not full
*/
bool HashOperation::isfull()
{
	if (currentSize == tableSize)
	{
		return true;
	}
	else
	{
		return false;
	}
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
		cout << ".................................................................." << endl;
		cout << "Please choose one of the following commands: " << endl;
		cout << "1 - insert\n2 - delete\n3 - print\n4 - exit\n" << endl;
		cout << "Your choice: ";
		cin >> index;
		
		if (index == 1)
		{
			int newItem = 0;
			cout << "Which number do you want to insert into the hash table?" << endl;
			cin >> newItem;
			if (!contains(newItem))
			{
				//to avoid duplicate
				bool ableToInsert = insert(newItem);
				if (!ableToInsert)
				{
					cout << " The insertion is failed!\n" << endl;
				}
				else
				{
					cout << " ";
				}
			}
			else
			{
				cout << "\nThe number has already existed in the hash table, please re-make your choice!\n" << endl;
			}
		}	
		else if (index == 2)
		{
			int delItem = 0;
			cout << "Which number do you want to remove from the hash table?" << endl;
			cin >> delItem;
			bool ableToRemove = remove(delItem);
			if (!ableToRemove)
			{
				cout << "\nSorry, the removal is failed! The number may do not exist in the hash table\n" << endl;
			}
			else
			{
				cout << " ";
			}
		}
		else if (index == 3)
		{
			cout << "output for quadratic:\n" << endl;
			print();
		}
		if ((index != 1) && (index != 2) && (index != 3) && (index != 4))
		{
			cout << "\nPlease make your choice with No. 1 to 4. Thank you!\n" << endl;
		}
	}
	cout << "\nThank you for using my program!\n" << endl;
}