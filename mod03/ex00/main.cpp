#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap c1("c1");
    ClapTrap c2("c2");
    ClapTrap c3("c3");

    std::cout << std::endl;
    for (int i = 0; i < 11; i++) {
        c1.attack("test");
        c2.takeDamage(1);
        c3.beRepaired(10);
    }
    std::cout << std::endl;

    c1.takeDamage(50);
    c2.takeDamage(50);
    c3.takeDamage(50);

    std::cout << std::endl;
}
