/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/10/13
 * FileName: lab7.cpp
 * Description: do major implementation.
 */

#include "Executive.h"

int main(int argc, char **argv) {

    // Set a seed for randomize
    srand48(100);

    // Check arguments
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " size order type" << std::endl;
        return 0;
    }

    // Sort the data
    Executive(atoi(argv[1]), argv[2], argv[3]);
    return 0;
}
