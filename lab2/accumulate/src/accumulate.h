//
// Created by smmm on 26.02.2025.
//

#ifndef OOP_ACCUMULATE_H
#define OOP_ACCUMULATE_H

#include <vector>

auto ShiftByPositiveMean() -> void;
auto ReadNumbers(std::vector<double>& numbers) -> bool;
auto ProcessNumbers(std::vector<double>& numbers) -> void;
auto PrintSortedNumbers(const std::vector<double>& numbers) -> void;
auto GetPositiveSum(std::vector<double>& numbers) -> double;
auto GetPositiveCount(std::vector<double>& numbers) -> int;

#endif
