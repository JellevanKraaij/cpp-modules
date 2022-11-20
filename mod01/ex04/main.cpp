#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./mysed 'inputFile' 'search' 'replace'" << std::endl;
        return (EXIT_FAILURE);
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "failed to open input file" << std::endl;
        return (EXIT_FAILURE);
    }
    std::ofstream outputFile(((std::string)argv[1] + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "failed to open output file" << std::endl;
        return (EXIT_FAILURE);
    }

    char cBuff;
    std::string strBuff;
    while (inputFile.get(cBuff)) {
        if (argv[2][strBuff.length()] == cBuff)
            strBuff += cBuff;
        else {
            outputFile << strBuff;
            strBuff.clear();
            outputFile << cBuff;
        }
        if (strBuff.length() == std::strlen(argv[2]) && !strBuff.empty()) {
            outputFile << argv[3];
            strBuff.clear();
        }
    }
}
