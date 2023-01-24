#include <iostream>

#include "FragTrap.hpp"
#include "ScarvTrap.hpp"

int main(void) {
    ClapTrap c("clappy");
    ScarvTrap s("scarvy");
    FragTrap f("fraggy");

    std::cout << std::endl;

    c.attack("enemy");
    s.attack("enemy");
    f.attack("enemy");

    std::cout << std::endl;

    c.beRepaired(50);
    c.takeDamage(120);
    s.beRepaired(50);
    s.takeDamage(120);
    f.beRepaired(50);
    f.takeDamage(120);

    std::cout << std::endl;

    s.guardGate();
    f.highFivesGuys();

    std::cout << std::endl;
}
