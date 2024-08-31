#include <iostream>
#include <deque>
#include <list>
#include <cstdlib>

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

	// std::cout << "deque: ";
	// for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
	// 	std::cout << *it << " ";
	// }
	std::cout << std::endl;
	std::cout << "list: ";
	for (std::list<int>::iterator it = li.begin(); it != li.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// mergeSort(dq);

	std::list<int> li2 = li;

	li2.sort();
	mergeSort(li);
	if (li == li2) {
		std::cout << "std::list is sorted" << std::endl;
	} else {
		std::cout << "std::list is not sorted" << std::endl;
		exit(1);
	}


	std::cout << "After sorting" << std::endl;

	// std::cout << "deque: ";
	// for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;

	std::cout << "list: ";
	for (std::list<int>::iterator it = li.begin(); it != li.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}
