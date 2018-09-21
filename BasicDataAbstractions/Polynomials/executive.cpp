/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/05/13
 * FileName: executive.cpp
 * Description: invoke the mothods in poly.cpp and edit the final output. Read the polynomials and process transactions on them
 */

#include <cstring>
#include <fstream>
#include <cstdlib>
#include "executive.h"

/**
 * Loads polynomials from the file
 * @param filename name of the file to read
 */
void Executive::loadPoly(const char* filename) {
	n = 0;
	std::ifstream in(filename);
	if (in.good()) {
		// Load all the polynomials from the file
		while(polys[n].read(in)) {
			n++;
		}
		// Close the file
		in.close();

	} else {
		// Exit if the file does not exits.
		std::cout << "File " << filename << " is not found." << std::endl;
		exit(0);
	}
}

/**
 * Executes the directives loaded from the file
 * @param filename name of the file to read
 */
void Executive::execDirectives(const char* filename) {
	std::ifstream in(filename);
	char directive[100];
	int index1, index2;
	double x;

	if (in.good()) {
		// Read all the directives
		while(in >> directive) {
			if (strcmp(directive, "add") == 0) {
				// Choose two polynomials and display the sum
				in >> index1 >> index2;
				if (index1 >= 0 && index1 < n && index2 >= 0 && index2 < n) {
				std::cout << "The sum of two polynomial is" << std::endl;
					std::cout << "(";
					polys[index1].print(std::cout);
					std::cout << ") + (";
					polys[index2].print(std::cout);
					std::cout << ") = ";
					polys[index1].add(polys[index2]).print(std::cout);
					std::cout << std::endl;
					
				} else 
					std::cout << "The index is invalid." << std::endl;

			} else if (strcmp(directive, "print") == 0) {
				// Choose a polynomial and print it
				in >> index1;
				if (index1 >= 0 && index1 < n) {
					std::cout << "Polynomial " << index1 << " is : ";
					polys[index1].print(std::cout);
					std::cout << std::endl;
				} else
					std::cout << "The index is invalid." << std::endl;

			} else if (strcmp(directive, "evaluate") == 0) {
				// Choose a polynomial and evaluate
				in >> index1 >> x;
				if (index1 >= 0 && index1 < n) {
					std::cout << "The polynomial ";
					polys[index1].print(std::cout);
					std::cout << " evaluated at " << x << " is "
							<< polys[index1].evaluate(x) << std:: endl;
				} else
					std::cout << "The index is invalid." << std::endl;

			} else if (strcmp(directive, "differentiate") == 0) {
				// Choose a polynomial and print the derivative of it 
				in >> index1;
				if (index1 >= 0 && index1 < n) {
					std::cout << "The derivative of this polynomial is: ";
					polys[index1].print(std::cout);
					std::cout << " is ";
					polys[index1].differentiate().print(std::cout);
					std::cout << std::endl;
					
				} else
					std::cout << "The index is invalid." << std::endl;

			} else  {
				// It's an invalid directive 
				std::cout << "Invalid directive: " << directive << std::endl;
			}
		}
		// Close the file
		in.close();

	} else {
		// Exit if the file does not exits.
		std::cout << "File " << filename << " is not found." << std::endl;
		exit(0);
	}
}
