/* Author: Wei Fei
 * KUID: 2538810
 * Date: 10/03/13
 * FileName: Executive.cpp
 * Description: read files and edit the final output.
 */


#include "Executive.h"

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
	read<char>(charFile, charList);
	read<int>(intFile, intList);
	read<std::string>(stringFile, strList);
}

/**
 * Prints all the lists
 */
void Executive::print() const {
	std::cout << "Char input file: " << std::endl;
	print(charList);
	std::cout << std::endl;
	std::cout << "Int input file: " << std::endl;
	print(intList);
	std::cout << std::endl;
	std::cout << "String input file: " << std::endl;
	print(strList);
}

/**
 * Reads items from the input stream and updates the count list
 *
 * @param is  the input stream
 * @param arr the count array to be updated
 */
template <typename T>
void Executive::read(std::istream& is, CountList<T>& list) {
	T item;
	while (is >> item) {
		list.bumpCount(item);
	}
}

/**
 * Prints the count array
 *
 * @param arr the count array to be printed
 */
template <typename T>
void Executive::print(CountList<T> list) {
	for (int i = 0; i < list.getNumItemsStored(); i++) {
		Count<T> item = list.getItem(i);
		std::cout << "(" << item.getItem() << ", " << item.getCount() << ")\n";
	}
}
