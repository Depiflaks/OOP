//
// Created by smmm on 26.02.2025.
//
#include "../src/accumulate.h"
#include "./test_accumulate.h"
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>
#include <vector>


TEST(SortNumbersTest, EmptyArray)
{
	std::vector<double> numbers = {};
	SortNumbers(numbers);
	CompareArrays(numbers, {});
}

TEST(SortNumbersTest, IntArray)
{
	std::vector<double> numbers = {3, 2, 1};
	SortNumbers(numbers);
	CompareArrays(numbers, {1, 2, 3});
}

TEST(SortNumbersTest, NegativeArray)
{
	std::vector<double> numbers = {-1, -2, -3};
	SortNumbers(numbers);
	CompareArrays(numbers, {-3, -2, -1});
	numbers = {-1, 2, -3};
	SortNumbers(numbers);
	CompareArrays(numbers, {-3, -1, 2});
}

TEST(ProcessNumbersTest, HandlesPositiveNumbers)
{
	std::vector<double> numbers = { 1.0, 2.0, 3.0 };
	ProcessNumbers(numbers);
	CompareArrays(numbers, { 3.0, 4.0, 5.0 });
}

TEST(ProcessNumbersTest, HandlesNegativeNumbers)
{
	std::vector<double> numbers = { -1.0, -2.0, -3.0 };
	ProcessNumbers(numbers);
	CompareArrays(numbers, { -1.0, -2.0, -3.0 });
}

TEST(ProcessNumbersTest, HandlesMixedNumbers)
{
	std::vector<double> numbers = { -1.0, 2.0, -3.0, 4.0 };
	ProcessNumbers(numbers);
	CompareArrays(numbers, { 2.0, 5.0, 0.0, 7.0 });
}

TEST(ProcessNumbersTest, HandlesEmptyVector)
{
	std::vector<double> numbers;
	ProcessNumbers(numbers);
	CompareArrays(numbers, {});
}

void CompareArrays(const std::vector<double>& result, const std::vector<double>& expected)
{
	ASSERT_EQ(result.size(), expected.size());
	for (size_t i = 0; i < result.size(); ++i)
	{
		EXPECT_NEAR(result[i], expected[i], 1e-3);
	}
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}