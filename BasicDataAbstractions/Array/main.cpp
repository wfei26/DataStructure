/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/27/13
 * FileName: main.cpp
 * Description: do major implementation and combine all methods.
 */

#include "executive.h"

int main(int argc, char** argv) {
	
	// Check the arguments
	if (argc != 4) {
		std::cout << "Usage: " << argv[0] << " charFile intFile stringFile" << std::endl;
		return 0;
	}
	
	// Create three input streams
	std::ifstream charFile(argv[1]);
	std::ifstream intFile(argv[2]);
	std::ifstream stringFile(argv[3]);
	
	// Create an executive object
	Executive ex(charFile, intFile, stringFile);
	
	// Print the result
	ex.print();
	
	// Close the files
	charFile.close();
	intFile.close();
	stringFile.close();
	return 0;
}
