#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "incorrect parameters" << std::endl;
        return (EXIT_FAILURE);
    }
    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(((std::string)argv[1] + ".replace").c_str());

    char cBuff;
    std::string str;
    while (inputFile.get(cBuff)) {
        if (argv[2][str.length()] == cBuff)
            str += cBuff;
        else {
            outputFile << str;
            str.clear();
            outputFile << cBuff;
        }
        if (str.length() == std::strlen(argv[2]) && !str.empty()) {
            outputFile << argv[3];
            str.clear();
        }
    }
}
