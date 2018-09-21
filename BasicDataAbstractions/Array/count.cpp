/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/27/13
 * FileName: count.cpp
 * Description: Creat templates of different types and stores the pair of item and its occurrence.
 */


/**
 * Default constructor
 */
template <typename T>
Count<T>::Count() {
}

/**
 * Constructs by an item object and sets count to be 1
 *
 * @param item the item object
 */
template <typename T>
Count<T>::Count(T item) : item(item), count(1) {
}

/**
 * Copy constructor
 *
 * @param c the count object to copy from
 */
template <typename T>
Count<T>::Count(const Count<T>& c) : item(c.item), count(c.count) {
}

/**
 * Returns the occurrence of the item
 *
 * @return the occurrence of the item
 */
template <typename T>
int Count<T>::getCount() {
	return count;
}

/**
 * Returns the item
 *
 * @return the item object
 */
template <typename T>
T Count<T>::getItem() {
	return item;
}

/**
 * Increases the item occurrence by 1
 */
template <typename T>
void Count<T>::increaseCount() {
	count++;
}



