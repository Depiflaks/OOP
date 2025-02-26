//
// Created by smmm on 27.02.2025.
//
#include "args_set_handler.h"
#include <cstdlib>
#include <iostream>

const int minUpperBound = 0;
const int maxUpperBound = 0;

auto ToDigit(char* digit) -> int;
auto Exit(const char* message) -> void;

auto ParseArguments(int argc, char* argv[]) -> int
{
	if (argc != 2)
	{
		throw std::invalid_argument("Usage: program <upperBound>");
	}

	int upperBound = ToDigit(argv[1]);
	if (upperBound < minUpperBound || upperBound > maxUpperBound)
	{
		throw std::invalid_argument("Upper bound must be between 0 and 100000000");
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
		throw std::invalid_argument("Argument must be of type int");
	}
	catch (const std::out_of_range&)
	{
		throw std::invalid_argument("Argument must be less than MAX_INT");
	}
}

// todo: добавить в параметр ссылку на поток
auto PrintPrimes(const std::set<int>& primes) -> void
{
	for (int prime : primes)
	{
		std::cout << prime << " ";
	}
	std::cout << "\n";
}
