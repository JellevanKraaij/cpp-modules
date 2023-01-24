#include "ScarvTrap.hpp"

#include <iostream>

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
    if (!_energy) {
        std::cout << "ScarvTrap " << _name << " has no energy left" << std::endl;
        return;
    }
    std::cout << "ScarvTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    _energy--;
}

void ScarvTrap::takeDamage(unsigned int amount) {
    if (_health < amount) {
        std::cout << "ScarvTrap " << _name << " can't take " << amount << " points of damage as it's more than " << _health << " points of health"
                  << std::endl;
        return;
    }
    std::cout << "ScarvTrap " << _name << " takes " << amount << " points of damage" << std::endl;
    _health -= amount;
}

void ScarvTrap::beRepaired(unsigned int amount) {
    if (!_energy) {
        std::cout << "ScarvTrap " << _name << " has no energy left" << std::endl;
        return;
    }
    std::cout << "ScarvTrap " << _name << " repaired " << amount << " points of health" << std::endl;
    _energy--;
    _health += amount;
}

void ScarvTrap::guardGate() const {
    std::cout << "ScarvTrap is now in Gate keeper mode" << std::endl;
}
