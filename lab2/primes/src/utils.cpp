//
// Created by smmm on 27.02.2025.
//
#include "generator.h"
#include <iostream>
#include <cstdlib>

auto ParseArguments(int argc, char* argv[]) -> int
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <upperBound>" << std::endl;
		std::exit(1);
	}

	int upperBound = std::atoi(argv[1]);
	if (upperBound < 0 || upperBound > 100000000)
	{
		std::cerr << "Upper bound must be between 0 and 100000000" << std::endl;
		std::exit(1);
	}

	return upperBound;
}

auto PrintPrimes(const std::set<int>& primes) -> void
{
	for (int prime : primes)
	{
		std::cout << prime << " ";
	}
	std::cout << std::endl;
}