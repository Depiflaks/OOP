//
// Created by smmm on 26.02.2025.
//
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include "accumulate.h"

auto main() -> int
{
	std::vector<double> numbers;

	if (!ReadNumbers(numbers))
	{
		std::cout << "ERROR" << std::endl;
		return 0;
	}

	ProcessNumbers(numbers);
	PrintSortedNumbers(numbers);

	return 0;
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

	double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0,
		[](double acc, double val) { return val > 0 ? acc + val : acc; });
	int count = std::count_if(numbers.begin(), numbers.end(), [](double val) { return val > 0; });

	if (count == 0)
		return;

	double average = sum / count;

	for (double& num : numbers)
	{
		num += average;
	}
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