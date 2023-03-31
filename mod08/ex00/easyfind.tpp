#include <algorithm>
#include <iostream>

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &c, int v) {
    return (std::find(c.begin(), c.end(), v));
}
