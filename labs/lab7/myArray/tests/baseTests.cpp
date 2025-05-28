//
// Created by smmm on 28.05.2025.
//
#include <gtest/gtest.h>
#include <myArray/MyArray.h>
#include <string>

TEST(MyArrayTest, DefaultConstructor)
{
    MyArray<int> arr;
    EXPECT_EQ(arr.GetSize(), 0);
}

TEST(MyArrayTest, PushBackIncreasesSizeAndStoresElements) {
    MyArray<double> arr;
    arr.PushBack(1.1);
    arr.PushBack(2.2);
    arr.PushBack(3.3);

    EXPECT_EQ(arr.GetSize(), 3);
    EXPECT_DOUBLE_EQ(arr[0], 1.1);
    EXPECT_DOUBLE_EQ(arr[1], 2.2);
    EXPECT_DOUBLE_EQ(arr[2], 3.3);
}

TEST(MyArrayTest, IndexOperatorThrowsOutOfRange) {
    MyArray<std::string> arr;
    arr.PushBack("hello");
    EXPECT_NO_THROW(arr[0]);
    EXPECT_THROW(arr[1], std::out_of_range);
}

TEST(MyArrayTest, ClearRemovesAllElements) {
    MyArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    arr.Clear();
    EXPECT_EQ(arr.GetSize(), 0);
    EXPECT_THROW(arr[0], std::out_of_range);
}

TEST(MyArrayTest, ResizeIncreaseInitializesWithDefault)
{
    MyArray<int> arr;
    arr.PushBack(1);
    arr.ResizeWithErrorHandling(5);

    EXPECT_EQ(arr.GetSize(), 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 0);
    EXPECT_EQ(arr[2], 0);
    EXPECT_EQ(arr[3], 0);
    EXPECT_EQ(arr[4], 0);
}

TEST(MyArrayTest, ResizeDecreaseRemovesElements) {
    MyArray<std::string> arr;
    arr.PushBack("one");
    arr.PushBack("two");
    arr.PushBack("three");
    arr.ResizeWithErrorHandling(1);

    EXPECT_EQ(arr.GetSize(), 1);
    EXPECT_EQ(arr[0], "one");
    EXPECT_THROW(arr[1], std::out_of_range);
}
