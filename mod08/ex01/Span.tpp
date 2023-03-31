#include "Span.hpp"

template <typename T>
void Span::addRange(T begin, T end) {
    if (end - begin > _maxSize)
        throw std::length_error("Span no more space left");

    for (T it = begin; it < end; it++) {
        _numbers.push_back(*it);
    }
}
