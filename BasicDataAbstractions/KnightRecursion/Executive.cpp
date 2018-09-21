/* Author: Wei Fei
 * KUID: 2538810
 * Date: 10/08/13
 * FileName: Executive.cpp
 * Description: edit the final output.
 */

#include <iostream>
#include "Executive.h"
#include "KnightTour.h"

/**
 * Finds a solution of Knight Tour
 *
 * @param rows      rows of the chess board
 * @param cols      cols of the chess board
 * @param x         x-coordinate of the start position
 * @param y         y-coordinate of the start position
 */
Executive::Executive(int rows, int cols, int x, int y) {
    KnightTour k(rows, cols);
    if (k.search(x, y)) {
        std::cout << "Success!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
    k.print();
}
