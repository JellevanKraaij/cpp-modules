#include <fstream>
#include <iostream>
#include <sstream>

#include "ExchangeRate.hpp"

ExchangeRate prepareExchangeRate(const std::string &filename) {
    ExchangeRate exchangeRate;

    std::ifstream database(filename);
    if (!database) {
        std::cout << "Error: could not open database" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!exchangeRate.loadDatabase(database)) {
        std::cout << "Error: invalid database file" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (exchangeRate.empty()) {
        std::cout << "Error: database is empty" << std::endl;
        exit(EXIT_FAILURE);
    }
    return (exchangeRate);
}

void handleLine(const std::string &line, const ExchangeRate &btc) {
    size_t pos = line.find(" | ");
    if (pos == std::string::npos) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    const std::string date = line.substr(0, pos);
    if (!ExchangeRate::isValideDate(date)) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    const std::string value = line.substr(pos + 3);
    std::istringstream valueStream(value);
    float rate;
    if (!(valueStream >> rate) || !valueStream.eof()) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    if (rate < 0) {
        std::cout << "Error: not a positive number => " << line << std::endl;
        return;
    }
    if (rate > 1000) {
        std::cout << "Error: too large number => " << line << std::endl;
        return;
    }

    std::cout << date << " => " << rate << " * " << btc.getRate(date) << " = " << rate * btc.getRate(date) << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <inputfile> [database]" << std::endl;
        exit(EXIT_FAILURE);
    }
    ExchangeRate btc = prepareExchangeRate(argc < 3 ? "data.csv" : argv[2]);

    std::ifstream input(argv[1]);
    if (!input) {
        std::cout << "Error: could not open input file" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(input, line)) {
        handleLine(line, btc);
    }
    if (input.bad()) {
        std::cout << "Error: read from input file failed" << std::endl;
        exit(EXIT_FAILURE);
    }
}
