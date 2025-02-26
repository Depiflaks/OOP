//
// Created by smmm on 26.02.2025.
//
#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../accumulate.h"

void CompareArrays(const std::vector<double>& result, const std::vector<double>& expected) {
	ASSERT_EQ(result.size(), expected.size());
	for (size_t i = 0; i < result.size(); ++i) {
		EXPECT_NEAR(result[i], expected[i], 1e-3);
	}
}

TEST(ProcessNumbersTest, HandlesPositiveNumbers) {
	std::vector<double> numbers = {1.0, 2.0, 3.0};
	ProcessNumbers(numbers);
	CompareArrays(numbers, {3.0, 4.0, 5.0});
}

TEST(ProcessNumbersTest, HandlesMixedNumbers) {
	std::vector<double> numbers = {-1.0, 2.0, -3.0, 4.0};
	ProcessNumbers(numbers);
	CompareArrays(numbers, {1.0, 4.0, 1.0, 6.0});
}

TEST(ProcessNumbersTest, HandlesEmptyVector) {
	std::vector<double> numbers;
	ProcessNumbers(numbers);
	CompareArrays(numbers, {});
}

TEST(ReadNumbersTest, HandlesValidInput) {
	std::vector<double> numbers;
	std::istringstream input("1.0 2.0 3.0");
	std::cin.rdbuf(input.rdbuf());
	EXPECT_TRUE(ReadNumbers(numbers));
	CompareArrays(numbers, {1.0, 2.0, 3.0});
}

TEST(ReadNumbersTest, HandlesInvalidInput) {
	std::vector<double> numbers;
	std::istringstream input("1.0 abc 3.0");
	std::cin.rdbuf(input.rdbuf());
	EXPECT_FALSE(ReadNumbers(numbers));
}

void TestMain(const std::string& inputFile, const std::string& expectedOutputFile) {
	std::ifstream input(inputFile);
	std::ifstream expectedOutput(expectedOutputFile);
	std::stringstream output;

	std::cin.rdbuf(input.rdbuf());
	std::cout.rdbuf(output.rdbuf());

	main();

	std::string expectedLine, outputLine;
	while (std::getline(expectedOutput, expectedLine) && std::getline(output, outputLine)) {
		EXPECT_EQ(outputLine, expectedLine);
	}
}

TEST(MainTest, HandlesValidInput) {
	TestMain("test_input.txt", "test_expected_output.txt");
}

TEST(MainTest, HandlesInvalidInput) {
	TestMain("test_invalid_input.txt", "test_expected_error.txt");
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}