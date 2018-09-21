/* Author: Wei Fei
 * KUID: 2538810
 * Date: 10/08/13
 * FileName: KnightTour.h
 * Description: the header file of KnightTour.cpp.
 */


#ifndef KNIGHT_TOUR
#define KNIGHT_TOUR

const int DX[] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int DY[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int NUM_DIR = 8;

class KnightTour {
private:
    // Chess board
    int **board;
    // Rows of the chess board
    int rows;
    // Columns of the chess board
    int cols;

public:
    /**
     * Constructs with the board size
     *
     * @param rows      rows of the chess board
     * @param cols      cols of the chess board
     */
    KnightTour(int rows, int cols);

    /**
     * Destructor
     */
    ~KnightTour();

    /**
     * Searches for the solution recursively
     *
     * @param x         x-coordinate of the start position
     * @param y         y-coordinate of the start position
     * @param depth     depth of recursion
     * @return          true if a solution is found
     *                  false otherwise
     */
    bool search(int x, int y, int depth = 0);

    /**
     * Prints the board
     */
    void print();
};
#endif
