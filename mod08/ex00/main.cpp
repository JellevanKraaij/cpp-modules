#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main() {
    std::vector<int> test(10);

    for (int i = 0; i < 10; i++)
        test[i] = i;
    std::vector<int>::iterator it = easyfind(test, 5);
    if (it == test.end())
        std::cout << "5 not found" << std::endl;
    else
        std::cout << "Found " << *it << " at index " << it - test.begin() << std::endl;

    std::vector<int>::iterator it2 = easyfind(test, 42);
    if (it2 == test.end())
        std::cout << "42 not found" << std::endl;
    else
        std::cout << "Found " << *it2 << " at index " << it2 - test.begin() << std::endl;
    return (0);
}
