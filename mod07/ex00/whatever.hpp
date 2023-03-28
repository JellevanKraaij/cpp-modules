#pragma once

template <typename T>
void swap(T& s1, T& s2) {
    const T tmp = s1;
    s1 = s2;
    s2 = tmp;
}

template <typename T>
T min(T& v1, T& v2) {
    return (v1 < v2 ? v1 : v2);
}

template <typename T>
T max(T& v1, T& v2) {
    return (v1 > v2 ? v1 : v2);
}
