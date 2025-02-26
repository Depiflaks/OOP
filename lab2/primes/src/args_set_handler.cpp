//
// Created by smmm on 27.02.2025.
//
#include "args_set_handler.h"
#include <cstdlib>
#include <iostream>

const int minUpperBound = 0;
const int maxUpperBound = 100'000'000;

int ToDigit(char* digit);
void Exit(const char* message);

int ParseArguments(int argc, char* argv[])
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

int ToDigit(char* digit)
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

void PrintPrimes(const std::set<int>& primes, std::ostream& outStream)
{
	for (int prime : primes)
	{
		outStream << prime << " ";
	}
	outStream << "\n";
}
