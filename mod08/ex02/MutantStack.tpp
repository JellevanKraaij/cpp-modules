#include "MutantStack.hpp"

template <typename T, typename C>
MutantStack<T, C>::MutantStack() : C() {}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack() {}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack& other) : C(other) {}

template <typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator=(const MutantStack& other) {
    C::operator=(other);
}

template <typename T, typename C>
void MutantStack<T, C>::push(const T& value) {
    C::push_back(value);
}

template <typename T, typename C>
T& MutantStack<T, C>::top() {
    return (std::deque<T>::back());
}

template <typename T, typename C>
void MutantStack<T, C>::pop() {
    C::pop_back();
}
