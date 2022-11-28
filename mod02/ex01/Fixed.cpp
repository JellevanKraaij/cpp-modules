#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : _value(_convertToRaw(num)) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _value(Fixed::_convertToRaw(num)) {
    std::cout << "Float constructor called" << std::endl;
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
    return (os << cl.toFloat());
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

float Fixed::toFloat(void) const {
    return (Fixed::_convertToFloat(_value));
}

int Fixed::_convertToRaw(const int num) {
    return (num << _fractBits);
}

int Fixed::_convertToRaw(const float num) {
    return (roundf(num * (float)(1 << _fractBits)));
}

int Fixed::_convertToInt(const int raw) {
    return (raw / (1 << _fractBits));
}

float Fixed::_convertToFloat(const int raw) {
    return ((float)raw / (float)(1 << _fractBits));
}
