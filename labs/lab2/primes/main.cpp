//
// Created by smmm on 27.02.2025.
//
#include "./src/args_set_handler.h"
#include "./src/generator.h"
#include <iostream>

int main(int argc, char* argv[]) {
	int upperBound = ParseArguments(argc, argv);
	auto primes = GeneratePrimeNumbersSet(upperBound);
	PrintPrimes(primes, std::cout);
	return 0;
}