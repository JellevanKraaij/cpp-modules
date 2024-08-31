#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Error: no input numbers" << std::endl;
        return 1;
    }
    std::deque<int> dq;
    std::list<int> li;
    for (int i = 1; i < argc; ++i) {
        int num = atoi(argv[i]);
        if (num < 0) {
            std::cout << "Error: negative number" << std::endl;
            return 1;
        }
        dq.push_back(num);
        li.push_back(num);
    }

    std::cout << "Before: " << std::endl;
    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::list<int> check_list = li;
    std::deque<int> check_deque = dq;

    // cpp98
    std::clock_t t1, t2;
    double listTime, dequeTime;

    t1 = std::clock();
    PmergeMe<std::list, int>::mergeSort(li);
    t2 = std::clock();

    listTime = (t2 - t1) / (double)CLOCKS_PER_SEC;

    t1 = std::clock();
    PmergeMe<std::deque, int>::mergeSort(dq);
    t2 = std::clock();

    dequeTime = (t2 - t1) / (double)CLOCKS_PER_SEC;

    std::cout << "After: " << std::endl;

    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    check_list.sort();
    std::sort(check_deque.begin(), check_deque.end());
    if (li != check_list || dq != check_deque) {
        std::cout << "Error: result is not sorted correctly" << std::endl;
        return 1;
    }

    std::cout << "Time to process a range of " << li.size() << " elements with std::list : " << listTime * 1000 << " ms" << std::endl;
    std::cout << "Time to process a range of " << dq.size() << " elements with std::deque : " << dequeTime * 1000 << " ms" << std::endl;

    return 0;
}
