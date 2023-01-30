#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name", 100, 50, 30), _name("") {}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30), _name(name) {
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    ScavTrap::operator=(other);
    FragTrap::operator=(other);
    _name = other._name;
    return (*this);
}

void DiamondTrap::whoAmI() const {
    std::cout << "My name is " << _name << " and my ClapTrap name " << ClapTrap::_name << std::endl;
}
