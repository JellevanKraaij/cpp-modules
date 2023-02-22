#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) {
    _brain = new Brain();
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog assignment operator called" << std::endl;
    AAnimal::operator=(other);
    *_brain = *other._brain;
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

Brain *Dog::getBrain() {
    return (_brain);
}
