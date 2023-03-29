#pragma once
#include <cstddef>

template <typename T>
void iter(T *arr, size_t length, void (*function)(T *)) {
    for (size_t i = 0; i < length; i++) {
        function(&arr[i]);
    }
}
