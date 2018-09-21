/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/27/13
 * FileName: executive.cpp
 * Description: read files and edit the final output.
 */


#include "executive.h"

/**
 * Constructor to load the three files
 *
 * @param charFile   input stream of the char file
 * @param intFile    input stream of the int file
 * @param stringFile input stream of the string file
 */
Executive::Executive(std::istream& charFile, std::istream& intFile,
					 std::istream& stringFile) {
	if (!charFile) {
		std::cout << "The char file is not found." << std::endl;
		exit(0);
	}
	if (!intFile) {
		std::cout << "The int file is not found." << std::endl;
		exit(0);
	}
	if (!stringFile) {
		std::cout << "The string file is not found." << std::endl;
		exit(0);
	}
	read<char>(charFile, charArray);
	read<int>(intFile, intArray);
	read<std::string>(stringFile, strArray);
}

/**
 * Prints all the arrays
 */
void Executive::print() const {
	std::cout << "Char input file: " << std::endl;
	print(charArray);
	std::cout << std::endl;
	std::cout << "Int input file: " << std::endl;
	print(intArray);
	std::cout << std::endl;
	std::cout << "String input file: " << std::endl;
	print(strArray);
}

/**
 * Reads items from the input stream and updates the count array
 *
 * @param is  the input stream
 * @param arr the count array to be updated
 */
template <typename T>
void Executive::read(std::istream& is, CountArray<T>& arr) {
	T item;
	while (is >> item) {
		arr.bumpCount(item);
	}
}

/**
 * Prints the count array
 *
 * @param arr the count array to be printed
 */
template <typename T>
void Executive::print(CountArray<T> arr) {
	for (int i = 0; i < arr.getNumItemsStored(); i++) {
		Count<T> item = arr.getItem(i);
		std::cout << "(" << item.getItem() << ", " << item.getCount() << ")\n";
	}
}
