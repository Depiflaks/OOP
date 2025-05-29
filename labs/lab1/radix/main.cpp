//
// Created by smmm on 29.05.2025.
//
#include <data/RadixConversionData.h>
#include <iostream>
#include <radix/radixConverter.h>
#include <stdexcept>
#include <string>

void PrintHelp(const char* command);
RadixConversionData ParseArguments(char** argv);

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

