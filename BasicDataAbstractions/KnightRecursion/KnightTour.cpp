/* Author: Wei Fei
 * KUID: 2538810
 * Date: 10/08/13
 * FileName: KnightTour.cpp
 * Description: implement a recursive backtracking solution to the Knight's Tour problem, give all posible paths.
 */


#include "KnightTour.h"
#include <iostream>
#include <iomanip>

/**
 * Constructs with the board size
 *
 * @param rows      rows of the chess board
 * @param cols      cols of the chess board
 */
KnightTour::KnightTour(int row, int col) : rows(row), cols(col) {
    // create the board array and initialize by -1
    board = new int *[row];
    for (int i = 0; i < row; i++) {
        board[i] = new int [col];
        for (int j = 0; j < col; j++)
            board[i][j] = -1;
    }
}

/**
 * Destructor
 */
KnightTour::~KnightTour() {
    for (int i = 0; i < rows; i++)
        delete[] board[i];
    delete[] board;
}


/**
 * Searches for the solution recursively
 *
 * @param x         x-coordinate of the start position
 * @param y         y-coordinate of the start position
 * @param depth     depth of recursion
 * @return          true if a solution is found
 *                  false otherwise
 */
bool KnightTour::search(int x, int y, int depth) {
    board[x][y] = depth;

    // solution is found
    if (depth == rows * cols - 1) return true;

    // go to the 8 adjacent positions
    for (int i = 0; i < NUM_DIR; i++) {
        if (x + DX[i] >= 0 && x + DX[i] < rows
                && y + DY[i] >= 0 && y + DY[i] < cols
                && board[x + DX[i]][y + DY[i]] == -1) {
            if (search(x + DX[i], y + DY[i], depth + 1)) return true;
        }
    }

    // recover
    if (depth != 0) board[x][y] = -1;

    // not found
    return false;
}

/**
 * Prints the board
 */
void KnightTour::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "[";
            if (board[i][j] == -1) {
                std::cout << "  ";
            } else {
                std::cout << std::setw(2) << board[i][j];
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }
}
