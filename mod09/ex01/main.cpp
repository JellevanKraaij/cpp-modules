#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Error" << std::endl;
        return (1);
    }
    std::string input;
    for (int i = 1; i < argc; i++) {
        input += argv[i];
        input += " ";
    }
    try {
        std::cout << RPNcalculate(input) << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error" << std::endl;
        return (1);
    }
}
