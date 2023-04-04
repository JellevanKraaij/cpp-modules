#include <iostream>
#include <stack>

#include "MutantStack.hpp"
int main() {
    MutantStack<int> mstack;
    std::deque<int> rstack;

    mstack.push(5);
    rstack.push_front(5);

    std::cout << "pushed 5" << std::endl;

    mstack.push(17);
    rstack.push_back(17);

    std::cout << "pushed 17" << std::endl;

    std::cout << "mstack top: " << mstack.top() << std::endl;
    std::cout << "rstack top: " << rstack.back() << std::endl;

    mstack.pop();
    rstack.pop_back();

    std::cout << "popped" << std::endl;

    std::cout << "mstack top: " << mstack.top() << std::endl;
    std::cout << "rstack top: " << rstack.back() << std::endl;

    mstack.push(3);
    rstack.push_back(3);

    std::cout << "pushed 3" << std::endl;

    std::cout << "mstack top: " << mstack.top() << std::endl;
    std::cout << "rstack top: " << rstack.back() << std::endl;

    std::cout << "mstack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "rstack: ";
    for (std::deque<int>::iterator it = rstack.begin(); it != rstack.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "mstack size: " << mstack.size() << std::endl;
    std::stack<int> s(mstack);
    for (size_t i = 0; !s.empty(); ++i) {
        std::cout << "s.top(): " << s.top() << std::endl;
        s.pop();
    }
}
