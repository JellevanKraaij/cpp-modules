#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _health(10), _energy(10), _damage(0), _name(name) {
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, unsigned int health, unsigned int energy, unsigned int damage)
    : _health(health), _energy(energy), _damage(damage), _name(name) {
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
    if (!_health) {
        std::cout << _name << " is dead" << std::endl;
        return;
    }
    if (!_energy) {
        std::cout << _name << " has no energy left" << std::endl;
        return;
    }
    std::cout << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    _energy--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (!_health) {
        std::cout << _name << " is dead" << std::endl;
        return;
    }
    if (_health < amount) {
        std::cout << _name << " takes " << amount << " points of damage resulting in death" << std::endl;
        _health = 0;
        return;
    }
    std::cout << _name << " takes " << amount << " points of damage" << std::endl;
    _health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!_health) {
        std::cout << _name << " is dead" << std::endl;
        return;
    }
    if (!_energy) {
        std::cout << _name << " has no energy left" << std::endl;
        return;
    }
    std::cout << _name << " repaired " << amount << " points of health" << std::endl;
    _energy--;
    _health += amount;
}
