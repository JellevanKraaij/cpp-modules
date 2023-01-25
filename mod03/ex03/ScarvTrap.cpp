#include "ScarvTrap.hpp"

#include <iostream>

ScarvTrap::ScarvTrap() : ClapTrap("", 100, 50, 20) {
    std::cout << "ScarvTrap constructor called" << std::endl;
}

ScarvTrap::ScarvTrap(const std::string name) : ClapTrap(name, 100, 50, 20) {
    std::cout << "ScarvTrap constructor called" << std::endl;
}

ScarvTrap::ScarvTrap(const ScarvTrap &other) : ClapTrap(other) {
    std::cout << "ScarvTrap constructor called" << std::endl;
}

ScarvTrap::~ScarvTrap() {
    std::cout << "ScarvTrap destructor called" << std::endl;
}

ScarvTrap &ScarvTrap::operator=(const ScarvTrap &other) {
    std::cout << "ScarvTrap assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

void ScarvTrap::attack(const std::string &target) {
    if (!_health) {
        std::cout << "ScarvTrap " << _name << " is dead" << std::endl;
        return;
    }
    if (!_energy) {
        std::cout << "ScarvTrap " << _name << " has no energy left" << std::endl;
        return;
    }
    std::cout << "ScarvTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    _energy--;
}

void ScarvTrap::guardGate() const {
    std::cout << "ScarvTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
