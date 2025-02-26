//
// Created by smmm on 27.02.2025.
//
#include "generator.h"
#include <cstdlib>
#include <iostream>

auto ParseArguments(int argc, char* argv[]) -> int
{
	if (argc != 2)
	{
		Exit("Usage: program <upperBound>");
	}

	int upperBound = ToDigit(argv[1]);
	if (upperBound < 0 || upperBound > 100000000)
	{
		Exit("Upper bound must be between 0 and 100000000");
	}

	return upperBound;
}

auto ToDigit(char* digit) -> int
{
	try
	{
		std::size_t pos;
		int value = std::stoi(digit, &pos);
		return value;
	}
	catch (const std::invalid_argument&)
	{
		Exit("Argument must be of type int");
	}
	catch (const std::out_of_range&)
	{
		Exit("Argument must be less than MAX_INT");
	}
	return 0;
}

auto Exit(const char* message) -> void
{
	std::cerr << message << "\n";
	std::exit(1);
}

auto PrintPrimes(const std::set<int>& primes) -> void
{
	for (int prime : primes)
	{
		std::cout << prime << " ";
	}
	std::cout << "\n";
}

auto PrintPrimesCount(const std::set<int>& primes) -> void
{
	std::cout << "Total primes: " << primes.size() << "\n";
}
