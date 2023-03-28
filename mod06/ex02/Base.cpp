#include "Base.hpp"

#include <iostream>
#include <random>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void) {
    static bool seedRandom = true;

    if (seedRandom) {
        std::srand(std::time(nullptr));
        seedRandom = false;
    }

    switch (std::rand() % 3) {
        case 0:
            std::cout << "generate type A" << std::endl;
            return new A;
        case 1:
            std::cout << "generate type B" << std::endl;
            return new B;
        case 2:
            std::cout << "generate type C" << std::endl;
            return new C;
    }
    return (nullptr);
}

void indentify(Base* p) {
    std::cout << "Type is: ";

    if (dynamic_cast<A*>(p) != nullptr) {
        std::cout << 'A' << std::endl;
        return;
    }
    if (dynamic_cast<B*>(p) != nullptr) {
        std::cout << 'B' << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p) != nullptr) {
        std::cout << 'C' << std::endl;
        return;
    }
    if (dynamic_cast<Base*>(p) != nullptr) {
        std::cout << "Base" << std::endl;
        return;
    }
}

void indentify(Base& p) {
    std::cout << "Type is: ";
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << 'A' << std::endl;
        return;
    } catch (const std::bad_cast& e) {
    }

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << 'B' << std::endl;
        return;
    } catch (const std::bad_cast& e) {
    }

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << 'C' << std::endl;
        return;
    } catch (const std::bad_cast& e) {
    }

    try {
        (void)dynamic_cast<Base&>(p);
        std::cout << "Base" << std::endl;
        return;
    } catch (const std::bad_cast& e) {
    }

    std::cout << "Not a valid type" << std::endl;
}
