#pragma once

#include <deque>

template <typename T, typename C = std::deque<T> >
class MutantStack : public C {
   public:
    MutantStack();
    MutantStack(const MutantStack& other);
    ~MutantStack();

    MutantStack& operator=(const MutantStack& other);

    void push(const T& value);
    T& top();
    void pop();
};

#include "MutantStack.tpp"
