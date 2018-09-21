// quickSort.c++
#ifndef QUICK_SORT_CPP
#define QUICK_SORT_CPP
#include "swap.h"

/** Chooses a pivot for quicksort's partition algorithm and swaps
 *  it with the first item in an array.
 * @pre theArray[first..last] is an array; first <= last.
 * @post theArray[first] is the pivot.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray. */
template <typename T>
void choosePivot(T theArray[], long first, long last)
{
    bool v1 = false; // true means the first quick sort, false means the second quick sort

    long mid = (last + first)/2;
    if (!v1) {
        if (theArray[first] > theArray[mid])
            swap<T>(theArray[first], theArray[mid]);
        if (theArray[mid] > theArray[last])
            swap<T>(theArray[mid], theArray[last]);
        if(theArray[first]>theArray[mid])
            swap<T>(theArray[first], theArray[mid]);
        swap<T>(theArray[mid], theArray[last-1]);
        swap<T>(theArray[first], theArray[last - 1]);
    } else {
        swap<T>(theArray[first], theArray[mid]);
    }
}

/** Partitions an array for quicksort.
 * @pre theArray[first..last] is an array; first <= last.
 * @post Partitions theArray[first..last] such that:
 *    S1 = theArray[first..pivotIndex-1] <  pivot
 *         theArray[pivotIndex]          == pivot
 *    S2 = theArray[pivotIndex+1..last]  >= pivot
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray.
 * @param pivotIndex  The index of the pivot after partitioning. */
template <typename T>
void partition(T theArray[],
               long first, long last, long& pivotIndex)
{
   // place pivot in theArray[first]
   choosePivot(theArray, first, last);
   T pivot = theArray[first];     // copy pivot

   // initially, everything but pivot is in unknown
   long lastS1 = first;           // index of last item in S1
   long firstUnknown = first + 1; // index of first item in
                                 // unknown

   // move one item at a time until unknown region is empty
   for (; firstUnknown <= last; ++firstUnknown)
   {  // Invariant: theArray[first+1..lastS1] < pivot
      //         theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (theArray[firstUnknown] < pivot)
      {  // item from unknown belongs in S1
         ++lastS1;
         swap<T>(theArray[firstUnknown], theArray[lastS1]);
      }  // end if

      // else item from unknown belongs in S2
   }  // end for

   // place pivot in proper position and mark its location
   swap<T>(theArray[first], theArray[lastS1]);
   pivotIndex = lastS1;
}  // end partition

/** Sorts the items in an array into ascending order.
 * @pre theArray[first..last] is an array.
 * @post theArray[first..last] is sorted.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray. */
template <typename T>
void quicksort(T theArray[], long first, long last)
{
   long pivotIndex;

   if (first < last)
   {  // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex);

      // sort regions S1 and S2
      quicksort(theArray, first, pivotIndex-1);
      quicksort(theArray, pivotIndex+1, last);
   }  // end if
}  // end quicksort

template <typename T>
void quicksort(T theArray[], long size)
{
	quicksort(theArray, 0, size-1);
}

#endif
