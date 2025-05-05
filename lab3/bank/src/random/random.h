//
// Created by smmm on 29.04.2025.
//

#ifndef RANDOM_H
#define RANDOM_H

#include <random>

int GetRandomNumber(int min, int max);

template <typename T>
T& ChooseRandom(const std::vector<T>& values)
{
	const auto randomIndex = GetRandomNumber(0, static_cast<int>(values.size()) - 1);
	return values[randomIndex];
}

#endif // RANDOM_H
