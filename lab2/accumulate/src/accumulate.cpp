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

auto ShiftByPositiveMean() -> void
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

auto ReadNumbers(std::vector<double>& numbers) -> bool
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

auto ProcessNumbers(std::vector<double>& numbers) -> void
{
	if (numbers.empty())
		return;

	double sum = GetPositiveSum(numbers);
	int count = GetPositiveCount(numbers);

	if (count == 0)
		return;

	double average = sum / count;

	for (double& num : numbers)
	{
		num += average;
	}
}

auto GetPositiveCount(std::vector<double>& numbers) -> int
{
	return std::count_if(
		numbers.begin(),
		numbers.end(),
		[](double val) { return val > 0; });
}

auto GetPositiveSum(std::vector<double>& numbers) -> double
{
	double sum = 0.0;
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

auto PrintSortedNumbers(const std::vector<double>& numbers) -> void
{
	std::vector<double> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	std::cout << std::fixed << std::setprecision(3);
	for (size_t i = 0; i < sortedNumbers.size(); ++i)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << sortedNumbers[i];
	}
	std::cout << std::endl;
}
