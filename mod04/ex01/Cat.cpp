#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat assignment operator called" << std::endl;
    Animal::operator=(other);
    *_brain = *other._brain;
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Miaow" << std::endl;
}

Brain *Cat::getBrain() {
    return (_brain);
}
