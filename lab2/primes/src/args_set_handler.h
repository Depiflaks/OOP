//
// Created by smmm on 27.02.2025.
//

#ifndef OOP_ARGS_SET_HANDLER_H
#define OOP_ARGS_SET_HANDLER_H

#include <set>
#include <string>
#include <vector>

// todo: переименовать файл
auto ParseArguments(int argc, char* argv[]) -> int;
auto PrintPrimes(const std::set<int>& primes) -> void;

#endif // OOP_ARGS_SET_HANDLER_H
