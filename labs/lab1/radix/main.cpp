//
// Created by smmm on 29.05.2025.
//
#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

void PrintHelp(const char* command);
RadixConversionData ParseArguments(int argc, char** argv);

int StringToInt(const std::string& str, int radix)
{
	size_t startChar = 0;
	bool isNegative = false;

	if (str[0] == '-')
	{
		isNegative = true;
		startChar = 1;
	}
	else if (str[0] == '+')
	{
		startChar = 1;
	}

	long long result = 0;

	for (size_t i = startChar; i < str.size(); ++i)
	{
		char c = str[i];
		int digit;

		if (c >= '0' && c <= '9')
			digit = c - '0';
		else if (c >= 'A' && c <= 'Z')
			digit = c - 'A' + 10;
		else if (c >= 'a' && c <= 'z')
			digit = c - 'a' + 10;
		else
			throw std::invalid_argument("Invalid character");

		if (digit >= radix)
			throw std::invalid_argument("Digit exceeds radix");

		if (result > (LLONG_MAX - digit) / radix)
			throw std::overflow_error("Overflow");

		result = result * radix + digit;
	}

	if (isNegative)
		result = -result;

	if (result > INT_MAX || result < INT_MIN)
		throw std::overflow_error("Overflow");

	return static_cast<int>(result);
}

std::string IntToString(int n, int radix)
{
	if (radix < 2 || radix > 36)
		throw std::invalid_argument("Invalid radix");

	if (n == 0)
		return "0";

	bool negative = n < 0;
	unsigned int abs_n;

	if (n == INT_MIN)
		abs_n = static_cast<unsigned int>(INT_MAX) + 1;
	else
		abs_n = negative ? static_cast<unsigned int>(-n) : static_cast<unsigned int>(n);

	std::string result;
	while (abs_n > 0)
	{
		unsigned int digit = abs_n % radix;
		abs_n /= radix;

		char c;
		if (digit < 10)
			c = '0' + digit;
		else
			c = 'A' + digit - 10;

		result.push_back(c);
	}

	if (negative)
		result.push_back('-');

	std::ranges::reverse(result);
	return result;
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		PrintHelp(argv[0]);
		return 1;
	}

	try
	{
		auto conversionData = ParseArguments(argv);
		int number = StringToInt(value, sourceRadix);
		std::string result = IntToString(number, destRadix);
		std::cout << result << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
		return 1;
	}
	catch (const std::overflow_error& e)
	{
		std::cerr << "Overflow: " << e.what() << std::endl;
		return 1;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}

void PrintHelp(const char* command)
{
	std::cerr << "Usage: " << command << " <source notation> <destination notation> <value>\n";
}

RadixConversionData ParseArguments(char** argv)
{
	int sourceRadix = std::stoi(argv[1]);
	int destRadix = std::stoi(argv[2]);
	std::string value = argv[3];
	return RadixConversionData{ sourceRadix, destRadix, value };
}
