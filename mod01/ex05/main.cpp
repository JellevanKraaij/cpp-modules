#include <iostream>
#include <stdexcept>

#include "Harl.hpp"

void complain(const std::string &level) {
    std::cout << "run complain with " << level << " level:" << std::endl;

    try {
        Harl::complain(level);
    } catch (const std::invalid_argument &exception) {
        std::cout << "Harl throwed exception: " << exception.what() << std::endl;
    }
    std::cout << std::endl;
}

int main(void) {
    complain("invalid");
    complain("debug");
    complain("DEBUG");
    complain("INFO");
    complain("WARNING");
    complain("ERROR");
}
