/* Author: Wei Fei
 * KUID: 2538810
 * Date: 09/10/13
 * FileName: main.cpp
 * Description: do major implementation and edit the final output, also create a matrix.
 */

#include "matrix.h"


Matrix randomMatrix(int row, int col, int max) {
  double mat[Max_numRows][Max_numCols];
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat[i][j] = rand() % max + 1;
  return Matrix(row, col, mat);
}

int main() {

  Matrix a = randomMatrix(3, 2, 2);
  std::cout << "Matrix a: " << std::endl;
  a.print(std::cout);

  Matrix b = randomMatrix(2, 3, 4);
  std::cout << "Matrix b: " << std::endl;
  b.print(std::cout);

  std::cout << "b.transpose(): " << std::endl;
  b.transpose().print(std::cout);

  std::cout << "b.scale(0.5): " << std::endl;
  b.scale(0.5).print(std::cout);

  Matrix c = a.add(a);
  std::cout << "Matrix c = a + a: " << std::endl;
  c.print(std::cout);

  Matrix d = a.multiply(b);
  std::cout << "Matrix d = a * b: " << std::endl;
  d.print(std::cout);

  Matrix e(3, 3, 0);
  e[0][0] = 1;
  e[0][1] = 0;
  e[0][2] = 2;
  e[1][0] = 0;
  e[1][1] = 1;
  e[1][2] = 1;
  e[2][0] = 2;
  e[2][1] = 0;
  e[2][2] = 3;
  std::cout << "Matrix e: " << std::endl;
  e.print(std::cout);
  std::cout << "e.inverse(): " << std::endl;
  e.inverse().print(std::cout);

  return 0;
}
