/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/05/13
 * FileName: poly.cpp
 * Description: this file mainly construct some methods to achieve four required operations   of poltnomials
 */

#include "poly.h"
#include <cmath> 

/**
 * Default constructor
 */
Polynomial::Polynomial() : degree(0) {
	coef[0] = 0;
}

/**
 * Copy constructor
 * @param other another polynomial
 */
Polynomial::Polynomial(const Polynomial& other) {
	*this = other;
}

/**
 * Overloads assign operator
 * @param other another polynomial
 * @return referece to this polynomial
 */
Polynomial& Polynomial::operator=(const Polynomial& other) {
	if (this != &other) {
		// Copy the degree
		degree = other.degree;
		// Copy the coefficients 
		for (int i = 0; i <= degree; i++)
			coef[i] = other.coef[i];
	}
	return *this;
}

/**
 * Computes and returns the value resulting from evaluating this
 * polynomial at the given x.
 * @param x the value of x
 * @return the value resulting from evaluating this polynomial at
 *         the given x.
 */ 
double Polynomial::evaluate(double x) const {
	double res = 0;
	for (int i=0; i<MAX_DEGREE; i++){
	res = res + pow(x,i)*coef[i]; 
	}
	return res;
}

/**
 * Adds this polynomial to p2, returning the sum as the function
 * return value.
 * @param p2 the polynomial to add
 * @return the sum of the two polynomials
 */
Polynomial Polynomial::add(Polynomial p2) const {
	Polynomial p;
	if (p2.degree > degree) {
		p = p2;
		// Add the coefficients of this polynomail to p
		for (int i = 0; i <= degree; i++) {
			p.coef[i] += coef[i];
		}
		p.degree = p2.degree;

	} else {
		p = *this;
		// Add the coefficients of p2 to p
		for (int i = 0; i <= p2.degree; i++) {
			p.coef[i] += p2.coef[i];
		}
		p.degree = degree;
	}

	// Decrease the degree
	while(p.coef[p.degree] == 0 && p.degree > 0) {
		p.degree--;
	}
	return p;
}

/**
 * Prints this polynomial to the given output stream.
 * @param os the given output stream
 */
void Polynomial::print(std::ostream &os) const {
	bool first = true;
	for (int i = 0; i <= degree; i++) {
		if (i == 0) {
			// Print the first item
			if (coef[i] != 0 || degree == 0) {
				os << coef[i];
				first = false;
			}

		} else {
			// Skips the items with zero coefficient
			if (coef[i] == 0) continue;
			if (coef[i] < 0) {
				if (first) {
					if (coef[i] == -1) os << "-";
					else os << coef[i];

				} else {
					os << " - ";
					if (coef[i] != -1) os << -coef[i];
				}
			} else {
				if (!first) os << " + ";
				if (coef[i] != 1) os << coef[i];
			}
			// Print x^y
			os << "x";
			if (i > 1) os << "^" << i;
			first = false;
		}
	}
}

/**
 * Reads the polynomial from the given input stream.
 * @param in the given input stream.
 * @return true if read succefully
 *         false otherwise
 */
bool Polynomial::read(std::istream& in) {
	if (in >> degree) {
		for (int i = 0; i <= degree; i++)
			in >> coef[i];
		return true;

	} else {
		// No more data to read
		return false;
	}
}
/**
 * Computes the derivative of this polynomial and returns the 
 * result as the function return parameter.
 * @return the derivative of this polynomial
 */
Polynomial Polynomial::differentiate() const {
	Polynomial p = *this;
	if (p.degree >= 1) {
		// If the degree > 1, computes the derivative
		for (int i = 0; i < p.degree; i++) {
			p.coef[i] = p.coef[i + 1] * (i + 1);
		}
		p.degree--;

	} else {
		// If the degree is 0, set coef[0] to be 0.
		p.coef[0] = 0;
	}
	return p;
}
