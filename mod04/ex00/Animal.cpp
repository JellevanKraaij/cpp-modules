#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type) {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}

std::string Animal::getType() const {
    return (type);
}

void Animal::makeSound() const {
    std::cout << "default Animal sound" << std::endl;
}
