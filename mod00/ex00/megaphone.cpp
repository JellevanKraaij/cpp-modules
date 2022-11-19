#include <iostream>
#include <cstdlib>
#include <cstring>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (EXIT_SUCCESS);
    }

    for (int i = 1; i < argc; i++) {
        for (size_t j = 0; j < std::strlen(argv[i]); j++)
            std::cout << (char)std::toupper(argv[i][j]);
    }
    std::cout << std::endl;
    return (EXIT_SUCCESS);
}
