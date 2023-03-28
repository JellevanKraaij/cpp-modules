#include <iostream>
#include <random>

#include "iter.hpp"

template <typename T>
void genramdom_iter(T *elem) {
    static bool init = false;
    if (!init) {
        std::srand(std::time(nullptr));
        init = true;
    }
    *elem = (std::rand() % 64) + 'A';
    std::cout << *elem << ",";
}

template <typename T>
void print_iter(T *elem) {
    std::cout << *elem << ",";
}

int main(void) {
    char arr_char[10];
    int arr_int[10];

    iter(arr_char, 10, genramdom_iter);
    std::cout << std::endl;
    iter(arr_char, 10, print_iter);
    std::cout << std::endl;

    std::cout << "=====================" << std::endl;

    iter(arr_int, 10, genramdom_iter);
    std::cout << std::endl;
    iter(arr_int, 10, print_iter);
    std::cout << std::endl;
}
