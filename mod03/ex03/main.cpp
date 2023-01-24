#include <iostream>

#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap test("SHOULD NOT BE PRINTED");
    DiamondTrap test2("DiamondFTW");

    std::cout << std::endl;

    test = test2;

    std::cout << std::endl;

    test.whoAmI();
    test.attack("enemy");
    test.highFivesGuys();
    test.guardGate();

    std::cout << std::endl;
}
