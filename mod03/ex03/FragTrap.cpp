#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30) {
    std::cout << "FragTrap constructor called" << std::endl;
}

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

void FragTrap::highFivesGuys() const {
    std::cout << "FragTrap " << _name << " high fives everyone" << std::endl;
}
