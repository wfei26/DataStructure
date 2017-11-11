/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 03/30/15
*File: MinMaxHeapOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab7 - Min-Max Heap
*****************************************/

#include "MinMaxHeapOperation.h"
using namespace std;


/*
* Default constructor
*/
MinMaxHeapOperation::MinMaxHeapOperation()
{
	size = 0;
	for (int i = 0; i < 100; i++)
	{
		MinMaxHeap[i] = -1;
	}
}


/*
* Destructor
*/
MinMaxHeapOperation::~MinMaxHeapOperation()
{
	for (int i = 0; i < size + 1; i++)
	{
		MinMaxHeap[i] = -1;
	}
}


/*
* Read all item entries from the file and insert them into the MinMaxHeap
*/
void MinMaxHeapOperation::readfile()
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
			MinMaxHeap[size + 1] = newEntry;
			size++;
		}
		
		/*for (int i = 0; i < size; i++)
		{
			cout << MinMaxHeap[i] << " ";
		}
		cout << endl;*/
		
		CreateHeap(size + 1);
		
		/*for (int i = 0; i < size; i++)
		{
			cout << MinMaxHeap[i] << " ";
		}
		cout << endl;*/
	}
	file.close();
}


/*
* Create new Heap by using TrickleDown method
*/
void MinMaxHeapOperation::CreateHeap(const int mysize)
{
	for (int i = mysize / 2; i >= 1; i--)
	{
		TrickleDown(i);
	}
}


