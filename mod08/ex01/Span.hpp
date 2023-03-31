#pragma once

#include <vector>

class Span {
   public:
    Span();
    Span(const unsigned int maxSize);
    Span(const Span &other);
    ~Span();

    Span &operator=(const Span &other);

    void addNumber(const int number);

    unsigned int shortestSpan();
    unsigned int longestSpan();

    template <typename T>
    void addRange(T begin, T end);

   private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
};

#include "Span.tpp"
