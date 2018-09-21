/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/17/13
 * FileName: quickInsertionSort.cpp
 * Description: combine quick and insertion sort algorithm.
 */

// QuickInsertionSort.c++

#include "quicksort.c++"
#include "insertionSort.c++"

template <typename T>
void quickInsertionSort(T theArray[], long first, long last, int threshold) {
    long pivotIndex;

    if (first < last) {  // create the partition: S1, pivot, S2
        if (last - first > threshold) {
            partition(theArray, first, last, pivotIndex);
            // sort regions S1 and S2
            quickInsertionSort(theArray, first, pivotIndex - 1, threshold);
            quickInsertionSort(theArray, pivotIndex + 1, last, threshold);

        } else {
            insertionSort(theArray + first, last - first + 1);
        }
    }
}

template <typename T>
void quickInsertionSort(T theArray[], long size, int threshold) {
    quickInsertionSort(theArray, 0, size - 1, threshold);
}
