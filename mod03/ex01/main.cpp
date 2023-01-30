#include <iostream>

#include "ScavTrap.hpp"

int main(void) {
    ScavTrap s("sarvy");
    ClapTrap c("clappy");

    std::cout << std::endl;

    c.attack("enemy");
    s.attack("enemy");

    std::cout << std::endl;

    c.beRepaired(50);
    c.takeDamage(120);
    s.beRepaired(50);
    s.takeDamage(120);

    std::cout << std::endl;

    s.guardGate();

    std::cout << std::endl;
}
