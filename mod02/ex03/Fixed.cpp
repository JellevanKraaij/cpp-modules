#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const int num) : _value(_convertToRaw(num)) {
}

Fixed::Fixed(const float num) : _value(Fixed::_convertToRaw(num)) {
}

Fixed::Fixed(const Fixed &copy) {
    *this = copy;
}

Fixed::~Fixed() {
}

Fixed &Fixed::operator=(const Fixed &assign) {
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

Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed ret;

    ret.setRawBits(this->getRawBits() + rhs.getRawBits());
    return (ret);
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed ret;

    ret.setRawBits(this->getRawBits() - rhs.getRawBits());
    return (ret);
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed ret;

    ret.setRawBits(((long)this->getRawBits() * (long)rhs.getRawBits()) / (1 << _fractBits));
    return (ret);
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    Fixed ret;

    ret.setRawBits(((long)this->getRawBits() * (1 << _fractBits) / rhs.getRawBits()));
    return (ret);
}

Fixed &Fixed::operator++() {
    _value++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed old = *this;
    _value++;
    return (old);
}

Fixed &Fixed::operator--() {
    _value--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed old = *this;
    _value--;
    return (old);
}

bool Fixed::operator==(const Fixed &rhs) const {
    return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return (!(*this == rhs));
}

bool Fixed::operator<(const Fixed &rhs) const {
    return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>(const Fixed &rhs) const {
    return (rhs < *this);
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return (!(*this > rhs));
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return (!(*this < rhs));
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
    return (f1 > f2 ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
    return (f1 < f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    return (f1 > f2 ? f1 : f2);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    return (f1 < f2 ? f1 : f2);
}

Fixed Fixed::abs(const Fixed &f1)
{
    if (f1 < 0)
        return (f1 * -1);
    return (f1);
}
