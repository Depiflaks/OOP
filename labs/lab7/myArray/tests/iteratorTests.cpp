//
// Created by smmm on 28.05.2025.
//
#include <algorithm>
#include <gtest/gtest.h>
#include <myArray/MyArray.h>
#include <numeric>
#include <ranges>
#include <string>

TEST(MyArrayIteratorTest, ForwardIteration) {
    MyArray<double> arr;
    arr.PushBack(1.1);
    arr.PushBack(2.2);
    arr.PushBack(3.3);

    std::vector<double> expected = {1.1, 2.2, 3.3};
    size_t index = 0;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        EXPECT_DOUBLE_EQ(*it, expected[index++]);
    }
}

TEST(MyArrayIteratorTest, RangeBasedForWorks) {
    MyArray<double> arr;
    arr.PushBack(1.5);
    arr.PushBack(2.5);
    arr.PushBack(3.5);

    double sum = 0.0;
    for (double x : arr) {
        sum += x;
    }

    EXPECT_DOUBLE_EQ(sum, 7.5);
}

TEST(MyArrayIteratorTest, ReverseIteration) {
    MyArray<double> arr;
    arr.PushBack(10.0);
    arr.PushBack(20.0);
    arr.PushBack(30.0);

    std::vector<double> collected;
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        collected.push_back(*it);
    }

    ASSERT_EQ(collected.size(), 3);
    EXPECT_DOUBLE_EQ(collected[0], 30.0);
    EXPECT_DOUBLE_EQ(collected[1], 20.0);
    EXPECT_DOUBLE_EQ(collected[2], 10.0);
}

TEST(MyArrayIteratorTest, StdAlgorithmsWithIterators) {
    MyArray<double> arr;
    arr.PushBack(1.0);
    arr.PushBack(2.0);
    arr.PushBack(3.0);
    arr.PushBack(4.0);

    double sum = std::accumulate(arr.begin(), arr.end(), 0.0);
    EXPECT_DOUBLE_EQ(sum, 10.0);

    auto found = std::find(arr.begin(), arr.end(), 3.0);
    ASSERT_NE(found, arr.end());
    EXPECT_DOUBLE_EQ(*found, 3.0);
}

TEST(MyArrayIteratorTest, SupportsStdRanges) {
    MyArray<double> arr;
    arr.PushBack(1.0);
    arr.PushBack(2.0);
    arr.PushBack(3.0);

    auto squared = arr | std::views::transform([](double x) { return x * x; });

    std::vector<double> result;
    for (double x : squared) {
        result.push_back(x);
    }

    ASSERT_EQ(result.size(), 3);
    EXPECT_DOUBLE_EQ(result[0], 1.0);
    EXPECT_DOUBLE_EQ(result[1], 4.0);
    EXPECT_DOUBLE_EQ(result[2], 9.0);
}
