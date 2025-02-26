//
// Created by smmm on 26.02.2025.
//

#ifndef OOP_ACCUMULATE_H
#define OOP_ACCUMULATE_H

#include <vector>

void ShiftByPositiveMean();
bool ReadNumbers(std::vector<double>& numbers);
void ProcessNumbers(std::vector<double>& numbers);
void PrintSortedNumbers(const std::vector<double>& numbers);
double GetPositiveSum(std::vector<double>& numbers);
int GetPositiveCount(std::vector<double>& numbers);

#endif
