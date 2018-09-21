/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/17/13
 * FileName: mergeBubbleSort.cpp
 * Description: combine merge and bubble sort algorithm.
 */

// mergeBubbleSort.c++

#include "mergesort.c++"
#include "bubbleSort.c++"

template <typename T>
void mergeBubbleSort(T theArray[], long first, long last, T* tempArray, int threshold)
{
   if (first < last)
   {
      if (last - first > threshold) {
          // sort each half
          long mid = (first + last)/2;    // index of midpoint
          // sort left half theArray[first..mid]
          mergeBubbleSort(theArray, first, mid, tempArray, threshold);
          // sort right half theArray[mid+1..last]
          mergeBubbleSort(theArray, mid+1, last, tempArray, threshold);
          // merge the two halves
          merge(theArray, first, mid, last, tempArray);

      } else {
          bubbleSort(theArray + first, last - first + 1);
      }
   }
}

template <typename T>
void mergeBubbleSort(T theArray[], long size, int threshold)
{
	T* tempArray = new T[size];
	mergeBubbleSort(theArray, 0, size-1, tempArray, threshold);
	delete [] tempArray;
}
