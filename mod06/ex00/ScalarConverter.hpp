#pragma once

#include <string>

#include "ScalarHolder.hpp"

class ScalarConverter {
   public:
    static void convert(const std::string& literal);

   protected:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter();

    ScalarConverter& operator=(const ScalarConverter& other);

   private:
    static ScalarHolder<char> convertChar(const std::string& literal);
    static ScalarHolder<int> convertInt(const std::string& literal);
    static ScalarHolder<float> convertFloat(const std::string& literal);
    static ScalarHolder<double> convertDouble(const std::string& literal);

    template <typename T>
    static void printChar(T val);
    template <typename T>
    static void printInt(T val);
    template <typename T>
    static void printFloat(T val);
    template <typename T>
    static void printDouble(T val);

    template <typename Out, typename In>
    static Out rangeSafeCast(In val);
};
