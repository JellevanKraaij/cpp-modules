
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <typeinfo>

#include "PmergeMe.hpp"

// with debug
template <template <class, class> class ContainerType, class NumberType, class Allocator>
void PmergeMe<ContainerType, NumberType, Allocator>::mergeSort(ContainerType<NumberType, Allocator> &li) {
    // store the last element if the list is uneven (otherwise one of the pairs will be incomplete)

    if (li.size() <= 1) {
        return;
    }

    bool uneven = li.size() % 2;
    NumberType uneven_value = 0;
    if (uneven) {
        uneven_value = li.back();
        li.pop_back();
    }

    // group the elements in pairs
    ContainerType<std::pair<NumberType, NumberType>, Allocator> pairs = createPairs(li);

    // sort each individual pair so that the first element is the largest: [1 3] -> [3 1]
    sortIndividualPairs(pairs);

    // sort pairs by their first element: [5, 2], [3, 1] -> [3, 1], [5, 2]
    sortPairs(pairs);

    if (DEBUG) {
        std::cout << "individual pairs sorted and pairs sorted by their first/largest element: " << std::endl;
        printPairs(pairs);
    }

    // insert the second element of pair 1 at the beginning, as it is always smaller than first element of pair 1
    NumberType first = pairs.front().second;
    pairs.front().second = EMPTY_VALUE;
    pairs.push_front(std::make_pair(first, EMPTY_VALUE));

    if (DEBUG) {
        std::cout << "inserting " << first << " at the beginning" << std::endl;
        std::cout << "pairs with first element inserted: " << std::endl;
        printPairs(pairs);
    }

    // insert the remaining elements in the list following the jacobsthal sequence starting from 2 (2, 6, 10, 22, 42)
    size_t jacobs_it = 0, jacobs = 0, jacobs_index = 2;
    while (true) {
        if (jacobs_it >= jacobs) {
            jacobs = jacobsthal(jacobs_index++);
            jacobs_it = 0;
        }

        // find the next element to insert using the jacobsthal sequence to determine the number of elements to skip
        typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::iterator to_insert = findNext(pairs, jacobs - jacobs_it);
        if (to_insert == pairs.end()) {
            break;
        }

        // retrieve the number to insert and mark the pair as empty
        NumberType number = to_insert->second;
        to_insert->second = EMPTY_VALUE;

        // find the location to insert the number starting from the beginning of the list to the current element (as its always smaller than the
        // current element)
        typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::iterator insert_location =
            std::upper_bound(pairs.begin(), to_insert, std::make_pair(number, EMPTY_VALUE), compare);

        if (DEBUG) {
            if (insert_location != pairs.begin()) {
                typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::iterator insert_location_prev = insert_location;
                insert_location_prev--;
                std::cout << "jacobsthal " << jacobs << "-" << jacobs_it << " inserting " << number << " between " << insert_location_prev->first
                          << "|" << insert_location->first << " found in range " << pairs.front().first << "<->" << to_insert->first << std::endl;
            } else
                std::cout << "jacobsthal " << jacobs << "-" << jacobs_it << " inserting " << number << " between x|" << insert_location->first
                          << " found in range " << pairs.front().first << "<->" << to_insert->first << std::endl;
        }

        // insert the number at the determined location
        pairs.insert(insert_location, std::make_pair(number, EMPTY_VALUE));

        if (DEBUG) {
            std::cout << "result: " << std::endl;
            printPairs(pairs);
        }
        ++jacobs_it;
    }

    // insert the last element if the list was uneven
    if (uneven) {
        // find the location to insert the uneven value searching in the whole list
        typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::iterator insert_location =
            std::upper_bound(pairs.begin(), pairs.end(), std::make_pair(uneven_value, EMPTY_VALUE), compare);

        if (DEBUG) {
            typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::iterator insert_location_prev = insert_location;
            insert_location_prev--;
            std::cout << "uneven value " << uneven_value << " inserting between " << insert_location_prev->first << "|" << insert_location->first
                      << " found in range " << pairs.front().first << "<->" << pairs.back().first << std::endl;
        }

        // insert the uneven value at the determined location
        pairs.insert(insert_location, std::make_pair(uneven_value, EMPTY_VALUE));
        if (DEBUG) {
            std::cout << "result: " << std::endl;
            printPairs(pairs);
        }
    }

    // copy the sorted elements back to the original list
    li.clear();
    for (typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        li.push_back(it->first);
    }
}

