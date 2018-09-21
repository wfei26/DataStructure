/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/05/13
 * FileName: main.cpp
 * Description: major implementation, read file.
 */

#include "executive.h"

/**
 * The main function.
 * @param  argc  number of arguments
 * @return argv  an array of arguments
 */
int main(int argc, char* argv[]) {
	// Check whether the number of arguments is valid
	if (argc != 3) {
		std::cout << "Usage: " << argv[0] 
			<< " polynomials_file directives_file" << std::endl;
		return 0;
	}

	// Create an exective object
	Executive exec;	
	
	// Load polynomials
	exec.loadPoly(argv[1]);

	// Execute the directives
	exec.execDirectives(argv[2]);
	return 0;
}
