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

    static void print(ScalarHolder<char> val);
    static void print(ScalarHolder<int> val);
    static void print(ScalarHolder<float> val);
    static void print(ScalarHolder<double> val);

    template <typename Out, typename In>
    static ScalarHolder<Out> rangeSafeCast(ScalarHolder<In> val);
};
