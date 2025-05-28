//
// Created by smmm on 28.05.2025.
//
#include <gtest/gtest.h>
#include <myArray/MyArray.h>
#include <string>

TEST(MyArrayTest, CopyConstructorCreatesDeepCopy) {
    MyArray<std::string> original;
    original.PushBack("hello");
    original.PushBack("world");

    MyArray<std::string> copy(original);
    EXPECT_EQ(copy.GetSize(), 2);
    EXPECT_EQ(copy[0], "hello");
    EXPECT_EQ(copy[1], "world");

    original[0] = "changed";
    EXPECT_EQ(copy[0], "hello");
}

TEST(MyArrayTest, CopyAssignmentCreatesDeepCopy) {
    MyArray<double> a;
    a.PushBack(1.5);
    a.PushBack(2.5);

    MyArray<double> b;
    b = a;

    EXPECT_EQ(b.GetSize(), 2);
    EXPECT_DOUBLE_EQ(b[0], 1.5);
    EXPECT_DOUBLE_EQ(b[1], 2.5);

    a[0] = 9.9;
    EXPECT_DOUBLE_EQ(b[0], 1.5);
}

TEST(MyArrayTest, SelfCopyAssignmentDoesNotChangeArray) {
    MyArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);

    arr = arr;

    EXPECT_EQ(arr.GetSize(), 2);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
}

TEST(MyArrayTest, MoveConstructorTransfersOwnership) {
    MyArray<std::string> source;
    source.PushBack("x");
    source.PushBack("y");

    MyArray<std::string> moved(std::move(source));

    EXPECT_EQ(moved.GetSize(), 2);
    EXPECT_EQ(moved[0], "x");
    EXPECT_EQ(moved[1], "y");
    EXPECT_EQ(source.GetSize(), 0);
    EXPECT_THROW(source[0], std::out_of_range);
}

TEST(MyArrayTest, MoveAssignmentTransfersOwnership) {
    MyArray<int> src;
    src.PushBack(42);
    src.PushBack(43);

    MyArray<int> dest;
    dest.PushBack(99);

    dest = std::move(src);

    EXPECT_EQ(dest.GetSize(), 2);
    EXPECT_EQ(dest[0], 42);
    EXPECT_EQ(dest[1], 43);
    EXPECT_EQ(src.GetSize(), 0);
    EXPECT_THROW(src[0], std::out_of_range);
}
