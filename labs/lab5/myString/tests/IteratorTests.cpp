//
// Created by smmm on 21.05.2025.
//
#include "MyString.h"
#include <gtest/gtest.h>

TEST(Iterator, ForwardIteration)
{
	MyString str("hello");
	std::string result;
	for (auto it = str.begin(); it != str.end(); ++it)
		result += *it;
	EXPECT_EQ(result, "hello");
}

TEST(Iterator, ConstForwardIteration)
{
	const MyString str("world");
	std::string result;
	for (auto it = str.begin(); it != str.end(); ++it)
		result += *it;
	EXPECT_EQ(result, "world");
}

TEST(Iterator, ReverseIteration)
{
	MyString str("abc");
	std::string result;
	for (auto it = str.rbegin(); it != str.rend(); ++it)
		result += *it;
	EXPECT_EQ(result, "cba");
}

TEST(Iterator, ConstReverseIteration)
{
	const MyString str("xyz");
	std::string result;
	for (auto it = str.rbegin(); it != str.rend(); ++it)
		result += *it;
	EXPECT_EQ(result, "zyx");
}

TEST(Iterator, RangeBasedFor)
{
	MyString str("range");
	std::string result;
	for (char ch : str)
		result += ch;
	EXPECT_EQ(result, "range");
}

TEST(Iterator, IteratorArithmetic)
{
	MyString str("abcdef");
	auto begin = str.begin();
	auto end = str.end();
	ptrdiff_t distance = end - begin;
	EXPECT_EQ(distance, 6);

	auto it = begin + 3;
	EXPECT_EQ(*it, 'd');
}

TEST(Iterator, IteratorIndexAccess)
{
	MyString str("iterator");
	auto it = str.begin();
	EXPECT_EQ(it[0], 'i');
	EXPECT_EQ(it[3], 'r');
	EXPECT_EQ(it[7], 'r');
}

TEST(Iterator, ConstIteratorIndexAccess)
{
	const MyString str("testing");
	auto it = str.begin();
	EXPECT_EQ(it[1], 'e');
	EXPECT_EQ(it[5], 'n');
}


TEST(IteratorBounds, DereferenceOutOfBounds)
{
	MyString str("abc");
	auto it = str.begin();

	it += 3;
	EXPECT_DEATH(*it, "");
}

TEST(IteratorBounds, IndexingOutOfBounds)
{
	MyString str("abc");
	auto it = str.begin();

	EXPECT_DEATH(it[3], "");
	EXPECT_DEATH(it[-1], "");
}

TEST(IteratorBounds, ConstDereferenceOutOfBounds)
{
	const MyString str("abc");
	auto it = str.cbegin();

	it += 3;
	EXPECT_DEATH(*it, "");
}

TEST(IteratorBounds, ConstIndexingOutOfBounds)
{
	const MyString str("abc");
	auto it = str.cbegin();

	EXPECT_DEATH(it[3], "");
	EXPECT_DEATH(it[-1], "");
}

TEST(IteratorBounds, ReverseIteratorBounds)
{
	MyString str("abc");

	auto rit = str.rbegin();
	rit += 3;

	EXPECT_DEATH(*rit, "");
	EXPECT_DEATH(rit[1], "");
}
