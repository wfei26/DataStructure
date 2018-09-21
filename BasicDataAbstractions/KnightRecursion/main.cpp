/* Author: Wei Fei
 * KUID: 2538810
 * Date: 10/08/13
 * FileName: main.cpp
 * Description: do major implementation and combine all methods.
 */

#include <cstdlib>
#include "Executive.h"
#include <iostream>

int main(int argc, char **argv) {

    // check arguments
    if (argc != 5) {
        std::cout << "Usage: " << argv[0]
                << " rows cols startX startY" << std::endl;
        return EXIT_FAILURE;
    }

    // execute
    Executive(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    return EXIT_SUCCESS;
}
