/* Author: Wei Fei
 * KUID: 2538810
 * Date: 12/03/13
 * FileName: lab9.cpp
 * Description: do major implementation.
 */

#include "Executive.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " inputfile" << std::endl;
        return 0;
    }
    Executive(argv[1]).run();
    return 0;
}
