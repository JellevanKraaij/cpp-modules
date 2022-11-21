#include <cstdlib>
#include <iostream>
#include <string>

#ifndef __APPLE__
# define ALLOW_FALLTHROUGH  __attribute__((fallthrough))
#else
# define ALLOW_FALLTHROUGH {}
#endif

#include "Harl.hpp"

int switchString(const std::string &str, const std::string lookup[], int lookupLen) {
    for (int i = 0; i < lookupLen; i++) {
        if (lookup[i] == str)
            return (i);
    }
    return (-1);
}

void compain(const std::string &level) {
    std::cout << "[ " << level << " ]" << std::endl;
    Harl::compain(level);
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " 'inputFile' 'search' 'replace'" << std::endl;
        return (EXIT_FAILURE);
    }

    static const std::string lookup[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    switch (switchString(argv[1], lookup, 4)) {
        case 0:
            compain("DEBUG");
            ALLOW_FALLTHROUGH;
        case 1:
            compain("INFO");
            ALLOW_FALLTHROUGH;
        case 2:
            compain("WARNING");
            ALLOW_FALLTHROUGH;
        case 3:
            compain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
