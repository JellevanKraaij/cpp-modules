#include "ScalarConverter.hpp"

#include <exception>
#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>

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
    std::cout << "input: '" << literal << '\'' << std::endl;

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
    }
}

ScalarHolder<char> ScalarConverter::convertChar(const std::string& literal) {
    if (literal.length() != 1 || !isprint(literal.at(0))) {
        std::cout << "char convert failed" << std::endl;
        return (false);
    }
    char value = literal.at(0);
    std::cout << "char convert success res: " << value << std::endl;
    return (value);
}

ScalarHolder<int> ScalarConverter::convertInt(const std::string& literal) {
    // stringstream parsing allows single + or - char
    if (literal.length() == 1 && !isnumber(literal.at(0))) {
        std::cout << "int convert failed" << std::endl;
        return (false);
    }

    std::istringstream stream(literal);

    int value;
    stream >> std::noskipws >> value;

    if (!stream.eof() || stream.fail()) {
        std::cout << "int convert failed" << std::endl;
        return (false);
    }
    std::cout << "int convert success res: " << value << std::endl;
    return (value);
}

ScalarHolder<float> ScalarConverter::convertFloat(const std::string& literal) {
    if (literal.empty() || literal.back() != 'f') {
        std::cout << "float convert failed" << std::endl;
        return (false);
    }
    std::istringstream stream(std::string(literal.begin(), literal.end() - 1));

    float value;
    stream >> std::noskipws >> value;

    if (!stream.eof() || stream.fail()) {
        std::cout << "float convert failed" << std::endl;
        return (false);
    }
    std::cout << "float convert success res: " << value << std::endl;
    return (value);
}

ScalarHolder<double> ScalarConverter::convertDouble(const std::string& literal) {
    std::istringstream stream(literal);

    double value;
    stream >> std::noskipws >> value;

    if (!stream.eof() || stream.fail()) {
        std::cout << "double convert failed" << std::endl;
        return (false);
    }
    std::cout << "double convert success res: " << value << std::endl;
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
        return;
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
        return;
    }
    std::cout << std::endl;
}

template <typename T>
void ScalarConverter::printFloat(T val) {
    std::cout << "float: ";
    try {
        std::cout << rangeSafeCast<float>(val) << 'f';
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

template <typename T>
void ScalarConverter::printDouble(T val) {
    std::cout << "double: ";
    try {
        std::cout << std::setprecision(2) << rangeSafeCast<double>(val);
    } catch (const std::exception& e) {
        std::cout << e.what();
        return;
    }
    std::cout << std::endl;
}

template <typename Out, typename In>
Out ScalarConverter::rangeSafeCast(In val) {
    if (val < std::numeric_limits<Out>::min() || val > std::numeric_limits<Out>::max()) {
        throw std::range_error("impossible");
    }
    return (static_cast<Out>(val));
}
