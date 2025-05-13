//
// Created by smmm on 27.02.2025.
//

#ifndef OOP_ARGS_SET_HANDLER_H
#define OOP_ARGS_SET_HANDLER_H

#include <set>
#include <string>
#include <vector>

int ParseArguments(int argc, char* argv[]);
void PrintPrimes(const std::set<int>& primes, std::ostream& outStream);

#endif // OOP_ARGS_SET_HANDLER_H
