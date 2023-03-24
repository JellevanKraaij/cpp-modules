#include <iostream>

#include "Base.hpp"

int main(void) {
    for (int i = 0; i < 10; i++) {
        Base *test = generate();
        indentify(test);
        indentify(*test);
        delete test;
    }
    std::cout << "test with base type" << std::endl;
    Base test;
    indentify(test);
    indentify(&test);
}
