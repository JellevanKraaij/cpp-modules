#include "BitcoinExchange.hpp"

#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this == &other)
        return (*this);

    _data = other._data;
    return (*this);
}

bool BitcoinExchange::loadDatabase(std::istream &input) {
    std::string line;

    std::getline(input, line);
    if (line != "date,exchange_rate")
        return (false);

    while (std::getline(input, line)) {
        if (!parsePushLine(line))
            return (false);
    }
    if (input.bad())
        return (false);
    return (true);
}

bool BitcoinExchange::parsePushLine(const std::string &line) {
    std::string date;
    std::string BitcoinExchange;

    size_t pos = line.find(',');
    if (pos == std::string::npos)
        return (false);
    date = line.substr(0, pos);
    if (!isValideDate(date))
        return (false);

    BitcoinExchange = line.substr(pos + 1);
    std::istringstream BitcoinExchangeStream(BitcoinExchange);
    float rate;
    if (!(BitcoinExchangeStream >> rate) || !BitcoinExchangeStream.eof())
        return (false);
    _data[date] = rate;
    return (true);
}

bool BitcoinExchange::isValideDate(const std::string &date) {
    tm tm;
    const char *res = strptime(date.c_str(), "%Y-%m-%d", &tm);
    if (res == NULL)
        return (false);
    if (*res != '\0')
        return (false);
    return (true);
}

float BitcoinExchange::getRate(const std::string &date) const {
    if (_data.empty())
        throw std::runtime_error("no data");
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    if (it == _data.end())
        return (_data.rbegin()->second);
    if (it->first > date) {
        if (it == _data.begin())
            return (it->second);
        return (std::prev(it)->second);
    }
    return (it->second);
}

bool BitcoinExchange::empty() const {
    return (_data.empty());
}
