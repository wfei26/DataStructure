/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/05/13
 * FileName: poly.h
 * Description: the header file of poly.cpp, do some declarations. 
 */

#ifndef POLY_H
#define POLY_H
#include <iostream>

/**
 * The max degree
 */ 
const int MAX_DEGREE = 20;

/**
 * This class represents a polynomial and offers some polynomial
 * operations.
 */
class Polynomial {
public:
	/**
	 * Default constructor
	 */
	Polynomial();

    /**
	 * Copy constructor
	 * @param other another polynomial
	 */
	Polynomial(const Polynomial& other);
	
    /**
	 * Overloads assign operator
	 * @param other another polynomial
	 * @return referece to this polynomial
	 */
	Polynomial& operator=(const Polynomial& other);

	/**
	 * Computes and returns the value resulting from evaluating this
	 * polynomial at the given x.
	 * @param x the value of x
	 * @return the value resulting from evaluating this polynomial at
	 *         the given x.
	 */ 
	double evaluate(double x) const;

	/**
	 * Adds this polynomial to p2, returning the sum as the function
	 * return value.
	 * @param p2 the polynomial to add
	 * @return the sum of the two polynomials
	 */
	Polynomial add(Polynomial p2) const;
	
	/**
	 * Prints this polynomial to the given output stream.
	 * @param os the given output stream
	 */
	void print(std::ostream &os) const;
	
	/**
	 * Reads the polynomial from the given input stream.
	 * @param in the given input stream.
	 * @return true if read succefully
	 *         false otherwise
	 */
	bool read(std::istream& in);
	/**
	 * Computes the derivative of this polynomial and returns the 
	 * result as the function return parameter.
	 * @return the derivative of this polynomial
	 */
	Polynomial differentiate() const;

private:
	/**
	 * The array of coefficients 
	 */
	double coef[MAX_DEGREE + 1];

	/**
	 * The degree of the polynomial
	 */
	int degree;
};


#endif
