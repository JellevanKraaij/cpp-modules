#include "ExchangeRate.hpp"
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>

ExchangeRate::ExchangeRate() {}

ExchangeRate::ExchangeRate(const ExchangeRate& other) {
	*this = other;
}

ExchangeRate::~ExchangeRate() {}

ExchangeRate& ExchangeRate::operator=(const ExchangeRate &other) {
	if (this ==& other)
		return (*this);

	_data = other._data;
	return(*this);
}

bool ExchangeRate::parseDatabase(std::istream &input)
{
	std::string line;

	std::getline(input, line);
	if (line != "date,exchange_rate")
		return (false);
	
	while (std::getline(input, line))
	{
		std::cout << "line: " << line << std::endl;
		if (!parsePushLine(line))
			return (false);
	}
	if (input.bad())
		return (false);
	return (true);
}

bool ExchangeRate::parsePushLine(const std::string &line)
{
	std::string date;
	std::string exchangeRate;
	
	size_t pos = line.find(',');
	if (pos == std::string::npos)
		return (false);
	date = line.substr(0, pos);
	if (!isValideDate(date))
		return (false);
	
	exchangeRate = line.substr(pos + 1);
	std::istringstream exchangeRateStream(exchangeRate);
	float rate;
	if (!(exchangeRateStream >> rate) || !exchangeRateStream.eof())
		return (false);
	_data[date] = rate;
	return (true);
}

bool ExchangeRate::isValideDate(const std::string &date) const
{
	int year, month, day;
	if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	return (true);
}

float ExchangeRate::getRate(const std::string &date) const
{
	if (_data.empty())
		throw std::runtime_error("no data");
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
	if (it == _data.end())
		return (_data.rbegin()->second);
	return (it->second);
}

bool ExchangeRate::empty() const
{
	return (_data.empty());
}

