//
// Created by smmm on 29.04.2025.
//
#include "random.h"

inline int GetRandomNumber(const int min, const int max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

