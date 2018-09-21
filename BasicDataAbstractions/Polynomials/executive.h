/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/05/13
 * FileName: executive.h
 * Description: the header file of executive.cpp, do some declarations. 
 */

#ifndef EXECUTE_H
#define EXECUTE_H

#include "poly.h"

/**
 * The max number of polynomials
 */
const int MAX_NUM_POLYNOMIALS = 10;

/**
 * This class reads the polynomials and processes transactions
 * on them.
 */
class Executive {
public:
	/**
	 * Loads polynomials from the file
	 * @param filename name of the file to read
	 */
	void loadPoly(const char* filename);

	/**
	 * Executes the directives loaded from the file
	 * @param filename name of the file to read
	 */
	void execDirectives(const char* filename);
private:

	/**
	 * The array of polynomials
	 */
	Polynomial polys[MAX_NUM_POLYNOMIALS];

	/**
	 * The number of polynomials
	 */
	int n;
};

#endif
