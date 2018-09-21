/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/10/13
 * FileName: matrix.cpp
 * Description: major class of this program, which gives the details of constructor and six operations of matrix
 */

#include "matrix.h"

/**
 * Constructor
 *
 * @param row number of rows
 * @param col number of columns
 * @param a   elements of the matrix
 */
Matrix::Matrix(int row, int col, double a[Max_numRows][Max_numCols]) {
  if (row <= 0 || row >= Max_numRows || col <= 0 || col >= Max_numCols) {
    std::cout << "The matrix size is invalid." << std::endl;
    exit(-1);
  }
  rowNum = row;
  colNum = col;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat[i][j] = a[i][j];
}


/**
 * Constructs a matrix with an initial value
 *
 * @param row   number of rows
 * @param col   number of columns
 * @param value the initial value
 */
Matrix::Matrix(int row, int col, int value) {
  if (row <= 0 || row >= Max_numRows || col <= 0 || col >= Max_numCols) {
    std::cout << "The matrix size is invalid." << std::endl;
    exit(-1);
  }
  rowNum = row;
  colNum = col;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat[i][j] = value;
}

/**
 * Copy constructor
 *
 * @param b  the matrix to copy from
 */
Matrix::Matrix(const Matrix& b) {
  rowNum = b.rowNum;
  colNum = b.colNum;
  for (int i = 0; i < b.rowNum; i++)
    for (int j = 0; j < b.colNum; j++)
      mat[i][j] = b.mat[i][j];
}

/**
 * Reads a matrix from an input stream
 *
 * @param is the input stream to read from
 */
Matrix::Matrix(std::istream &is) {
  is >> rowNum >> colNum;

  for (int i = 0; i < rowNum; i++)
    for (int j = 0; j < colNum; j++)
      is >> mat[i][j];
}


/**
 * Prints the matrix to an output stream
 *
 * @param os the output stream
 */
void Matrix::print(std::ostream &os) const {
  for (int i = 0; i < rowNum; i++) {
    for (int j = 0; j < colNum; j++)
      os << mat[i][j] << "  ";
    os << std::endl;
  }
}

/**
 * Adds anther matrix to this matrix
 *
 * @param b the matrix to be added
 * @return the result matrix
 */
Matrix Matrix::add(const Matrix b) const {
  Matrix res(rowNum, colNum, -1);
  if (rowNum != b.rowNum || colNum != b.colNum) {
    std::cout << "Size mismatching" << std::endl;

  } else {
    for (int i = 0; i < rowNum; i++)
      for (int j = 0; j < colNum; j++)
        res.mat[i][j] = mat[i][j] + b.mat[i][j];
  }
  return res;
}

/**
 * Scales up the matrix
 *
 * @param x  the scale to multiply
 * @return the result matrix
 */
Matrix Matrix::scale(double x) const {
  Matrix res(*this);
  for (int i = 0; i < rowNum; i++)
    for (int j = 0; j < colNum; j++)
      res.mat[i][j] *= x;
  return res;
}

/**
 * Multiplies another matrix to this matrix
 *
 * @param b the matrix to be multiplied
 * @return the result matrix
 */
Matrix Matrix::multiply(const Matrix b) const {
  Matrix res(rowNum, b.colNum, 0);
  if (colNum != b.rowNum) {
    std::cout << "Size mismatching." << std::endl;

  } else {
    for (int i = 0; i < rowNum; i++)
      for (int j = 0; j < colNum; j++)
        for (int k = 0; k < b.colNum; k++)
          res.mat[i][k] += mat[i][j] * b.mat[j][k];
  }
  return res;
}

/**
 * Transposes the matrix.
 *
 * @return the transposed matrix
 */
Matrix Matrix::transpose() const {
  Matrix res(colNum, rowNum, 0);
  for (int i = 0; i < rowNum; i++)
    for (int j = 0; j < colNum; j++)
      res.mat[j][i] = mat[i][j];
  return res;
}

/**
 * Inverses the matrix
 *
 * @return the inversed matrix
 */
Matrix Matrix::inverse() const {
  return cofactor().transpose().scale(1.0 / det());
}


/**
 * Computes the determinant of the matrix
 *
 * @return the determinant of the matrix
 */
double Matrix::det() const {
  double det = 0;
  int n = colNum;
  if (colNum == 2) n--;
  for (int i = 0; i < n; ++i) {
    double a = 1, b = 1;
    for (int j = 0; j < rowNum; ++j) {
      a *= mat[j][(i + j) % colNum];
      b *= mat[rowNum - j - 1][(i + j) % colNum];
    }
    det += a - b;
  }
  return det;
}

/**
 * Returns a sub matrix excluding a row and a column
 *
 * @param excludingRow    the excluding row
 * @param excludingColumn the excluding column
 * @return a sub matrix excluding the row and the column
 */
Matrix Matrix::subMatrix(int excludingRow, int excludingColumn) const {
  Matrix res(rowNum - 1, colNum - 1, 0);
  int r = -1;
  for (int i = 0; i < rowNum; i++) {
    if (i == excludingRow)
      continue;
    r++;
    int c = -1;
    for (int j = 0; j < colNum; j++) {
      if (j == excludingColumn)
        continue;
      res.mat[r][++c] = mat[i][j];
    }
  }
  return res;
}

/**
 * Computes the cofactor matrix
 *
 * @return the cofactor matrix
 */
Matrix Matrix::cofactor() const {
  Matrix res(rowNum, colNum, 0);
  for (int i = 0; i < rowNum; i++)
    for (int j = 0; j < colNum; j++) {
      res.mat[i][j] = subMatrix(i, j).det();
      if (i % 2 == 1) res.mat[i][j] *= -1;
      if (j % 2 == 1) res.mat[i][j] *= -1;
    }
  return res;
}

/**
  * Returns the row at the specified index
  *
  * @param the index of row
  * @return the row at the specified index
  */
double* Matrix::operator[](int index) {
  return mat[index];
}
