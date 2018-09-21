/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/17/13
 * FileName: mergeInsertionSort.cpp
 * Description: combine merge and insertion sort algorithm.
 */

// mergeInsertionSort.c++

#include "mergesort.c++"
#include "insertionSort.c++"

template <typename T>
void mergeInsertionSort(T theArray[], long first, long last, T* tempArray, int threshold)
{
   if (first < last)
   {
      if (last - first > threshold) {
          // sort each half
          long mid = (first + last)/2;    // index of midpoint
          // sort left half theArray[first..mid]
          mergeInsertionSort(theArray, first, mid, tempArray, threshold);
          // sort right half theArray[mid+1..last]
          mergeInsertionSort(theArray, mid+1, last, tempArray, threshold);
          // merge the two halves
          merge(theArray, first, mid, last, tempArray);

      } else {
          insertionSort(theArray + first, last - first + 1);
      }
   }
}

template <typename T>
void mergeInsertionSort(T theArray[], long size, int threshold)
{
	T* tempArray = new T[size];
	mergeInsertionSort(theArray, 0, size-1, tempArray, threshold);
	delete [] tempArray;
}
