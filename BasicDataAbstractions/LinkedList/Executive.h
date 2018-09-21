/* Author: Wei Fei
 * KUID: 2538810
 * Date: 10/03/13
 * FileName: Executive.cpp
 * Description: the header file of Executive.cpp.
 */


#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "CountList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class Executive {
private:
	/**
	 * The count data of char
	 */
	CountList<char> charList;
	/**
	 * The count data of int
	 */
	CountList<int> intList;
	/**
	 * The count data of string
	 */
	CountList <std::string> strList;

	/**
	 * Prints the count data
	 *
	 * @param arr the count data to be printed
	 */
	template <typename T>
	static void print(CountList<T> list);
	
	/**
	 * Reads items from the input stream and updates the count data
	 *
	 * @param is  the input stream
	 * @param arr the count data to be updated
	 */
	template <typename T>
	static void read(std::istream& is, CountList<T>& list);

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
	 * Prints all the lists
	 */
	void print() const;
};

#endif
