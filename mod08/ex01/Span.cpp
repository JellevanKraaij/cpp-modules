#include "Span.hpp"

#include <algorithm>

Span::Span() : _maxSize(0), _numbers() {}

Span::Span(const unsigned int maxSize) : _maxSize(maxSize), _numbers() {}

Span::Span(const Span &other) {
    *this = other;
}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this == &other)
        return (*this);
    _numbers = other._numbers;
    _maxSize = other._maxSize;
    return (*this);
}

void Span::addNumber(const int number) {
    if (_numbers.size() >= _maxSize)
        throw std::length_error("Span no more space left");
    _numbers.push_back(number);
}

unsigned int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::out_of_range("Span can't get span with less than 2 numbers");

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    return ((long)sortedNumbers.back() - (long)sortedNumbers.front());
}

unsigned int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw std::out_of_range("Span can't get span with less than 2 numbers");

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    unsigned int shortestSpan = std::numeric_limits<unsigned int>::max();

    for (std::vector<int>::iterator it = sortedNumbers.begin(); (it + 1) < sortedNumbers.end(); it++) {
        if ((long)*(it + 1) - (long)*it < shortestSpan)
            shortestSpan = (long)*(it + 1) - (long)*it;
    }
    return (shortestSpan);
}
