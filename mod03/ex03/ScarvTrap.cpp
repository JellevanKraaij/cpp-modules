#include "ScarvTrap.hpp"

#include <iostream>

ScarvTrap::ScarvTrap() {
    std::cout << "ScarvTrap constructor called" << std::endl;
}

ScarvTrap::ScarvTrap(const std::string name) : ClapTrap(name, 100, 50, 20) {
    std::cout << "ScarvTrap constructor called" << std::endl;
}

ScarvTrap::ScarvTrap(const ScarvTrap &other) : ClapTrap(other) {
    std::cout << "ScarvTrap copy constructor called" << std::endl;
}

ScarvTrap::~ScarvTrap() {
    std::cout << "ScarvTrap destructor called" << std::endl;
}

ScarvTrap &ScarvTrap::operator=(const ScarvTrap &other) {
    std::cout << "ScarvTrap assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

void ScarvTrap::guardGate() const {
    std::cout << _name << " is now in Gate keeper mode" << std::endl;
}

