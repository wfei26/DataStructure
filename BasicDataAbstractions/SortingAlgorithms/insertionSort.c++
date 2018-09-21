/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/10/13
 * FileName: insertionSort.cpp
 * Description: insertion sort algorithm.
 */



// insertionSort.c++
#include <cassert>

/** Sorts the items in an array into ascending order.
 * @pre theArray is an array of n items.
 * @post theArray is sorted into ascending order; n is unchanged.
 * @param theArray  The given array.
 * @param n  The size of theArray. */
template <typename T>
void insertionSort(T theArray[], long n)
{
    
   // unsorted = first index of the unsorted region,
   // loc = index of insertion in the sorted region,
   // nextItem = next item in the unsorted region

   // initially, sorted region is theArray[0],
   //            unsorted region is theArray[1..n-1];
   // in general, sorted region is
   //             theArray[0..unsorted-1],
   // unsorted region is theArray[unsorted..n-1]

   for (long unsorted = 1; unsorted < n; ++unsorted)
   {  // Invariant: theArray[0..unsorted-1] is sorted
      // find the right position (loc) in
      // theArray[0..unsorted] for theArray[unsorted],
      // which is the first item in the unsorted
      // region; shift, if necessary, to make room
      T nextItem = theArray[unsorted];
      long loc = unsorted;

      for (;(loc > 0) && (theArray[loc-1 ]> nextItem);
            --loc)
         // shift theArray[loc-1] to the right
         theArray[loc] = theArray[loc-1];

      // Assertion: theArray[loc] is where nextItem belongs
      
      // insert nextItem into Sorted region
      theArray[loc] = nextItem;
   }  // end for
}  // end insertionSort
