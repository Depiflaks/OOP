//
// Created by smmm on 26.02.2025.
//
#include "../src/generator.h"
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

auto CaptureOutput(std::function<void()> func) -> std::string
{
	std::stringstream buffer;
	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	func();
	std::cout.rdbuf(old);
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
	EXPECT_EXIT(ParseArguments(argc, const_cast<char**>(argv)), ::testing::ExitedWithCode(1), "");
}

TEST(ParseArgumentsTest, HandlesOutOfRangeInput)
{
	const char* argv[] = { "program", "100000001" };
	int argc = 2;
	EXPECT_EXIT(ParseArguments(argc, const_cast<char**>(argv)), ::testing::ExitedWithCode(1), "");
}

TEST(PrintPrimesTest, HandlesEmptySet)
{
	std::set<int> primes;
	auto output = CaptureOutput([&]() { PrintPrimes(primes); });
	EXPECT_EQ(output, "\n");
}

TEST(PrintPrimesTest, HandlesNonEmptySet)
{
	std::set<int> primes = { 2, 3, 5 };
	auto output = CaptureOutput([&]() { PrintPrimes(primes); });
	EXPECT_EQ(output, "2 3 5 \n");
}

TEST(PrintPrimesCountTest, HandlesEmptySet)
{
	std::set<int> primes;
	auto output = CaptureOutput([&]() { PrintPrimesCount(primes); });
	EXPECT_EQ(output, "Total primes: 0\n");
}

TEST(PrintPrimesCountTest, HandlesNonEmptySet)
{
	std::set<int> primes = { 2, 3, 5 };
	auto output = CaptureOutput([&]() { PrintPrimesCount(primes); });
	EXPECT_EQ(output, "Total primes: 3\n");
}

TEST(PrintPrimesCountTest, HandlesMaxCount)
{
	std::set<int> primes = GeneratePrimeNumbersSet(100000000);
	auto output = CaptureOutput([&]() { PrintPrimesCount(primes); });
	EXPECT_EQ(output, "Total primes: 5761455\n");
}