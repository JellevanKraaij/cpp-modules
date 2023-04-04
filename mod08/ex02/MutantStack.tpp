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
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin() {
    return C::c.begin();
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end() {
    return C::c.end();
}