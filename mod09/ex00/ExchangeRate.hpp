#pragma once

#include <ctime>
#include <istream>
#include <map>
#include <utility>

class ExchangeRate {
   public:
    ExchangeRate();
    ExchangeRate(const ExchangeRate &other);
    ~ExchangeRate();

    bool loadDatabase(std::istream &input);

    ExchangeRate &operator=(const ExchangeRate &other);
    float getRate(const std::string &date) const;
    static bool isValideDate(const std::string &date);
    bool empty() const;

   private:
    std::map<std::string, float> _data;
    bool parsePushLine(const std::string &line);
};
