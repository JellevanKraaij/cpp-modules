#pragma once
#include <algorithm>
#include <iterator>

template <typename T>
void mergeSort(T &numbers) {
	if (numbers.size() > 2)
	{
		typename T::iterator it = numbers.begin();
		std::advance(it, numbers.size() / 2);
		T left(numbers.begin(), it);
		T right(it, numbers.end());
		mergeSort(left);
		mergeSort(right);
		numbers.clear();
		std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(numbers));
	}
	else if (numbers.size() == 2 && numbers.front() > numbers.back()) {
		std::swap(numbers.front(), numbers.back());
	}
}
