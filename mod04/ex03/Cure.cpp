#include "Cure.hpp"

#include <iostream>

#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) {
    *this = other;
}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &other) {
    AMateria::operator=(other);
    return (*this);
}

AMateria *Cure::clone() {
    return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
