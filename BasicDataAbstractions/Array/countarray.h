/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/27/13
 * FileName: countarray.h
 * Description: the header file of countarray.cpp.
 */


#ifndef COUNT_ARRAY_H
#define COUNT_ARRAY_H

#include "count.h"

/**
 * This class maintains a dynamic array of count objects.
 */
template <typename T>
class CountArray {
private:
	/**
	 * Pointer to the array
	 */
	Count<T> *array;
	/**
	 * Size of the array
	 */	int arraySize;
	/**
	 * Number of items stored in the array
	 */
	int numItemsStored;

public:
	/**
	 * Default constructor
	 */
	CountArray();
	
	/**
	 * Copy constructor
	 *
	 * @param countArr the CountArray to copy from
	 */
	CountArray(const CountArray<T>& countArr);

	/**
	 * Destructor
	 */
	~CountArray();

	/**
	 * Bumps the count of the given item
	 *
	 * @param t the given item
	 */
	void bumpCount(T t);

	/**
	 * Returns the number of items stored in the array
	 *
	 * @return the number of items stored in the array
	 */
	int getNumItemsStored() const;

	/**
	 * Returns the item at the given index
	 *
	 * @param whichItem the index of item
	 * @return the item at the given index
	 */
	Count<T> getItem(int whichItem) const;
};

#include "countarray.cpp"
#endif
