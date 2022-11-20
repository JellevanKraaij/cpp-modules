#include <iostream>
#include <stdexcept>

#include "Harl.hpp"

void compain(const std::string &level) {
    std::cout << "run compain with " << level << " level:" << std::endl;

    try {
        Harl::compain(level);
    } catch (const std::invalid_argument &exception) {
        std::cout << "Harl throwed exception: " << exception.what() << std::endl;
    }
    std::cout << std::endl;
}

int main(void) {
    compain("invalid");
    compain("debug");
    compain("DEBUG");
    compain("INFO");
    compain("WARNING");
    compain("ERROR");
}
