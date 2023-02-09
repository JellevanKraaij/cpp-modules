#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal") {
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string &type) : type(type) {
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = other;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    std::cout << "AAnimal assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}

std::string AAnimal::getType() const {
    return (type);
}
