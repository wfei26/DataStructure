/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/10/13
 * FileName: Executive.cpp
 * Description: edit the final output.
 */

#include "Executive.h"

/**
 * Constructor
 *
 * @param size size of the array
 * @param initial condition
 * @param sort algorithm used
 */
Executive::Executive(int size, const char *order, const char *sortType) {
    this->size = size;
    this->array = new double [size];

    // initialize the array
    if (!strcmp(order, "random")) {
        for (int i = 0; i < size; i++)
            array[i] = drand48();

    } else if (!strcmp(order, "ascending")) {
        for (int i = 0; i < size; i++)
            array[i] = 0.001 * static_cast<double>(i);

    } else if (!strcmp(order, "descending")) {
        for (int i = 0; i < size; i++)
            array[i] = 0.001 * static_cast<double>(size - i - 1);

    } else {
        std::cout << "Unknown initial array condition: " << order << std::endl;
        exit(0);
    }

    unsigned long time = 0;

    // sort the array
    if (!strcmp(sortType, "bubble")) {
        time = sort<double>(bubbleSort);

    } else if (!strcmp(sortType, "insertion")) {
        time = sort<double>(insertionSort);

    } else if (!strcmp(sortType, "selection")) {
        time = sort<double>(selectionSort);

    } else if (!strcmp(sortType, "merge")) {
        time = sort<double>(mergesort);

    } else if (!strcmp(sortType, "quick")) {
        time = sort<double>(quicksort);

    } else {
        std::cout << "Unknown sort type: " << sortType << std::endl;
        exit(0);
    }

    // display statistics
    std::cout << "Size of the array       : " << size << std::endl;
    std::cout << "Sorting algorithm       : " << sortType << std::endl;
    std::cout << "Initial array condition : " << order << std::endl;
    std::cout << "Total time used         : " << time << " us" << std::endl;
}

/**
 * Destructor
 */
Executive::~Executive() {
    delete[] array;
}

/**
 * Sorts the array by the specified sort function and returns the time used
 *
 * @param sortFunction the sort function to be used
 * @return time used
 */
template<class T>
unsigned long Executive::sort(void (sortFunction)(T theArray[], long n)) {
    unsigned long startTime = getTime();
    sortFunction(array, size);
    unsigned long endTime = getTime();
    return endTime - startTime;
}

/**
 * Returns the current time in microseconds
 *
 * @return the current time in microseconds
 */
unsigned long Executive::getTime() {
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000ul + tv.tv_usec;
}
