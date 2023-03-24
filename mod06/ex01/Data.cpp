#include "Data.hpp"

#include <iostream>

Data::Data() : _message("default") {}

Data::Data(const std::string& message) : _message(message) {}

Data::Data(const Data& other) {
    *this = other;
}

Data::~Data() {}

Data& Data::operator=(const Data& other) {
    if (this == &other)
        return (*this);
    _message = other._message;
    return (*this);
}

void Data::printMessage() const {
    std::cout << _message << std::endl;
}