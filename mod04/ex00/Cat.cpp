#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat assignment operator called" << std::endl;
    Animal::operator=(other);
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Miaow" << std::endl;
}
