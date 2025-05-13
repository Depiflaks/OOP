//
// Created by smmm on 26.02.2025.
//
#include "../src/args_set_handler.h"
#include "../src/generator.h"
#include <gtest/gtest.h>
#include <sstream>

std::string CaptureOutput(std::function<void(std::ostream& outStream)> func)
{
	std::stringstream buffer;
	func(buffer);
	return buffer.str();
}

TEST(GeneratePrimeNumbersSetTest, HandlesZero)
{
	auto primes = GeneratePrimeNumbersSet(0);
	EXPECT_TRUE(primes.empty());
}

TEST(GeneratePrimeNumbersSetTest, HandlesOne)
{
	auto primes = GeneratePrimeNumbersSet(1);
	EXPECT_TRUE(primes.empty());
}

TEST(GeneratePrimeNumbersSetTest, HandlesSmallUpperBound)
{
	auto primes = GeneratePrimeNumbersSet(10);
	std::set<int> expected = { 2, 3, 5, 7 };
	EXPECT_EQ(primes, expected);
}

TEST(GeneratePrimeNumbersSetTest, HandlesLargeUpperBound)
{
	auto primes = GeneratePrimeNumbersSet(100);
	EXPECT_EQ(primes.size(), 25);
}

TEST(GeneratePrimeNumbersSetTest, HandlesMaxUpperBound)
{
	auto primes = GeneratePrimeNumbersSet(100000000);
	EXPECT_EQ(primes.size(), 5761455);
}

TEST(ParseArgumentsTest, HandlesValidInput)
{
	const char* argv[] = { "program", "100" };
	int argc = 2;
	EXPECT_EQ(ParseArguments(argc, const_cast<char**>(argv)), 100);
}

TEST(ParseArgumentsTest, HandlesInvalidInput)
{
	const char* argv[] = { "program", "invalid" };
	int argc = 2;
	EXPECT_THROW(ParseArguments(argc, const_cast<char**>(argv)), std::invalid_argument);
}

TEST(ParseArgumentsTest, HandlesOutOfRangeInput)
{
	const char* argv[] = { "program", "100000001" };
	int argc = 2;
	EXPECT_THROW(ParseArguments(argc, const_cast<char**>(argv)), std::invalid_argument);
}

TEST(PrintPrimesTest, HandlesEmptySet)
{
	std::set<int> primes;
	auto output = CaptureOutput(
		[&](std::ostream& outStream) { PrintPrimes(primes, outStream); });
	EXPECT_EQ(output, "\n");
}

TEST(PrintPrimesTest, HandlesNonEmptySet)
{
	std::set<int> primes = { 2, 3, 5 };
	auto output = CaptureOutput(
		[&](std::ostream& outStream) { PrintPrimes(primes, outStream); });
	EXPECT_EQ(output, "2 3 5 \n");
}