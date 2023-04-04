#pragma once

#include <stack>

template <typename T, typename C = std::stack<T> >
class MutantStack : public C {
   public:
    MutantStack();
    MutantStack(const MutantStack& other);
    ~MutantStack();

    MutantStack& operator=(const MutantStack& other);

    typedef typename C::container_type::iterator iterator;

    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"
