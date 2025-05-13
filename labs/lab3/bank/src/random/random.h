//
// Created by smmm on 29.04.2025.
//

#ifndef RANDOM_H
#define RANDOM_H

#include <random>

inline int GetRandomNumber(const int min, const int max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

template <typename T>
const T& ChooseRandom(const std::vector<T>& values)
{
	const auto randomIndex = GetRandomNumber(0, static_cast<int>(values.size()) - 1);
	return values[randomIndex];
}

#endif // RANDOM_H
