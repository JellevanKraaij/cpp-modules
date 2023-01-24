#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

void FragTrap::attack(const std::string &target) {
    if (!_energy) {
        std::cout << "FragTrap " << _name << " has no energy left" << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    _energy--;
}

void FragTrap::takeDamage(unsigned int amount) {
    if (_health < amount) {
        std::cout << "FragTrap " << _name << " can't take " << amount << " points of damage as it's more than " << _health << " points of health"
                  << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " takes " << amount << " points of damage" << std::endl;
    _health -= amount;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (!_energy) {
        std::cout << "FragTrap " << _name << " has no energy left" << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " repaired " << amount << " points of health" << std::endl;
    _energy--;
    _health += amount;
}

void FragTrap::highFivesGuys() const {
    std::cout << "FragTrap high fives everyone" << std::endl;
}
