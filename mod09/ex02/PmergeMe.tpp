
#include "PmergeMe.hpp"

template <template <class> class ContainerType, class NumberType>
static void PmergeMe<ContainerType, NumberType>::mergeSort(ContainerType<NumberType> &li) {
    bool uneven = li.size() % 2;
    NumberType uneven_value = 0;
    if (uneven) {
        uneven_value = li.back();
        li.pop_back();
    }

    ContainerType<std::pair<NumberType, NumberType> > pairs = createPairs(li);

    sortEachPair(pairs);

    pairs.sort(compare);

    ContainerType<NumberType> result;
    ContainerType<NumberType> pending;

    for (typename ContainerType<std::pair<NumberType, NumberType> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        pending.push_back(it->first);
        result.push_back(it->second);
    }

    result.push_front(pending.front());
    pending.pop_front();

    typename ContainerType<NumberType>::iterator search_max = result.begin();
    std::advance(search_max, 2);

    for (typename ContainerType<NumberType>::iterator it = pending.begin(); it != pending.end();) {
        for (size_t i = 0; i < jacobsthal(std::distance(pending.begin(), it) + 2) && it != pending.end(); ++i, ++it) {
            typename ContainerType<NumberType>::iterator location = std::lower_bound(result.begin(), search_max, *it);
            result.insert(location, *it);
            search_max++;
        }
    }

    if (uneven) {
        typename ContainerType<NumberType>::iterator location = std::lower_bound(result.begin(), result.end(), uneven_value);
        result.insert(location, uneven_value);
    }
    li = result;
}

// bool compare(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
//     return p1.second < p2.second;
// }

// std::list<std::pair<int, int> > createPairs(std::list<int>& li) {
//     size_t place = 0;
//     std::list<std::pair<int, int> > pairs;
//     for (std::list<int>::iterator it = li.begin(); it != li.end(); ++it, ++place) {
//         if (place % 2 == 0) {
//             pairs.push_back(std::make_pair(*it, -1));
//         } else {
//             pairs.back().second = *it;
//         }
//     }
//     return pairs;
// }

// void sortEachPair(std::list<std::pair<int, int> >& pairs) {
//     for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
//         if (it->first > it->second)
//             std::swap(it->first, it->second);
//     }
// }

// size_t jacobsthal(size_t n) {
//     if (n == 0)
//         return 1;
//     if (n == 1)
//         return 0;
//     return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
// }

// void printPairs(const std::list<std::pair<int, int> >& pairs) {
//     for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
//         std::cout << '[' << it->first << ", " << it->second << "] ";
//     }
//     std::cout << std::endl;
// }

// void mergeSort(std::list<int>& li) {
//     std::list<std::pair<int, int> > pairs;

//     bool uneven = li.size() % 2;
//     int uneven_value = 0;
//     if (uneven) {
//         uneven_value = li.back();
//         li.pop_back();
//         std::cout << "uneven value: " << uneven_value << std::endl;
//     }

//     pairs = createPairs(li);
//     // std::cout << "pairs: ";
//     // printPairs(pairs);

//     // sort each individual pair so that the first element is smaller than the second element, [5, 3] -> [3, 5]
//     sortEachPair(pairs);

//     // std::cout << "individual pairs sorted: ";
//     // printPairs(pairs);

//     // sort pairs by their second element (largest element)
//     pairs.sort(compare);

//     // std::cout << "pairs sorted by second element: ";
//     // printPairs(pairs);

//     std::list<int> result;
//     std::list<int> pending;

//     for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
//         pending.push_back(it->first);
//         result.push_back(it->second);
//     }

//     result.push_front(pending.front());  // add the first element from pending to the front of the result, because it is the smallest element
//     pending.pop_front();

//     std::list<int>::iterator search_max = result.begin();
//     std::advance(search_max, 2);  // search_max points to the third element in the list (because the first two elements are already added)

//     for (std::list<int>::iterator it = pending.begin(); it != pending.end();) {
//         for (size_t i = 0; i < jacobsthal(std::distance(pending.begin(), it) + 2) && it != pending.end(); ++i, ++it) {
//             std::list<int>::iterator location = std::lower_bound(result.begin(), search_max, *it);
//             result.insert(location, *it);
//             search_max++;
//         }
//     }

//     if (uneven) {
//         std::list<int>::iterator location = std::lower_bound(result.begin(), result.end(), uneven_value);
//         result.insert(location, uneven_value);
//     }
//     li = result;
// }
