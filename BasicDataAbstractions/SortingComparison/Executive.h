/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/17/13
 * FileName: Executive.h
 * Description: the header file of Executive.cpp.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <cstring>
#include <cstdlib>
#include "Sorts.h"
#include <sys/time.h>
#include <ctime>
#include <iostream>

class Executive {
public:

    /**
     * Constructor
     *
     * @param size size of the array
     * @param initial condition
     * @param sort algorithm used
     * @param threshold to change sort function
     */
    Executive(int size, const char *order, const char *sortType, int threshold = 0);

    /**
     * Destructor
     */
    ~Executive();

private:

    /**
     * Sorts the array by the specified sort function and returns the time used
     *
     * @param sortFunction the sort function to be used
     * @return time used
     */
    template<class T>
    unsigned long sort(void (sortFunction)(T theArray[], long n));

    /**
     * Sorts the array by the specified sort function and returns the time used
     *
     * @param sortFunction the sort function to be used
     * @return time used
     */
    template<class T>
    unsigned long sort(void (sortFunction)(T theArray[], long n, int threshold));

    /**
     * Returns the current time in microseconds
     *
     * @return the current time in microseconds
     */
    unsigned long getTime();

    /**
     * Array of data
     */
    double *array;

    /**
     * Size of the array
     */
    int size;

    /**
     * Threshold to change sort function
     */
    int threshold;
};

#endif
