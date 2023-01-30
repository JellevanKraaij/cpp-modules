#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20) {
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20) {
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

void ScavTrap::attack(const std::string &target) {
    if (!_health) {
        std::cout << "ScavTrap " << _name << " is dead" << std::endl;
        return;
    }
    if (!_energy) {
        std::cout << "ScavTrap " << _name << " has no energy left" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    _energy--;
}

void ScavTrap::guardGate() const {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
