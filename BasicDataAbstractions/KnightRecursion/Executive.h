/* Author: Wei Fei
 * KUID: 2538810
 * Date: 10/08/13
 * FileName: Executive.h
 * Description: the header file of Executive.cpp.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

class Executive {
public:
    /**
     * Finds a solution of Knight Tour
     *
     * @param rows      rows of the chess board
     * @param cols      cols of the chess board
     * @param x         x-coordinate of the start position
     * @param y         y-coordinate of the start position
     */
    Executive(int rows, int cols, int x, int y);
};

#endif

