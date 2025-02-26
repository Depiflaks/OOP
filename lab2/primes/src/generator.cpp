//
// Created by smmm on 27.02.2025.
//
#include "generator.h"
#include <algorithm>
#include <cmath>
#include <vector>

void FillPrimeNumberSet(std::set<int>& primes, const int upperBound, std::vector<bool>& isPrime);
void EratosthenesSieve(const int upperBound, std::vector<bool>& isPrime);

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::set<int> primes;
	if (upperBound < 2)
		return primes;

	std::vector<bool> isPrime(upperBound + 1, true);
	isPrime[0] = isPrime[1] = false;
	EratosthenesSieve(upperBound, isPrime);

	FillPrimeNumberSet(primes, upperBound, isPrime);

	return primes;
}

void EratosthenesSieve(const int upperBound, std::vector<bool>& isPrime)
{
	// todo: можно ускорить в 2 раза
	for (int candidate = 2; candidate <= std::sqrt(upperBound); ++candidate)
	{
		if (isPrime[candidate])
		{
			for (int multiple = candidate * candidate; multiple <= upperBound; multiple += candidate)
			{
				isPrime[multiple] = false;
			}
		}
	}
}

void FillPrimeNumberSet(std::set<int>& primes, const int upperBound, std::vector<bool>& isPrime)
{
	for (int i = 2; i <= upperBound; ++i)
	{
		if (isPrime[i])
			primes.insert(i);
	}
}