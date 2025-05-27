//
// Created by smmm on 27.05.2025.
//

#ifndef FIND_MAX_H
#define FIND_MAX_H

#include <optional>
#include <vector>

template <typename T, typename Less>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
		return false;

	const T* maxElem = &arr[0];

	for (size_t i = 1; i < arr.size(); ++i)
		if (less(*maxElem, arr[i]))
			maxElem = &arr[i];

	maxValue = *maxElem;
	return true;
}
#endif // FIND_MAX_H
