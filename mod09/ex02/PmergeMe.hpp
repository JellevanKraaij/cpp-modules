#pragma once

#ifndef DEBUG
#define DEBUG 0
#endif

template <template <class, class> class ContainerType, class NumberType, class Allocator = std::allocator<NumberType> >
class PmergeMe {
   public:
    static void mergeSort(ContainerType<NumberType, Allocator>& li);

   private:
    static ContainerType<std::pair<NumberType, NumberType>, Allocator> createPairs(const ContainerType<NumberType, Allocator>& li);
    static void sortIndividualPairs(ContainerType<std::pair<NumberType, NumberType>, Allocator>& pairs);
    static size_t jacobsthal(size_t n);
    static void printPairs(const ContainerType<std::pair<NumberType, NumberType>, Allocator>& pairs);
    static typename ContainerType<std::pair<NumberType, NumberType>, Allocator>::iterator findNext(
        ContainerType<std::pair<NumberType, NumberType>, Allocator>& pairs, size_t skip);
    static bool compare(const std::pair<NumberType, NumberType>& p1, const std::pair<NumberType, NumberType>& p2);
    static bool findNextCompare(const std::pair<NumberType, NumberType>& p);
    static const NumberType EMPTY_VALUE = -1;
    static void sortPairs(ContainerType<std::pair<NumberType, NumberType>, Allocator>& pairs);
};

#include "PmergeMe.tpp"
