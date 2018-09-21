/* Author: Wei Fei
 * KUID: 2538810
 * Date: 11/17/13
 * FileName: lab8.cpp
 * Description: do main implementation
 */

#include "Executive.h"

int main(int argc, char **argv) {

    // Set a seed for randomize
    srand48(100);

    // Check arguments
    if (argc != 4 && argc != 5) {
        std::cout << "Usage: " << argv[0] << " size order type [threshold]" << std::endl;
        return 0;
    }

    // Sort the data
    int threshold = argc > 4 ? atoi(argv[4]) : 0;
    Executive(atoi(argv[1]), argv[2], argv[3], threshold);
    return 0;
}
