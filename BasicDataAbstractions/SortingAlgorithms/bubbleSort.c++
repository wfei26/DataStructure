/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/10/13
 * FileName: bubbleSort.cpp
 * Description: bubble sort algorithm.
 */



// bubbleSort.c++

#include <cassert>
#include "swap.h"

/** Sorts the items in an array into ascending order.
 * @pre theArray is an array of n items.
 * @post theArray is sorted into ascending order; n is unchanged.
 * @param theArray  The given array.
 * @param n  The size of theArray. */
template <typename T>
void bubbleSort(T theArray[], long n)
{
   bool sorted = false;  // false when swaps occur

   for (long pass = 1; (pass < n) && !sorted; ++pass)
   {  // Invariant: theArray[n+1-pass..n-1] is sorted
      //            and > theArray[0..n-pass]
      sorted = true;  // assume sorted
      for (long index = 0; index < n-pass; ++index)
      {  // Invariant: theArray[0..index-1] <=
         // theArray[index]
         long nextIndex = index + 1;
         if (theArray[index] > theArray[nextIndex])
         {
            swap(theArray[index], theArray[nextIndex]);
            sorted = false;
         }  // end if
      }  // end for
   }  // end for
}  // end bubbleSort
