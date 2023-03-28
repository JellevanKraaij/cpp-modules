#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**) {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++) {
        if (numbers[i] != 0) {
            std::cerr << "array is not initialized by default" << std::endl;
            return (1);
        }
    }

    if (numbers.size() != MAX_VAL) {
        std::cerr << "size of numbers is not correct" << std::endl;
        return (1);
    }
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        tmp[5] = 10;
        Array<int> test(tmp);
        test[5] = 5;

        if (tmp[5] != 10) {
            std::cerr << "copy constructor doesnt work, value is changed" << std::endl;
            return 1;
        }
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }

    delete[] mirror;
    return 0;
}