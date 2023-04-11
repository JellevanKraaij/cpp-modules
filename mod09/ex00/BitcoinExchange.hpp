#pragma once

#include <ctime>
#include <istream>
#include <map>
#include <utility>

class BitcoinExchange {
   public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool loadDatabase(std::istream &input);

    BitcoinExchange &operator=(const BitcoinExchange &other);
    float getRate(const std::string &date) const;
    static bool isValideDate(const std::string &date);
    bool empty() const;

   private:
    std::map<std::string, float> _data;
    bool parsePushLine(const std::string &line);
};
