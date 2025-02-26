//
// Created by smmm on 26.02.2025.
//
#include "src/accumulate.h"
#include <iostream>

int main()
{	std::vector<double> numbers;

	if (!ReadNumbers(numbers))
	{
		std::cout << "ERROR" << std::endl;
		return 0;
	}

	ProcessNumbers(numbers);
	SortNumbers(numbers);
	PrintNumbers(numbers);
	return 0;
}