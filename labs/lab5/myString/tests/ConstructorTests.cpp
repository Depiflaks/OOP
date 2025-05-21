//
// Created by smmm on 21.05.2025.
//

#include "../src/MyString.h"
#include <gtest/gtest.h>

TEST(ConstructorFromC, Standart)
{
	MyString str("hello");
	EXPECT_EQ(str.GetLength(), 5u);
	EXPECT_GE(str.GetCapacity(), 5u);
	EXPECT_EQ(str.GetStringData()[str.GetLength()], '\0');
}

TEST(ConstructorFromC, StringAndLength)
{
	const char* data = "hello world";
	MyString str(data, 5);
	EXPECT_EQ(str.GetLength(), 5u);
	EXPECT_GE(str.GetCapacity(), 5u);
	EXPECT_STREQ(str.GetStringData(), "hello");
	EXPECT_EQ(str.GetStringData()[str.GetLength()], '\0');
}

TEST(ConstructorFromC, LengthMoreThenString)
{
	const char* str = "abc";
	size_t declaredLength = 6;

	MyString s(str, declaredLength);

	EXPECT_EQ(s.GetLength(), declaredLength);
	EXPECT_GE(s.GetCapacity(), declaredLength);
	EXPECT_EQ(s.GetStringData()[s.GetLength()], '\0');

	for (size_t i = 0; i < 3; ++i)
	{
		EXPECT_EQ(s.GetStringData()[i], str[i]);
	}
}

TEST(ConstructorFromStd, Standart)
{
	std::string stdStr = "world";
	MyString str(stdStr);
	EXPECT_EQ(str.GetLength(), 5u);
	EXPECT_GE(str.GetCapacity(), 5u);
	EXPECT_STREQ(str.GetStringData(), "world");
	EXPECT_EQ(str.GetStringData()[str.GetLength()], '\0');
}

TEST(SubString, ReturnsCorrectLength)
{
	MyString str("abcdef");
	MyString sub = str.SubString(2, 3);
	EXPECT_EQ(sub.GetLength(), 3u);
	EXPECT_STREQ(sub.GetStringData(), "cde");
	EXPECT_EQ(sub.GetStringData()[sub.GetLength()], '\0');
}

TEST(SubString, OutOfRangeHandledGracefully)
{
    MyString s("abcdef");
    size_t originalLength = s.GetLength();

    size_t start = 3;
    size_t requestedLength = 10;

    MyString sub = s.SubString(start, requestedLength);

    EXPECT_EQ(sub.GetLength(), originalLength - start);
    EXPECT_EQ(sub.GetCapacity(), originalLength - start);
    EXPECT_EQ(sub.GetStringData()[sub.GetLength()], '\0');

    for (size_t i = 0; i < sub.GetLength(); ++i)
    {
        EXPECT_EQ(sub.GetStringData()[i], s.GetStringData()[start + i]);
    }
}
TEST(SubString, WithoutLength)
{
    MyString s("abcdef");
    size_t originalLength = s.GetLength();

    size_t start = 3;

    MyString sub = s.SubString(start);

    EXPECT_EQ(sub.GetLength(), originalLength - start);
    EXPECT_EQ(sub.GetCapacity(), originalLength - start);
    EXPECT_EQ(sub.GetStringData()[sub.GetLength()], '\0');

    for (size_t i = 0; i < sub.GetLength(); ++i)
    {
        EXPECT_EQ(sub.GetStringData()[i], s.GetStringData()[start + i]);
    }
}

TEST(MoveConstructor, DoesNotThrowAndLeavesDonorEmpty)
{
	MyString source("move me");
	size_t originalLength = source.GetLength();

	EXPECT_NO_THROW({
		MyString moved = std::move(source);
		EXPECT_EQ(moved.GetLength(), originalLength);
		EXPECT_EQ(moved.GetStringData()[moved.GetLength()], '\0');
		EXPECT_EQ(source.GetLength(), 0u);
		EXPECT_STREQ(source.GetStringData(), "");
		EXPECT_EQ(source.GetStringData()[source.GetLength()], '\0');
	});
}
TEST(ClearMethod, ClearsStringCorrectly)
{
	MyString str("hello");
	EXPECT_NO_THROW({
		str.Clear();
		EXPECT_EQ(str.GetLength(), 0u);
		EXPECT_STREQ(str.GetStringData(), "");
		EXPECT_EQ(str.GetStringData()[str.GetLength()], '\0');
	});
}

TEST(ClearMethod, DoubleClearDoesNotThrow)
{
	MyString str("hello");
	EXPECT_NO_THROW({
		str.Clear();
		str.Clear();
		EXPECT_EQ(str.GetLength(), 0u);
		EXPECT_STREQ(str.GetStringData(), "");
		EXPECT_EQ(str.GetStringData()[str.GetLength()], '\0');
	});
}

TEST(ClearMethod, ClearAfterMoveDoesNotThrow)
{
	MyString str("to be moved");
	MyString moved = std::move(str);
	EXPECT_NO_THROW({
		str.Clear();
		EXPECT_EQ(str.GetLength(), 0u);
		EXPECT_STREQ(str.GetStringData(), "");
		EXPECT_EQ(str.GetStringData()[str.GetLength()], '\0');
	});
}
