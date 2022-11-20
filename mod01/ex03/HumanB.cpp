#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack() const {
    if (_weapon == NULL) {
        std::cout << _name << " is not armed" << std::endl;
        return;
    }
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}
