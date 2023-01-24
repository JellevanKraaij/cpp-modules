#include <iostream>

#include "ScarvTrap.hpp"

int main(void) {
    ScarvTrap s("scarvy");
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
