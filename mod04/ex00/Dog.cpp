#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog assignment operator called" << std::endl;
    Animal::operator=(other);
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}
