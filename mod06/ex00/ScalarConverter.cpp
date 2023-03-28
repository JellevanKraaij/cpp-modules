#include "ScalarConverter.hpp"

#include <cctype>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <typeinfo>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return (*this);
}

void ScalarConverter::convert(const std::string& literal) {
    ScalarHolder<char> charH;
    ScalarHolder<int> intH;
    ScalarHolder<float> floatH;
    ScalarHolder<double> doubleH;

    if ((intH = convertInt(literal)).isValid()) {
        charH = rangeSafeCast<char>(intH);
        floatH = rangeSafeCast<float>(intH);
        doubleH = rangeSafeCast<double>(intH);
    } else if ((charH = convertChar(literal)).isValid()) {
        intH = rangeSafeCast<int>(charH);
        floatH = rangeSafeCast<float>(charH);
        doubleH = rangeSafeCast<double>(charH);
    } else if ((floatH = convertFloat(literal)).isValid()) {
        charH = rangeSafeCast<char>(floatH);
        intH = rangeSafeCast<int>(floatH);
        doubleH = rangeSafeCast<double>(floatH);
    } else if ((doubleH = convertDouble(literal)).isValid()) {
        charH = rangeSafeCast<char>(doubleH);
        intH = rangeSafeCast<int>(doubleH);
        floatH = rangeSafeCast<float>(doubleH);
    } else {
        std::cout << "no possible conversion" << std::endl;
        return;
    }
    print(charH);
    print(intH);
    print(floatH);
    print(doubleH);
}

ScalarHolder<char> ScalarConverter::convertChar(const std::string& literal) {
    if (literal.length() != 1 || !isprint(literal.at(0)))
        return (false);

    char value = literal.at(0);
    return (value);
}

ScalarHolder<int> ScalarConverter::convertInt(const std::string& literal) {
    // stringstream parsing allows single + or - char
    if (literal.length() == 1 && !std::isdigit(literal.at(0)))
        return (false);

    std::istringstream stream(literal);

    int value;
    stream >> std::noskipws >> value;

    if (!stream.eof() || stream.fail())
        return (false);
    return (value);
}

ScalarHolder<float> ScalarConverter::convertFloat(const std::string& literal) {
    if (literal.empty() || *literal.rbegin() != 'f')
        return (false);

    std::istringstream stream(std::string(literal.begin(), literal.end() - 1));

    float value;
    stream >> std::noskipws >> value;
    if (!stream.eof() || stream.fail())
        return (false);

    return (value);
}

ScalarHolder<double> ScalarConverter::convertDouble(const std::string& literal) {
    std::istringstream stream(literal);

    double value;
    stream >> std::noskipws >> value;

    if (!stream.eof() || stream.fail())
        return (false);
    return (value);
}

void ScalarConverter::print(ScalarHolder<char> val) {
    std::cout << "char: ";
    if (!val.isValid()) {
        std::cout << "impossible" << std::endl;
        return;
    }
    char charVal;
    charVal = val.getVariable();
    if (!isprint(charVal))
        std::cout << "Non displayable";
    else
        std::cout << charVal;
    std::cout << std::endl;
}

void ScalarConverter::print(ScalarHolder<int> val) {
    std::cout << "int: ";
    if (!val.isValid()) {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << val.getVariable() << std::endl;
}
void ScalarConverter::print(ScalarHolder<float> val) {
    std::cout << "float: ";
    if (!val.isValid()) {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1) << val.getVariable() << 'f' << std::endl;
}

void ScalarConverter::print(ScalarHolder<double> val) {
    std::cout << "double: ";
    if (!val.isValid()) {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1) << val.getVariable() << std::endl;
}

template <typename Out, typename In>
ScalarHolder<Out> ScalarConverter::rangeSafeCast(ScalarHolder<In> val) {
    if (typeid(Out) == typeid(double) || typeid(Out) == typeid(float))
        return (static_cast<Out>(val.getVariable()));
    if (!(val > std::numeric_limits<Out>::min() && val < std::numeric_limits<Out>::max())) {
        return (false);
    }
    return (static_cast<Out>(val.getVariable()));
}
