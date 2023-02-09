#include "Ice.hpp"

#include <iostream>

#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) {
    *this = other;
}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &other) {
    AMateria::operator=(other);
    return (*this);
}

AMateria *Ice::clone() {
    return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
