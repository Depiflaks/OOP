//
// Created by smmm on 13.05.2025.
//

#include <ranges>

#include "myArray/MyArray.h"

int main()
{
	CMyArray<std::string> strings;
	strings.PushBack("Hello");
	strings.PushBack("World");
	std::cout << "Strings:";
	for (const auto& s : strings)
		std::cout << " " << s;
	std::cout << std::endl;

	CMyArray<double> numbers;
	numbers.PushBack(3.14);
	numbers.PushBack(2.71);
	numbers.Resize(5);
	std::cout << "Numbers:";
	for (const double& number : std::ranges::reverse_view(numbers))
		std::cout << " " << number;
	std::cout << std::endl;

	return 0;
}
