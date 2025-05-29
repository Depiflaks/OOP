//
// Created by smmm on 29.05.2025.
//
#include <algorithm>
#include <climits>
#include <data/RadixConversionData.h>
#include <iostream>
#include <stdexcept>
#include <string>

void PrintHelp(const char* command);
RadixConversionData ParseArguments(char** argv);
int CharToDecimal(char currentChar);
void CheckCharInRadixRange(int radix, int digit, char ch);
void CheckOverflowDoesntReached(int radix, long long result, int digit);
void CheckValueInIntRange(long long result);
bool IsOriginalValueNegative(const std::string& value);
void CheckRadixRange(int radix);
void CheckNotEmpty(const std::string& value);
void CheckHaveDigitAfterSign(const std::string& value);
constexpr char DigitToChar(unsigned int digit);
unsigned int AbsValue(int number, bool negative);

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
		int number = StringToInt(conversionData.m_originalValue, conversionData.m_sourceRadix);
		std::string result = IntToString(number, conversionData.m_destRadix);
		std::cout << result << '\n';
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
	return RadixConversionData{
		std::stoi(argv[1]),
		std::stoi(argv[2]),
		argv[3]
	};
}

int StringToInt(const std::string& value, int radix)
{
	CheckRadixRange(radix);
	CheckNotEmpty(value);
	CheckHaveDigitAfterSign(value);

	bool isNegative = IsOriginalValueNegative(value);
	int startChar = value[0] == '+' || value[0] == '-';
	long long result = 0;

	for (size_t i = startChar; i < value.size(); ++i)
	{
		char currentChar = value[i];
		int digit = CharToDecimal(currentChar);

		CheckCharInRadixRange(radix, digit, currentChar);
		CheckOverflowDoesntReached(radix, result, digit);

		result = result * radix + digit;
	}
	if (isNegative)
		result = -result;

	CheckValueInIntRange(result);
	return static_cast<int>(result);
}

bool IsOriginalValueNegative(const std::string& value)
{
	return value[0] == '-';
}

void CheckRadixRange(int radix)
{
	if (radix < 2 || radix > 36)
		throw std::invalid_argument("Invalid radix");
}

void CheckNotEmpty(const std::string& value)
{
	if (value.empty())
		throw std::invalid_argument("Empty string");
}

void CheckHaveDigitAfterSign(const std::string& value)
{
	if ((value[0] == '-' || value[0] == '+') && value.size() == 1)
		throw std::invalid_argument("Missing digits after sign");
}

int CharToDecimal(char currentChar)
{
	if (currentChar >= '0' && currentChar <= '9')
		return currentChar - '0';
	if (currentChar >= 'A' && currentChar <= 'Z')
		return currentChar - 'A' + 10;
	if (currentChar >= 'a' && currentChar <= 'z')
		return currentChar - 'a' + 10;
	throw std::invalid_argument("Invalid character: " + currentChar);
}

void CheckCharInRadixRange(int radix, int digit, char ch)
{
	if (digit >= radix)
		throw std::invalid_argument("Digit exceeds radix: " + ch);
}

void CheckOverflowDoesntReached(int radix, long long result, int digit)
{
	if (result > (LLONG_MAX - digit) / radix)
		throw std::overflow_error("Overflow");
}

void CheckValueInIntRange(long long result)
{
	if (result > INT_MAX || result < INT_MIN)
		throw std::overflow_error("Overflow");
}

constexpr char DigitToChar(unsigned int digit)
{
	return (digit < 10)
		? static_cast<char>('0' + digit)
		: static_cast<char>('A' + (digit - 10));
}

unsigned int AbsValue(int number, bool negative)
{
	if (number == INT_MIN)
		return static_cast<unsigned int>(INT_MAX) + 1;
	return negative ? static_cast<unsigned int>(-number) : static_cast<unsigned int>(number);
}

std::string IntToString(int number, int radix)
{
	CheckRadixRange(radix);
	if (number == 0)
		return "0";

	bool negative = number < 0;
	unsigned int absNumber = AbsValue(number, negative);

	std::string result;
	while (absNumber > 0)
	{
		unsigned int digit = absNumber % radix;
		absNumber /= radix;
		char ch = DigitToChar(digit);
		result.push_back(ch);
	}

	if (negative)
		result.push_back('-');

	std::ranges::reverse(result);
	return result;
}
