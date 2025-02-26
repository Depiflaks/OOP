//
// Created by smmm on 27.02.2025.
//
#include "./src/args_set_handler.h"
#include "./src/generator.h"

int main(int argc, char* argv[]) {
	int upperBound = ParseArguments(argc, argv);
	auto primes = GeneratePrimeNumbersSet(upperBound);
	PrintPrimes(primes);
	return 0;
}