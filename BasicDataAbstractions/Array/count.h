/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/27/13
 * FileName: count.h
 * Description: the header file of count.cpp.
 */


#ifndef COUNT_H
#define COUNT_H

/**
 * This class stores the pair of item and its occurrence.
 */
template <typename T>
class Count {
private:
	/**
	 * The item object
	 */
	T item;
	/**
	 * The occurrence of the item
	 */
	int count;

public:
	/**
	 * Default constructor
	 */
	Count();
	
	/**
	 * Constructs by an item object and sets count to be 1 
	 * 
	 * @param item the item object
	 */
	Count(T item);
	
	/**
	 * Copy constructor
	 *
	 * @param c the count object to copy from
	 */
	Count(const Count<T>& c);

	/**
	 * Returns the item
	 *
	 * @return the item object
	 */
	T getItem();

	/**
	 * Returns the occurrence of the item
	 *
	 * @return the occurrence of the item
	 */
	int getCount();


	/**
	 * Increases the item occurrence by 1
	 */
	void increaseCount();
};

#include "count.cpp"

#endif
