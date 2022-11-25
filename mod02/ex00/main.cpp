#include "Fixed.hpp"

#include <iostream>

#define QUOTED(x) #x

int main(void) {
    Fixed   test;
    test.setRawBits(5);
    std::cout << QUOTED(test) << ": " << test;

    Fixed   testCopy(test);
    test.setRawBits(10);
    std::cout << QUOTED(test) << ": rawBits = " << test.getRawBits() << std::endl;
    std::cout << QUOTED(test) << ": rawBits = " << testCopy.getRawBits() << std::endl;
}