template <template <class, class> class ContainerType, class NumberType, class Allocator>
ContainerType<std::pair<NumberType, NumberType>, Allocator> PmergeMe<ContainerType, NumberType, Allocator>::createPairs(
    const ContainerType<NumberType, Allocator> &li) {
    ContainerType<std::pair<NumberType, NumberType>, Allocator> pairs;
    size_t i = 0;
    for (typename ContainerType<NumberType, Allocator>::const_iterator it = li.begin(); it != li.end(); ++it, ++i) {
        if (i % 2 == 0) {
            pairs.push_back(std::make_pair(*it, EMPTY_VALUE));
        } else {
            pairs.back().second = *it;
        }
    }
    return pairs;
}

template <template <class, class> class ContainerType, class NumberType, class Allocator>
void PmergeMe<ContainerType, NumberType, Allocator>::sortIndividualPairs(ContainerType<std::pair<NumberType, NumberType>, Allocator> &pairs) {
    for (typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it->first < it->second) {
            std::swap(it->first, it->second);
        }
    }
}

template <template <class, class> class ContainerType, class NumberType, class Allocator>
size_t PmergeMe<ContainerType, NumberType, Allocator>::jacobsthal(size_t n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

template <template <class, class> class ContainerType, class NumberType, class Allocator>
void PmergeMe<ContainerType, NumberType, Allocator>::printPairs(const ContainerType<std::pair<NumberType, NumberType>, Allocator> &pairs) {
    for (typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it != pairs.begin())
            std::cout << " | ";
        std::cout << std::setw(2) << it->first;
    }
    std::cout << std::endl;
    for (typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it != pairs.begin())
            std::cout << " | ";
        if (it->second == EMPTY_VALUE)
            std::cout << std::setw(2) << 'x';
        else
            std::cout << std::setw(2) << it->second;
    }
    std::cout << std::endl;
}

template <template <class, class> class ContainerType, class NumberType, class Allocator>
typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::iterator PmergeMe<ContainerType, NumberType, Allocator>::findNext(
    ContainerType<std::pair<NumberType, NumberType>, Allocator> &pairs, size_t skip) {
    typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::iterator it = pairs.begin();
    typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::iterator prev_it = it;

    size_t i = 1;
    while (true) {
        it = std::find_if(it, pairs.end(), findNextCompare);
        if (i == 1 && it == pairs.end()) {
            return pairs.end();
        }
        if (it == pairs.end()) {
            it = prev_it;
            break;
        }
        if (i == skip) {
            break;
        }
        prev_it = it;
        ++it;
        ++i;
    }
    return it;
}

template <template <class, class> class ContainerType, class NumberType, class Allocator>
bool PmergeMe<ContainerType, NumberType, Allocator>::compare(const std::pair<NumberType, NumberType> &a, const std::pair<NumberType, NumberType> &b) {
    return a.first < b.first;
}

template <template <class, class> class ContainerType, class NumberType, class Allocator>
bool PmergeMe<ContainerType, NumberType, Allocator>::findNextCompare(const std::pair<NumberType, NumberType> &p) {
    return p.second != EMPTY_VALUE;
}

template <>
void PmergeMe<std::list, int, std::allocator<int> >::sortPairs(std::list<std::pair<int, int>, std::allocator<int> > &pairs) {
    pairs.sort(compare);
}

template <template <class, class> class ContainerType, class NumberType, class Allocator>
void PmergeMe<ContainerType, NumberType, Allocator>::sortPairs(ContainerType<std::pair<NumberType, NumberType>, Allocator> &pairs) {
    std::sort(pairs.begin(), pairs.end(), compare);
}