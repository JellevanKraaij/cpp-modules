#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    WrongAnimal::operator=(other);
    return (*this);
}

void WrongCat::makeSound() const {
    std::cout << "Miaow" << std::endl;
}
