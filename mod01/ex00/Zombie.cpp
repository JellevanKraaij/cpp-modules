#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(const std::string &name) : _name(name) {
    _printMessage("born");
}

Zombie::~Zombie() {
    _printMessage("died");
}

void Zombie::announce(void) {
    _printMessage("BraiiiiiiinnnzzzZ...");
}

void Zombie::_printMessage(const std::string &message) const {
    std::cout << _name << ": " << message << std::endl;
}
