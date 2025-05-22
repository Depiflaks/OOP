//
// Created by smmm on 22.05.2025.
//
#include "StringList.h"
#include <gtest/gtest.h>
#include <ranges>

TEST(Constructors, DefaultConstructor)
{
	StringList list;
	EXPECT_TRUE(list.IsEmpty());
	EXPECT_EQ(list.GetSize(), 0);
}

TEST(Constructors, CopyConstructor)
{
	StringList src;
	src.PushBack("one");
	src.PushBack("two");

	StringList copy(src);
	EXPECT_EQ(copy.GetSize(), 2);
	EXPECT_FALSE(copy.IsEmpty());

	auto itSrc = src.begin();
	auto itCopy = copy.begin();
	for (; itSrc != src.end() && itCopy != copy.end(); ++itSrc, ++itCopy)
	{
		EXPECT_EQ(*itSrc, *itCopy);
	}
	EXPECT_EQ(itSrc, src.end());
	EXPECT_EQ(itCopy, copy.end());
}

TEST(Constructors, MoveConstructor)
{
	StringList src;
	src.PushBack("one");
	src.PushBack("two");

	StringList moved(std::move(src));
	EXPECT_EQ(moved.GetSize(), 2);
	EXPECT_TRUE(src.IsEmpty());
}

TEST(AssignmentOperators, CopyAssignment)
{
	StringList src;
	src.PushBack("one");
	src.PushBack("two");

	StringList dest;
	dest.PushBack("x");
	dest = src;
	EXPECT_EQ(dest.GetSize(), src.GetSize());

	auto itSrc = src.begin();
	auto itDest = dest.begin();
	for (; itSrc != src.end() && itDest != dest.end(); ++itSrc, ++itDest)
	{
		EXPECT_EQ(*itSrc, *itDest);
	}
}

TEST(AssignmentOperators, MoveAssignment)
{
	StringList src;
	src.PushBack("one");
	src.PushBack("two");

	StringList dest;
	dest.PushBack("x");
	dest.PushBack("y");
	dest = std::move(src);

	EXPECT_EQ(dest.GetSize(), 2);
	EXPECT_TRUE(src.IsEmpty());
}

TEST(Destructor, BasicDestruction)
{
	{
		StringList list;
		list.PushBack("one");
		list.PushBack("two");
	}
	SUCCEED();
}

TEST(PushBackFront, PushFrontNonEmpty)
{
	StringList list;
	list.PushBack("two");
	list.PushFront("one");

	EXPECT_EQ(list.GetSize(), 2);
	auto it = list.begin();
	EXPECT_EQ(*it, "one");
	++it;
	EXPECT_EQ(*it, "two");
}

TEST(PushBackFront, PushBackNonEmpty)
{
	StringList list;
	list.PushFront("one");
	list.PushBack("two");

	EXPECT_EQ(list.GetSize(), 2);
	auto it = list.begin();
	EXPECT_EQ(*it, "one");
	++it;
	EXPECT_EQ(*it, "two");
}

TEST(PushBackFront, PushFrontEmpty)
{
	StringList list;
	list.PushFront("one");

	EXPECT_EQ(list.GetSize(), 1);
	EXPECT_EQ(*list.begin(), "one");
}

TEST(PushBackFront, PushBackEmpty)
{
	StringList list;
	list.PushBack("one");

	EXPECT_EQ(list.GetSize(), 1);
	EXPECT_EQ(*list.begin(), "one");
}

TEST(SizeEmpty, GetSize)
{
	StringList list;
	EXPECT_EQ(list.GetSize(), 0);
	list.PushBack("one");
	EXPECT_EQ(list.GetSize(), 1);
}

TEST(SizeEmpty, IsEmpty)
{
	StringList list;
	EXPECT_TRUE(list.IsEmpty());
	list.PushBack("one");
	EXPECT_FALSE(list.IsEmpty());
}

TEST(Clear, ClearNonEmptyList)
{
	StringList list;
	list.PushBack("one");
	list.PushBack("two");
	list.Clear();

	EXPECT_TRUE(list.IsEmpty());
	EXPECT_EQ(list.GetSize(), 0);
}

TEST(Insert, InsertNormal)
{
	StringList list;
	list.PushBack("one");
	list.PushBack("three");

	auto it = list.begin();
	++it; // указывает на "three"
	auto insertedIt = list.Insert(it, "two");

	EXPECT_EQ(*insertedIt, "two");
	EXPECT_EQ(list.GetSize(), 3);

	std::string expected[] = { "one", "two", "three" };
	size_t i = 0;
	for (auto& val : list)
	{
		EXPECT_EQ(val, expected[i++]);
	}
}

TEST(Insert, InsertOutOfBounds)
{
	StringList list;
	list.PushBack("one");
	list.PushBack("two");

	auto endIt = list.end();
	auto insertedIt = list.Insert(endIt, "three");
	EXPECT_EQ(*insertedIt, "three");
	EXPECT_EQ(*std::prev(insertedIt), "two");
	EXPECT_EQ(list.GetSize(), 3);
}

TEST(Erase, EraseNormal)
{
	StringList list;
	list.PushBack("one");
	list.PushBack("two");
	list.PushBack("three");

	auto it = list.begin();
	++it;
	auto nextIt = list.Erase(it);

	EXPECT_EQ(*nextIt, "three");
	EXPECT_EQ(list.GetSize(), 2);

	std::string expected[] = { "one", "three" };
	size_t i = 0;
	for (auto& val : list)
	{
		EXPECT_EQ(val, expected[i++]);
	}
}

TEST(Erase, EraseOutOfBounds)
{
	StringList list;
	list.PushBack("one");
	list.PushBack("two");

	auto endIt = list.end();
	auto resultIt = list.Erase(endIt);
	EXPECT_EQ(resultIt, list.end());
	EXPECT_EQ(list.GetSize(), 2);
}

TEST(Iterators, BeginEndIteration)
{
	StringList list;
	list.PushBack("one");
	list.PushBack("two");

	std::string expected[] = { "one", "two" };
	size_t i = 0;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		EXPECT_EQ(*it, expected[i++]);
	}
}

TEST(Iterators, OutOfRange)
{
	StringList list;
	list.PushBack("one");
	list.PushBack("two");
	auto endIt = list.end();
	ASSERT_DEATH({ auto val = *endIt;
	(void)val; }, ".*");
}

TEST(Iterators, StdRangesIteration)
{
	StringList list;
	list.PushBack("one");
	list.PushBack("two");

	std::string expected[] = { "one", "two" };
	size_t i = 0;
	for (const auto& s : std::ranges::subrange(list.begin(), list.end()))
	{
		EXPECT_EQ(s, expected[i++]);
	}
}

TEST(ReverseIterators, ReverseIteration)
{
	StringList list;
	list.PushBack("one");
	list.PushBack("two");
	list.PushBack("three");

	std::string expected[] = { "three", "two", "one" };
	size_t i = 0;
	for (auto it = list.rbegin(); it != list.rend(); ++it)
	{
		EXPECT_EQ(*it, expected[i++]);
	}
}

TEST(ReverseIterators, ConstReverseIteration)
{
	StringList list;
	list.PushBack("one");
	list.PushBack("two");
	list.PushBack("three");

	const auto& constList = list;
	std::string expected[] = { "three", "two", "one" };
	size_t i = 0;
	for (auto it = constList.rbegin(); it != constList.rend(); ++it)
	{
		EXPECT_EQ(*it, expected[i++]);
	}
}
