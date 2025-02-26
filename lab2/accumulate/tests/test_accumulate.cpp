//
// Created by smmm on 26.02.2025.
//
#include "../src/accumulate.h"
#include "./test_accumulate.h"
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

TEST(GetPositiveSumTest, EmptyArray)
{
	std::vector<double> numbers = {};
	EXPECT_EQ(GetPositiveSum(numbers), 0);
}

TEST(GetPositiveSumTest, IntArray)
{
	std::vector<double> numbers = {1, 2, 3};
	EXPECT_EQ(GetPositiveSum(numbers), 6);
}

TEST(GetPositiveSumTest, NegativeArray)
{
	std::vector<double> numbers = {-1, -2, -3};
	EXPECT_EQ(GetPositiveSum(numbers), 0);
	numbers = {-1, 2, -3};
	EXPECT_EQ(GetPositiveSum(numbers), 2);
}

TEST(GetPositiveCountTest, EmptyArray)
{
	std::vector<double> numbers = {};
	EXPECT_EQ(GetPositiveCount(numbers), 0);
}

TEST(GetPositiveCountTest, IntArray)
{
	std::vector<double> numbers = {1, 2, 3};
	EXPECT_EQ(GetPositiveCount(numbers), 3);
}

TEST(GetPositiveCountTest, NegativeArray)
{
	std::vector<double> numbers = {-1, -2, -3};
	EXPECT_EQ(GetPositiveCount(numbers), 0);
	numbers = {-1, 2, -3};
	EXPECT_EQ(GetPositiveCount(numbers), 1);
}

TEST(ReadNumbersTest, HandlesValidInput)
{
	std::vector<double> numbers;
	std::istringstream input("1.0 2.0 3.0");
	std::cin.rdbuf(input.rdbuf());
	EXPECT_TRUE(ReadNumbers(numbers));
	CompareArrays(numbers, { 1.0, 2.0, 3.0 });
}


TEST(ReadNumbersTest, HandlesInvalidInput)
{
	std::vector<double> numbers;
	std::istringstream input("1.0 abc 3.0");
	std::cin.rdbuf(input.rdbuf());
	EXPECT_FALSE(ReadNumbers(numbers));
}

TEST(ReadNumbersTest, HandlesEmptyInput)
{
	std::vector<double> numbers;
	std::istringstream input("");
	std::cin.rdbuf(input.rdbuf());
	EXPECT_TRUE(ReadNumbers(numbers));
	CompareArrays(numbers, {});
}

TEST(ReadNumbersTest, HandlesIntInput)
{
	std::vector<double> numbers;
	std::istringstream input("1 2 3");
	std::cin.rdbuf(input.rdbuf());
	EXPECT_TRUE(ReadNumbers(numbers));
	CompareArrays(numbers, {1, 2, 3});
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

TEST(ShiftByPositiveMeanTest, HandlesInvalidInput)
{
	TestShiftByPositiveMean("files/1/i.txt", "files/1/o.txt");
	TestShiftByPositiveMean("files/5/i.txt", "files/5/o.txt");
}

TEST(ShiftByPositiveMeanTest, HandlesValidInput)
{
	TestShiftByPositiveMean("files/2/i.txt", "files/2/o.txt");
	TestShiftByPositiveMean("files/3/i.txt", "files/3/o.txt");
	TestShiftByPositiveMean("files/4/i.txt", "files/4/o.txt");
}

auto CompareArrays(const std::vector<double>& result, const std::vector<double>& expected) -> void
{
	ASSERT_EQ(result.size(), expected.size());
	for (size_t i = 0; i < result.size(); ++i)
	{
		EXPECT_NEAR(result[i], expected[i], 1e-3);
	}
}

auto TestShiftByPositiveMean(const std::string& inputFile, const std::string& expectedOutputFile) -> void
{
	std::ifstream input(inputFile);
	std::ifstream expectedOutput(expectedOutputFile);
	std::stringstream output;

	std::cin.rdbuf(input.rdbuf());
	std::cout.rdbuf(output.rdbuf());

	ShiftByPositiveMean();

	std::string expectedLine, outputLine;
	while (std::getline(expectedOutput, expectedLine) && std::getline(output, outputLine))
	{
		EXPECT_EQ(outputLine, expectedLine);
	}
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}