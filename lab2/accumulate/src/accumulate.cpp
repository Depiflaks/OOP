//
// Created by smmm on 27.02.2025.
//
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <limits>
#include <vector>
#include "accumulate.h"

// todo: обратно в main.cpp
// убрать проверку из юнит тестов
void ShiftByPositiveMean()
{
	std::vector<double> numbers;

	if (!ReadNumbers(numbers))
	{
		std::cout << "ERROR" << std::endl;
		return;
	}

	ProcessNumbers(numbers);
	PrintSortedNumbers(numbers);
}

bool ReadNumbers(std::vector<double>& numbers)
{
	std::string line;
	std::getline(std::cin, line);
	std::istringstream stream(line);
	double number;
	while (stream >> number)
	{
		numbers.push_back(number);
	}
	if (!stream.eof() && stream.fail())
	{
		return false;
	}
	return true;
}

void ProcessNumbers(std::vector<double>& numbers)
{
	if (numbers.empty())
		return;

	double sum = GetPositiveSum(numbers);
	int count = GetPositiveCount(numbers);

	if (count == 0)
		return;

	double average = sum / count;

	// todo: std::transform
	for (double& num : numbers)
		num += average;
}

int GetPositiveCount(std::vector<double>& numbers)
{
	return std::count_if(
		numbers.begin(),
		numbers.end(),
		[](double val) { return val > 0; });
}

double GetPositiveSum(std::vector<double>& numbers)
{

	double sum = 0.0;
	// todo: обратно
//	sum = std::accumulate(numbers.begin(), numbers.end(), [](double acc, double curr) {
//		return curr > 0 ? acc + curr : acc;
//	})
	for (double val : numbers) {
		if (val > 0) {
			if (sum > std::numeric_limits<double>::max() - val) {
				std::cerr << "Overflow detected!" << std::endl;
				std::exit(1);
			}
			sum += val;
		}
	}
	return sum;
}

void PrintSortedNumbers(const std::vector<double>& numbers)
{
	std::vector<double> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	// todo: вынести в отдельную функцию

	std::cout << std::fixed << std::setprecision(3);
	for (size_t i = 0; i < sortedNumbers.size(); ++i)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << sortedNumbers[i];
	}
	std::cout << "\n";
}
