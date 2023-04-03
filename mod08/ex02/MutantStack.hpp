#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
   public:
	MutantStack();
	MutantStack(const MutantStack &other);
	~MutantStack();

	MutantStack &operator=(const MutantStack &other);

   private:
	
};
