//
// Created by smmm on 27.02.2025.
//
#include "accumulate.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <sstream>
#include <vector>

bool ReadNumbers(std::vector<double>& numbers);
double GetPositiveSum(std::vector<double>& numbers);
int GetPositiveCount(std::vector<double>& numbers);

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

	std::transform(numbers.begin(), numbers.end(), numbers.begin(),
		[average](double num) { return num + average; });
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
	double sum = std::accumulate(
		numbers.begin(),
		numbers.end(),
		0.0,
		[](double acc, double curr) {
			return curr > 0 ? acc + curr : acc;
		});
	return sum;
}

void SortNumbers(std::vector<double>& numbers)
{
	std::sort(numbers.begin(), numbers.end());
}

void PrintNumbers(const std::vector<double>& numbers)
{
	std::cout << std::fixed << std::setprecision(3);
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << numbers[i];
	}
	std::cout << "\n";
}
