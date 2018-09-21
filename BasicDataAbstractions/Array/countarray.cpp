/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/27/13
 * FileName: countarray.cpp
 * Description: maintain a dynamic array of count objects.
 */



/**
 * Default constructor
 */
template <typename T>
CountArray<T>::CountArray() {
	arraySize = 10;
	array = new Count<T>[arraySize];
	numItemsStored = 0;
}

/**
 * Copy constructor
 *
 * @param countArr the CountArray to copy from
 */
template <typename T>
CountArray<T>::CountArray(const CountArray<T>& countArr) {
	arraySize = countArr.arraySize;
	array = new Count<T>[arraySize];
	numItemsStored = countArr.numItemsStored;
	for (int i = 0; i < numItemsStored; i++) {
		array[i] = countArr.getItem(i);
	}
}

/**
 * Destructor
 */
template <typename T>
CountArray<T>::~CountArray() {
	delete[] array;
}


/**
 * Returns the number of items stored in the array
 *
 * @return the number of items stored in the array
 */
template <typename T>
int CountArray<T>::getNumItemsStored() const {
	return numItemsStored;
}

/**
 * Bumps the count of the given item
 *
 * @param t the given item
 */
template <typename T>
void CountArray<T>::bumpCount(T t) {
	for (int i = 0; i < numItemsStored; i++)
		if (array[i].getItem() == t) {
			// If 't' is in the array, just bump its count
			array[i].increaseCount();
			return;
		}
	
	// If the array is full, double the size
	if (numItemsStored == arraySize) {
		arraySize *= 2;
		Count<T> *newArray = new Count<T>[arraySize];
		for (int i = 0; i < numItemsStored; i++)
			newArray[i] = array[i];
		delete[] array;
		array = newArray;
	}
	
	// Add a new Count at the end
	array[numItemsStored++] = Count<T>(t);
}

/**
 * Returns the item at the specified index
 *
 * @param whichItem the index of item
 * @return the item at the index
 */
template <typename T>
Count<T> CountArray<T>::getItem(int whichItem) const {
	return array[whichItem];
}
