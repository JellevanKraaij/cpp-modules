#include "ScalarConverter.hpp"

#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

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

    charH = convertChar(literal);
    intH = convertInt(literal);
    floatH = convertFloat(literal);
    doubleH = convertDouble(literal);

    if (intH) {
        int val = intH;
        printChar(val);
        printInt(val);
        printFloat(val);
        printDouble(val);
    } else if (charH) {
        char val = charH;
        printChar(val);
        printInt(val);
        printFloat(val);
        printDouble(val);
    } else if (floatH) {
        float val = floatH;
        printChar(val);
        printInt(val);
        printFloat(val);
        printDouble(val);
    } else if (doubleH) {
        double val = doubleH;
        printChar(val);
        printInt(val);
        printFloat(val);
        printDouble(val);
    } else {
        std::cout << "no possible conversion" << std::endl;
    }
}

ScalarHolder<char> ScalarConverter::convertChar(const std::string& literal) {
    if (literal.length() != 1 || !isprint(literal.at(0)))
        return (false);

    char value = literal.at(0);
    return (value);
}

ScalarHolder<int> ScalarConverter::convertInt(const std::string& literal) {
    // stringstream parsing allows single + or - char
    if (literal.length() == 1 && !isnumber(literal.at(0)))
        return (false);

    std::istringstream stream(literal);

    int value;
    stream >> std::noskipws >> value;

    if (!stream.eof() || stream.fail())
        return (false);
    return (value);
}

ScalarHolder<float> ScalarConverter::convertFloat(const std::string& literal) {
    if (literal.empty() || literal.back() != 'f')
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

template <typename T>
void ScalarConverter::printChar(T val) {
    std::cout << "char: ";
    try {
        char charVal;
        charVal = rangeSafeCast<char>(val);
        if (!isprint(charVal))
            std::cout << "Non displayable";
        else
            std::cout << charVal;
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

template <typename T>
void ScalarConverter::printInt(T val) {
    std::cout << "int: ";
    try {
        std::cout << rangeSafeCast<int>(val);
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

template <typename T>
void ScalarConverter::printFloat(T val) {
    std::cout << "float: ";
    try {
        std::cout << std::fixed << std::setprecision(1) << rangeSafeCast<float>(val) << 'f';
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

template <typename T>
void ScalarConverter::printDouble(T val) {
    std::cout << "double: ";
    try {
        std::cout << std::fixed << std::setprecision(1) << rangeSafeCast<double, double>(val);
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

template <typename Out, typename In>
Out ScalarConverter::rangeSafeCast(In val) {
    if (val < std::numeric_limits<Out>::lowest() || val > std::numeric_limits<Out>::max()) {
        throw std::range_error("impossible");
    }
    return (static_cast<Out>(val));
}
