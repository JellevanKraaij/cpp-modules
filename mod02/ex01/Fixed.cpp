#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : _value(Fixed::_convertToRaw(num)) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &assign) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = assign.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &cl) {
    os << cl.toInt() << std::endl; //TODO: fix
    return (os);
}

int Fixed::getRawBits(void) const {
    return (_value);
}

void Fixed::setRawBits(const int raw) {
    _value = raw;
}

int Fixed::toInt(void) const {
	return (Fixed::_convertToInt(_value));
}

int Fixed::_convertToRaw(const int val) {
    return (val << _fractBits);
}
int Fixed::_convertToInt(const int val) {
    return (val >> _fractBits);
}