/*
* Check if a tree node has children
* @param pos   the index number of the checked item
*/
bool MinMaxHeapOperation::hasChildren(int pos)
{
	if ((MinMaxHeap[2 * pos]) != -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*
* Get the value of current level of checked item
* @param pos       the index number of the checked item
* @return level    the value of current level of checked item
*/
int MinMaxHeapOperation::getLevel(int pos)
{
	int level = (int)log2(pos);
	return level;
}


/*
* Search the current position of checked item
* @param newItem      the value of checked item
* @return i			  the index number of the checked item
*/
int MinMaxHeapOperation::searchNumber(const int newItem)
{
	for (int i = 0; i < size + 1; i++)
	{
		if (MinMaxHeap[i] == newItem)
		{
			return i;
		}
	}
}


/*
* To be used for building the heap(bottom up approach, delete min and delete max)
* @param level    the current level of checked item
*/
void MinMaxHeapOperation::TrickleDown(int i)
{
	if (((int)(log2(i))) % 2 == 0)
	{
		TrickleDownMin(i);
	}
	else
	{
		TrickleDownMax(i);
	}
}


/*
* To be used for building the heap and delete operation
* @param index    the current index number of checked item
*/
void MinMaxHeapOperation::TrickleDownMin(int index)
{
	if (hasChildren(index))
	{
		int minIndex = 0;
		int minNum = MinMaxHeap[index * 2];
		minIndex = index * 2;
		if ((MinMaxHeap[index * 2 + 1]) != -1)
		{
			if (minNum > MinMaxHeap[index * 2 +1])
			{
				minNum = MinMaxHeap[index * 2 + 1];
				minIndex = index * 2 + 1;
			}
		}
		if ((MinMaxHeap[index * 2 * 2]) != -1)
		{
			if (minNum > MinMaxHeap[index * 2 * 2])
			{
				minNum = MinMaxHeap[index * 2 * 2];
				minIndex = index * 2 * 2;
			}
		}
		if ((MinMaxHeap[index * 2 * 2 + 1]) != -1)
		{
			if (minNum > MinMaxHeap[index * 2 * 2 + 1])
			{
				minNum = MinMaxHeap[index * 2 * 2 + 1];
				minIndex = index * 2 * 2 + 1;
			}
		}
		if ((MinMaxHeap[index * 2 * 2 + 2]) != -1)
		{
			if (minNum > MinMaxHeap[index * 2 * 2 + 2])
			{
				minNum = MinMaxHeap[index * 2 * 2 + 2];
				minIndex = index * 2 * 2 + 2;
			}
		}
		if ((MinMaxHeap[index * 2 * 2 + 3]) != -1)
		{
			if (minNum > MinMaxHeap[index * 2 * 2 + 3])
			{
				minNum = MinMaxHeap[index * 2 * 2 + 3];
				minIndex = index * 2 * 2 + 3;
			}
		}
		if ((minIndex >= index * 2 * 2))
		{
			if (MinMaxHeap[minIndex] < MinMaxHeap[index])
			{
				swap(MinMaxHeap[index], MinMaxHeap[minIndex]);
				if (MinMaxHeap[minIndex] > MinMaxHeap[(int)(minIndex / 2)])
				{
					swap(MinMaxHeap[minIndex], MinMaxHeap[(int)(minIndex / 2)]);
				}
				TrickleDownMin(minIndex);
			}
		}
		else
		{
			if (MinMaxHeap[minIndex] < MinMaxHeap[index])
			{
				swap(MinMaxHeap[index], MinMaxHeap[minIndex]);
			}
		}
	}
}


/*
* To be used for building the heap and delete operation
* @param index    the current index number of checked item
*/
void MinMaxHeapOperation::TrickleDownMax(int index)
{
	if (hasChildren(index))
	{
		int maxIndex = 0;
		int maxNum = MinMaxHeap[index * 2];
		maxIndex = index * 2;
		if ((MinMaxHeap[index * 2 + 1]) != -1)
		{
			if (maxNum < MinMaxHeap[index * 2 + 1])
			{
				maxNum = MinMaxHeap[index * 2 + 1];
				maxIndex = index * 2 + 1;
			}
		}
		if ((MinMaxHeap[index * 2 * 2]) != -1)
		{
			if (maxNum < MinMaxHeap[index * 2 * 2])
			{
				maxNum = MinMaxHeap[index * 2 * 2];
				maxIndex = index * 2 * 2;
			}
		}
		if ((MinMaxHeap[index * 2 * 2 + 1]) != -1)
		{
			if (maxNum < MinMaxHeap[index * 2 * 2 + 1])
			{
				maxNum = MinMaxHeap[index * 2 * 2 + 1];
				maxIndex = index * 2 * 2 + 1;
			}
		}
		if ((MinMaxHeap[index * 2 * 2 + 2]) != -1)
		{
			if (maxNum < MinMaxHeap[index * 2 * 2 + 2])
			{
				maxNum = MinMaxHeap[index * 2 * 2 + 2];
				maxIndex = index * 2 * 2 + 2;
			}
		}
		if ((MinMaxHeap[index * 2 * 2 + 3]) != -1)
		{
			if (maxNum < MinMaxHeap[index * 2 * 2 + 3])
			{
				maxNum = MinMaxHeap[index * 2 * 2 + 3];
				maxIndex = index * 2 * 2 + 3;
			}
		}
		if ((maxIndex >= index * 2 * 2))
		{
			if (MinMaxHeap[maxIndex] > MinMaxHeap[index])
			{
				swap(MinMaxHeap[index], MinMaxHeap[maxIndex]);
				if (MinMaxHeap[maxIndex] < MinMaxHeap[(int)(maxIndex / 2)])
				{
					swap(MinMaxHeap[maxIndex], MinMaxHeap[(int)(maxIndex / 2)]);
				}
				TrickleDownMax(maxIndex);
			}
		}
		else
		{
			if (MinMaxHeap[maxIndex] > MinMaxHeap[index])
			{
				swap(MinMaxHeap[index], MinMaxHeap[maxIndex]);
			}
		}
	}
}


/*
* To be used for insert
* @param index    the current index number of checked item
*/
void MinMaxHeapOperation::BubbleUp(int index)
{
	if (getLevel(index) % 2 == 0)
	{
		if ((MinMaxHeap[(int)(index / 2)] != -1) && (MinMaxHeap[index] > MinMaxHeap[(int)(index / 2)]))
		{
			swap(MinMaxHeap[index], MinMaxHeap[(int)(index / 2)]);
			BubbleUpMax((int)(index / 2));
		}
		else
		{
			BubbleUpMin(index);
		}
	}
	else
	{
		if ((MinMaxHeap[(int)(index / 2)] != -1) && (MinMaxHeap[index] < MinMaxHeap[(int)(index / 2)]))
		{
			swap(MinMaxHeap[index], MinMaxHeap[(int)(index / 2)]);
			BubbleUpMin((int)(index / 2));
		}
		else
		{
			BubbleUpMax(index);
		}
	}
}


/*
* To be used for insert
* @param index    the current index number of checked item
*/
void MinMaxHeapOperation::BubbleUpMin(int index)
{
	if ((MinMaxHeap[int(index / 2 / 2)]) != -1)
	{
		if (MinMaxHeap[index] < MinMaxHeap[int(index / 2 / 2)])
		{
			swap(MinMaxHeap[index], MinMaxHeap[int(index / 2 / 2)]);
			BubbleUpMin(int(index / 2 / 2));
		}
	}
}


/*
* To be used for insert
* @param index    the current index number of checked item
*/
void MinMaxHeapOperation::BubbleUpMax(int index)
{
	if ((MinMaxHeap[int(index / 2 / 2)]) != -1)
	{
		if (MinMaxHeap[index] > MinMaxHeap[int(index / 2 / 2)])
		{
			swap(MinMaxHeap[index], MinMaxHeap[int(index / 2 / 2)]);
			BubbleUpMax(int(index / 2 / 2));
		}
	}
}


/*
* Insert new entry into the MinMaxHeap by using the BubbleUp method
* @param newItem   the value of new entry
*/
void MinMaxHeapOperation::insert(const int newItem)
{
	MinMaxHeap[size + 1] = newItem;
	BubbleUp(size + 1);
	size++;
}


/*
* Delete the smallest value from the MinMaxHeap
*/
void MinMaxHeapOperation::deletemin()
{
	if (size <= 0)
	{
		cout << "Error! Empty Heap!" << endl;
	}
	else
	{
		if (size == 1)
		{
			MinMaxHeap[1] = -1;
			size--;
		}
		else if (size == 2)
		{
			MinMaxHeap[1] = MinMaxHeap[2];
			MinMaxHeap[2] = -1;
			size--;
		}
		else
		{
			MinMaxHeap[1] = MinMaxHeap[size];
			MinMaxHeap[size] = -1;
			size--;
			TrickleDownMin(1);
		}
	}
}


/*
* Delete the largest value from the MinMaxHeap
*/
void MinMaxHeapOperation::deletemax()
{
	if (size <= 0)
	{
		cout << "Error! Empty Heap!" << endl;
	}
	else
	{
		if (size == 1)
		{
			MinMaxHeap[1] = -1;
			size--;
		}
		else if (size == 2)
		{
			MinMaxHeap[2] = -1;
			size--;
		}
		else
		{
			int tempIndex = 2;
			if (MinMaxHeap[tempIndex] < MinMaxHeap[tempIndex + 1])
			{
				MinMaxHeap[tempIndex + 1] = MinMaxHeap[size];
				MinMaxHeap[size] = -1;
				size--;
				TrickleDownMax(tempIndex + 1);
			}
			else
			{
				MinMaxHeap[tempIndex] = MinMaxHeap[size];
				MinMaxHeap[size] = -1;
				size--;
				TrickleDownMax(tempIndex);
			}
		}
	}
}


/*
* Print out all the elements of the MinMaxHeap using level order
*/
void MinMaxHeapOperation::levelorder()
{
	if (size <= 0)
	{
		cout << "Error! Empty Heap!";
	}
	else
	{
		int end = 1;
		for (int i = 1; i < size + 1; i++)
		{
			cout << MinMaxHeap[i] << " ";
			if (i == end)
			{
				end = end * 2 + 1;
				cout << endl;
			}
		}
	}
}


/*
* Combine all functions to execute the program
*/
void MinMaxHeapOperation::finalOutput()
{
	cout << "Welcome to use my program!\n" << endl;
	int index = 0;
	readfile();

	while (index != 5)
	{
		cout << "..............................................." << endl;
		cout << "Please choose one of the following commands: " << endl;
		cout << "1 - insert\n2 - deletemin\n3 - deletemax\n4 - levelorder\n5 - exit\n" << endl;
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
			deletemax();
			cout << endl;
		}

		if (index == 4)
		{
			cout << "Level order: " << endl;
			levelorder();
			cout << "\n" << endl;
		}

		if ((index < 1) || (index > 5))
		{
			cout << "Ooooops, typo! Please type the number 1 to 8." << endl;
		}
	}
	cout << "\nThank you for using my program!\n" << endl;
}