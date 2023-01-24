#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(const std::string &name) : _name(name), _health(10), _energy(10), _damage(0) {
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    _name = other._name;
    _health = other._health;
    _energy = other._energy;
    _damage = other._damage;
    return (*this);
}

void ClapTrap::attack(const std::string &target) {
    if (!_energy) {
        std::cout << "ClapTrap " << _name << " has no energy left" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    _energy--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_health < amount) {
        std::cout << "ClapTrap " << _name << " can't take " << amount << " points of damage as it's more than " << _health << " points of health"
                  << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage" << std::endl;
    _health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!_energy) {
        std::cout << "ClapTrap " << _name << " has no energy left" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " repaired " << amount << " points of health" << std::endl;
    _energy--;
    _health += amount;
}
