/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/01/13
 * FileName: main.cpp
 * Description: do major implementation and combine all methods.
 */

#include "Executive.h"
#include <cstdlib>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " inputFile" << std::endl;
    }
    std::ifstream fin(argv[1]);
    Executive ex(fin);
    return 0;
}
