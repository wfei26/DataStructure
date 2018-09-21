/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/27/13
 * FileName: executive.h
 * Description: the header file of executive.cpp.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "countarray.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class Executive {
private:
	/**
	 * The count array of char
	 */
	CountArray<char> charArray;
	/**
	 * The count array of int
	 */
	CountArray<int> intArray;
	/**
	 * The count array of string
	 */
	CountArray <std::string> strArray;

	/**
	 * Prints the count array
	 *
	 * @param arr the count array to be printed
	 */
	template <typename T>
	static void print(CountArray<T> arr);
	
	/**
	 * Reads items from the input stream and updates the count array
	 *
	 * @param is  the input stream
	 * @param arr the count array to be updated
	 */
	template <typename T>
	static void read(std::istream& is, CountArray<T>& arr);

public:
	/**
	 * Constructor to load the three files
	 *
	 * @param charFile   input stream of the char file
	 * @param intFile    input stream of the int file
	 * @param stringFile input stream of the string file
	 */
	Executive(std::istream& charFile, std::istream& intFile,
			std::istream& stringFile);

	/**
	 * Prints all the arrays
	 */
	void print() const;
};



#endif
