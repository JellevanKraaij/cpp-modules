#include "Harl.hpp"

#include <iostream>
#include <stdexcept>

const struct Harl::_mapLevels Harl::_mapLevels[Harl::_lookup_size] = {
    {.str = "DEBUG", .function = Harl::debug},
    {.str = "INFO", .function = Harl::info},
    {.str = "WARNING", .function = Harl::warning},
    {.str = "ERROR", .function = Harl::error},
};

void Harl::compain(std::string level) {
    (void)level;

    for (int i = 0; i < _lookup_size; i++) {
        if (_mapLevels[i].str == level) {
            _mapLevels[i].function();
            return;
        }
    }
    throw std::invalid_argument("received unknown level");
}

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void) {
    std::cout
        << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldn't be asking for more!"
        << std::endl;
}
void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
              << std::endl;
}
void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
