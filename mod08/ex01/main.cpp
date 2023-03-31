#include <iostream>
#include <vector>

#include "Span.hpp"

std::vector<int> testvec(10);

int main() {
    Span test1(10);

    test1.addRange(testvec.begin(), testvec.end());
    try {
        Span test2(9);
        test2.addRange(testvec.begin(), testvec.end());
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        test1.addNumber(1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::vector<int> largevec(100000);
    for (unsigned int i = 0; i < 100000; i++) {
        largevec[i] = std::rand();
    }

    Span test(5);

    test.addNumber(-2147483648);
    test.addNumber(+2147483647);
    test.addNumber(17);
    test.addNumber(9);
    test.addNumber(-11);

    std::cout << test.shortestSpan() << std::endl;
    std::cout << test.longestSpan() << std::endl;

    std::srand(std::time(nullptr));
    Span test3(100000);
    test3.addRange(largevec.begin(), largevec.end());
    std::cout << test3.shortestSpan() << std::endl;
    std::cout << test3.longestSpan() << std::endl;
    return (0);
}