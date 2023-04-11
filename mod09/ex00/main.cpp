#include <iostream>
#include <fstream>

#include "ExchangeRate.hpp"

int main() {
    ExchangeRate btc;

    std::ifstream database("data.csv");
    if (!database)
    {
        std::cerr << "cannot open database" << std::endl;
        return (1);
    }

    if (!btc.parseDatabase(database))
    {
        std::cerr << "invalid database" << std::endl;
        return (1);
    }

    if (btc.empty())
    {
        std::cerr << "database is empty" << std::endl;
        return (1);
    }

    std::cout << "rate on 2018-01-01: " << btc.getRate("2018-01-01") << std::endl;
}
