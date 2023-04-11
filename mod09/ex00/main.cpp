#include <fstream>
#include <iostream>
#include <sstream>

#include "BitcoinExchange.hpp"

BitcoinExchange prepareBitcoinExchange(const std::string &filename) {
    BitcoinExchange btcExchange;

    std::ifstream database(filename);
    if (!database) {
        std::cout << "Error: could not open database" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!btcExchange.loadDatabase(database)) {
        std::cout << "Error: invalid database file" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (btcExchange.empty()) {
        std::cout << "Error: database is empty" << std::endl;
        exit(EXIT_FAILURE);
    }
    return (btcExchange);
}

void handleLine(const std::string &line, const BitcoinExchange &BitcoinExchange) {
    size_t pos = line.find(" | ");
    if (pos == std::string::npos) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    const std::string date = line.substr(0, pos);
    if (!BitcoinExchange::isValideDate(date)) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    const std::string value = line.substr(pos + 3);
    std::istringstream valueStream(value);
    float amount;
    if (!(valueStream >> amount) || !valueStream.eof()) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    if (amount < 0) {
        std::cout << "Error: not a positive number => " << line << std::endl;
        return;
    }
    if (amount > 1000) {
        std::cout << "Error: too large number => " << line << std::endl;
        return;
    }
    std::cout << date << " => " << amount << " = " << amount * BitcoinExchange.getRate(date) << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <inputfile> [database]" << std::endl;
        exit(EXIT_FAILURE);
    }
    BitcoinExchange btcExchange = prepareBitcoinExchange(argc < 3 ? "data.csv" : argv[2]);

    std::ifstream input(argv[1]);
    if (!input) {
        std::cout << "Error: could not open input file" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(input, line)) {
        handleLine(line, btcExchange);
    }
    if (input.bad()) {
        std::cout << "Error: read from input file failed" << std::endl;
        exit(EXIT_FAILURE);
    }
}
