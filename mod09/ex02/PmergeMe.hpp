#pragma once
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>

#ifndef DEBUG
#define DEBUG 1
#endif

// template <template <class> class ContainerType, class NumberType>
// class PmergeMe {
// public:
//     static void mergeSort(ContainerType<NumberType>& li);

// private:
//     static ContainerType<std::pair<NumberType, NumberType> > createPairs(ContainerType<NumberType>& li);
// };

// #include "PmergeMe.tpp"

bool compare(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    return p1.first < p2.first;
}

std::list<std::pair<int, int> > createPairs(std::list<int>& li) {
    size_t place = 0;
    std::list<std::pair<int, int> > pairs;
    for (std::list<int>::iterator it = li.begin(); it != li.end(); ++it, ++place) {
        if (place % 2 == 0) {
            pairs.push_back(std::make_pair(*it, -1));
        } else {
            pairs.back().second = *it;
        }
    }
    return pairs;
}

void sortEachPair(std::list<std::pair<int, int> >& pairs) {
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }
}

size_t jacobsthal(size_t n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void printPairs(const std::list<std::pair<int, int> >& pairs) {
    for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it != pairs.begin())
            std::cout << " | ";
        std::cout << std::setw(2) << it->first;
    }
    std::cout << std::endl;
    for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it != pairs.begin())
            std::cout << " | ";
        if (it->second < 0)
            std::cout << std::setw(2) << 'x';
        else
            std::cout << std::setw(2) << it->second;
    }
    std::cout << std::endl;
}

bool find_next_compare(const std::pair<int, int>& p) {
    return p.second >= 0;
}

std::list<std::pair<int, int> >::iterator find_next(std::list<std::pair<int, int> >& pairs, std::list<std::pair<int, int> >::iterator start) {
    return std::find_if(start, pairs.end(), find_next_compare);
}

void mergeSort(std::list<int>& li) {
    std::list<std::pair<int, int> > pairs;

    bool uneven = li.size() % 2;
    int uneven_value = 0;
    if (uneven) {
        uneven_value = li.back();
        li.pop_back();
    }

    pairs = createPairs(li);
    // std::cout << "pairs: ";
    // printPairs(pairs);

    // sort each individual pair so that the first element is the larges: [3, 1] -> [3, 1]
    sortEachPair(pairs);

    // sort pairs by their first element: [3, 1] -> [1, 3]
    pairs.sort(compare);

    if (DEBUG) {
        std::cout << "pairs sorted by their first/largest element: " << std::endl;
        printPairs(pairs);
    }

    // insert first element, as its always smaller than the second element

    int first = pairs.front().second;
    pairs.front().second = -1;
    pairs.push_front(std::make_pair(first, -1));

    if (DEBUG) {
        std::cout << "inserting " << first << " at the beginning" << std::endl;
        std::cout << "pairs with first element inserted: " << std::endl;
        printPairs(pairs);
    }

    std::list<std::pair<int, int> >::iterator it;
    size_t length = pairs.size() - 2;
    size_t jacobs_it = 0, jacobs_original = 0, jacobs_index = 2;
    for (size_t i = 0; i < length; ++i) {
        if (jacobs_it == 0) {
            jacobs_original = jacobsthal(jacobs_index++);
            jacobs_it = jacobs_original < length - i ? jacobs_original : length - i;
        }
        it = pairs.begin();
        for (size_t j = 0; j < jacobs_it; ++j) {
            it = find_next(pairs, it);
            it++;
        }
        it--;

        int number = it->second;
        it->second = -1;
        std::list<std::pair<int, int> >::iterator insert_it = std::upper_bound(pairs.begin(), it, std::make_pair(number, -1), compare);


        if (DEBUG) {
            std::list<std::pair<int, int> >::iterator insert_it_prev = insert_it;
            insert_it_prev--;
            std::cout << "jacobsthal " << jacobs_original << "-" << jacobs_it << " inserting " << number << " between " << insert_it_prev->first
                      << "|" << insert_it->first << " found in range " << pairs.front().first << "<->" << it->first << std::endl;
        }

        pairs.insert(insert_it, std::make_pair(number, -1));

        if (DEBUG) {
            std::cout << "result: " << std::endl;
            printPairs(pairs);
        }
        --jacobs_it;
    }

    if (uneven) {
        std::list<std::pair<int, int> >::iterator insert_it = std::upper_bound(pairs.begin(), pairs.end(), std::make_pair(uneven_value, -1), compare);

        if (DEBUG) {
            std::list<std::pair<int, int> >::iterator insert_it_prev = insert_it;
            insert_it_prev--;
            std::cout << "uneven value " << uneven_value << " inserting between " << insert_it_prev->first << "|" << insert_it->first
                      << " found in range " << pairs.front().first << "<->" << pairs.back().first << std::endl;
        }
        pairs.insert(insert_it, std::make_pair(uneven_value, -1));
    }

    if (DEBUG) {
        std::cout << "pairs after sorting: " << std::endl;
        printPairs(pairs);
    }

    li.clear();
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        li.push_back(it->first);
    }
}
