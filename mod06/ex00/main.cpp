#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
    std::string value;

    if (argc < 2)
        value = "";
    else
        value = argv[1];
    std::cout << "input: '" << value << '\'' << std::endl;

    ScalarConverter::convert(value);
}
