//
// Created by smmm on 27.02.2025.
//

#ifndef OOP_GENERATOR_H
#define OOP_GENERATOR_H
#include <set>
#include <string>
#include <vector>

auto GeneratePrimeNumbersSet(int upperBound) -> std::set<int>;

auto ParseArguments(int argc, char* argv[]) -> int;

auto PrintPrimes(const std::set<int>& primes) -> void;

auto PrintPrimesCount(const std::set<int>& primes) -> void;

auto ToDigit(char* digit) -> int;

auto Exit(const char* message) -> void;

#endif
