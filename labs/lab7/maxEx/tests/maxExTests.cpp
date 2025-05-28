//
// Created by smmm on 27.05.2025.
//
#include "athlete/Athlete.h"
#include "findMax.h"

#include <gtest/gtest.h>

TEST(FindMaxTests, EmptyArrayReturnsFalse)
{
	std::vector<int> empty;
	int result = -1;
	EXPECT_FALSE(FindMax(empty, result, std::less()));
}

TEST(FindMaxTests, AllElementsEqualReturnsFirst)
{
	std::vector arr = { 5, 5, 5 };
	int result = 0;
	EXPECT_TRUE(FindMax(arr, result, std::less()));
	EXPECT_EQ(result, 5);
}

TEST(FindMaxTests, MaxByGreaterComparison)
{
	std::vector arr = { 1, 3, 2 };
	int result = 0;
	EXPECT_TRUE(FindMax(arr, result, std::less()));
	EXPECT_EQ(result, 3);
}

TEST(FindMaxTests, MaxByCustomReverseComparison)
{
	std::vector arr = { 10, 20, 30 };
	int result = 0;
	auto reverse = [](int a, int b) { return a > b; };
	EXPECT_TRUE(FindMax(arr, result, reverse));
	EXPECT_EQ(result, 10);
}

TEST(FindMaxTests, CommitRollbackNoAssignmentOnEmpty)
{
	std::vector<int> empty;
	int original = 42;
	int result = original;
	EXPECT_FALSE(FindMax(empty, result, std::less()));
	EXPECT_EQ(result, original);
}

TEST(FindMaxTests, CommitRollbackOnExceptionInAssignment)
{
	struct FragileInt
	{
		int value;
		explicit FragileInt(int v)
			: value(v)
		{
		}
		FragileInt(const FragileInt&) = default;
		FragileInt& operator=(const FragileInt&)
		{
			throw std::runtime_error("assign failed");
		}
		bool operator<(const FragileInt& other) const { return value < other.value; }
	};

	const std::vector arr = { FragileInt(1), FragileInt(2) };
	FragileInt target(0);

	try
	{
		FindMax(arr, target, [](const FragileInt& a, const FragileInt& b) { return a < b; });
		FAIL();
	}
	catch (const std::runtime_error& e)
	{
		EXPECT_STREQ(e.what(), "assign failed");
		EXPECT_EQ(target.value, 0);
	}
}

TEST(FindMaxAthleteTests, EmptyReturnsFalse)
{
    std::vector<Athlete> athletes;
    Athlete result("N/A", 0, 0);
    EXPECT_FALSE(FindMax(athletes, result, CompareByHeight));
}

TEST(FindMaxAthleteTests, AllEqualHeight)
{
    std::vector<Athlete> athletes = {
        {"A", 1.80, 70},
        {"B", 1.80, 75},
        {"C", 1.80, 80}
    };
    Athlete result("X", 0, 0);
    EXPECT_TRUE(FindMax(athletes, result, CompareByHeight));
    EXPECT_EQ(result.name, "A");
}

TEST(FindMaxAthleteTests, FindByHeight)
{
    std::vector<Athlete> athletes = {
        {"A", 1.70, 70},
        {"B", 1.90, 80},
        {"C", 1.85, 90}
    };
    Athlete result("X", 0, 0);
    EXPECT_TRUE(FindMax(athletes, result, CompareByHeight));
    EXPECT_EQ(result.name, "B");
}

TEST(FindMaxAthleteTests, FindByWeight)
{
    std::vector<Athlete> athletes = {
        {"A", 1.70, 60},
        {"B", 1.85, 75},
        {"C", 1.90, 90}
    };
    Athlete result("X", 0, 0);
    EXPECT_TRUE(FindMax(athletes, result, CompareByWeight));
    EXPECT_EQ(result.name, "C");
}

TEST(FindMaxAthleteTests, CommitRollbackNoAssignmentOnEmpty)
{
    std::vector<Athlete> athletes;
    Athlete original("Original", 1.75, 70);
    Athlete result = original;
    EXPECT_FALSE(FindMax(athletes, result, CompareByWeight));
    EXPECT_EQ(result.name, original.name);
    EXPECT_EQ(result.height, original.height);
    EXPECT_EQ(result.weight, original.weight);
}
