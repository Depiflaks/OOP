//
// Created by smmm on 21.05.2025.
//
#include "../MyString.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(Assignment, CopyAssignment)
{
	MyString str1("Hello,");
	MyString str2("World");
	str2 = str1;
	EXPECT_EQ(str2.GetLength(), str1.GetLength());
	EXPECT_STREQ(str2.GetStringData(), str1.GetStringData());
	EXPECT_EQ(str2.GetStringData()[str2.GetLength()], '\0');
}

TEST(Assignment, SelfAssignment)
{
	MyString str("Self");
	str = str;
	EXPECT_EQ(str.GetLength(), 4u);
	EXPECT_STREQ(str.GetStringData(), "Self");
	EXPECT_EQ(str.GetStringData()[str.GetLength()], '\0');
}

TEST(Assignment, AssignStdString)
{
	std::string str = "FromStdString";
	MyString myStr;
	myStr = str;
	EXPECT_EQ(myStr.GetLength(), str.length());
	EXPECT_STREQ(myStr.GetStringData(), str.c_str());
	EXPECT_EQ(myStr.GetStringData()[myStr.GetLength()], '\0');
}

TEST(Assignment, AssignConstChar)
{
	const char* str = "FromConstChar";
	MyString myStr;
	myStr = str;
	EXPECT_EQ(myStr.GetLength(), strlen(str));
	EXPECT_STREQ(myStr.GetStringData(), str);
	EXPECT_EQ(myStr.GetStringData()[myStr.GetLength()], '\0');
}

TEST(Addition, MyStringMyString)
{
	MyString a("Hello");
	MyString b("World");
	MyString result = a + b;
	EXPECT_EQ(result.GetLength(), 10u);
	EXPECT_STREQ(result.GetStringData(), "HelloWorld");
	EXPECT_EQ(result.GetStringData()[result.GetLength()], '\0');
}

TEST(Addition, StdStringMyString)
{
	std::string a = "Hi";
	MyString b{ "There" };
	MyString result = a + b;
	EXPECT_EQ(result.GetLength(), 7u);
	EXPECT_STREQ(result.GetStringData(), "HiThere");
	EXPECT_EQ(result.GetStringData()[result.GetLength()], '\0');
}

TEST(Addition, ConstCharMyString)
{
	const char* a = "Yo";
	MyString b("Man");
	MyString result = a + b;
	EXPECT_EQ(result.GetLength(), 5u);
	EXPECT_STREQ(result.GetStringData(), "YoMan");
	EXPECT_EQ(result.GetStringData()[result.GetLength()], '\0');
}

TEST(Addition, MyStringStdString)
{
	MyString a("Hi");
	std::string b = "There";
	MyString result = a + b;
	EXPECT_EQ(result.GetLength(), 7u);
	EXPECT_STREQ(result.GetStringData(), "HiThere");
	EXPECT_EQ(result.GetStringData()[result.GetLength()], '\0');
}

TEST(Addition, MyStringConstChar)
{
	MyString a("Yo");
	const char* b = "Man";
	MyString result = a + b;
	EXPECT_EQ(result.GetLength(), 5u);
	EXPECT_STREQ(result.GetStringData(), "YoMan");
	EXPECT_EQ(result.GetStringData()[result.GetLength()], '\0');
}

TEST(PlusEqual, MyStringMyString)
{
	MyString a("One");
	MyString b("Two");
	a += b;
	EXPECT_EQ(a.GetLength(), 6u);
	EXPECT_STREQ(a.GetStringData(), "OneTwo");
	EXPECT_EQ(a.GetStringData()[a.GetLength()], '\0');
}

TEST(PlusEqual, StdStringToMyString)
{
	MyString a("Hello");
	std::string b = "World";
	a += b;
	EXPECT_EQ(a.GetLength(), 10u);
	EXPECT_STREQ(a.GetStringData(), "HelloWorld");
	EXPECT_EQ(a.GetStringData()[a.GetLength()], '\0');
}

TEST(PlusEqual, ConstCharToMyString)
{
	MyString a("Hi");
	const char* b = "There";
	a += b;
	EXPECT_EQ(a.GetLength(), 7u);
	EXPECT_STREQ(a.GetStringData(), "HiThere");
	EXPECT_EQ(a.GetStringData()[a.GetLength()], '\0');
}

TEST(Equal, CompareEqual)
{
	MyString a("same");
	MyString b("same");
	EXPECT_TRUE(a == b);
}

TEST(Equal, StdStringAndMyString)
{
	MyString a("test");
	std::string b = "test";
	EXPECT_TRUE(a == b);
	EXPECT_TRUE(b == a);
}

TEST(Equal, ConstCharAndMyString)
{
	MyString a("match");
	const char* b = "match";
	EXPECT_TRUE(a == b);
	EXPECT_TRUE(b == a);
}

TEST(NotEqual, CompareNotEqual)
{
	MyString a("abc");
	MyString b("def");
	EXPECT_TRUE(a != b);
}

TEST(NotEqual, StdStringAndMyString)
{
	MyString a("abc");
	std::string b = "def";
	EXPECT_TRUE(a != b);
	EXPECT_TRUE(b != a);
}

TEST(NotEqual, ConstCharAndMyString)
{
	MyString a("left");
	const char* b = "right";
	EXPECT_TRUE(a != b);
	EXPECT_TRUE(b != a);
}

TEST(Less, LexicographicalOrder)
{
	MyString a("abc");
	MyString b("bcd");
	EXPECT_TRUE(a < b);
}

TEST(Less, StdStringAndMyString)
{
	MyString a("abc");
	std::string b = "bcd";
	EXPECT_TRUE(a < b);
	EXPECT_FALSE(b < a);
}

TEST(Less, ConstCharAndMyString)
{
	MyString a("abc");
	const char* b = "xyz";
	EXPECT_TRUE(a < b);
	EXPECT_FALSE(b < a);
}

TEST(Greater, LexicographicalOrder)
{
	MyString a("xyz");
	MyString b("uvw");
	EXPECT_TRUE(a > b);
}

TEST(Greater, StdStringAndMyString)
{
	MyString a("zzz");
	std::string b = "aaa";
	EXPECT_TRUE(a > b);
	EXPECT_FALSE(b > a);
}

TEST(Greater, ConstCharAndMyString)
{
	MyString a("hello");
	const char* b = "abc";
	EXPECT_TRUE(a > b);
	EXPECT_FALSE(b > a);
}

TEST(LessEqual, LexicographicalOrder)
{
	MyString a("abc");
	MyString b("abc");
	MyString c("abd");
	EXPECT_TRUE(a <= b);
	EXPECT_TRUE(a <= c);
}

TEST(GreaterEqual, LexicographicalOrder)
{
	MyString a("abc");
	MyString b("abc");
	MyString c("abb");
	EXPECT_TRUE(a >= b);
	EXPECT_TRUE(a >= c);
}

TEST(LessEqual, StdStringAndMyString)
{
	MyString a("abc");
	std::string b = "abc";
	EXPECT_TRUE(a <= b);
	EXPECT_TRUE(b <= a);
}

TEST(LessEqual, ConstCharAndMyString)
{
	MyString a("aaa");
	const char* b = "bbb";
	EXPECT_TRUE(a <= b);
	EXPECT_FALSE(b <= a);
}

TEST(GreaterEqual, StdStringAndMyString)
{
	MyString a("zzz");
	std::string b = "zzz";
	EXPECT_TRUE(a >= b);
	EXPECT_TRUE(b >= a);
}

TEST(GreaterEqual, ConstCharAndMyString)
{
	MyString a("ccc");
	const char* b = "bbb";
	EXPECT_TRUE(a >= b);
	EXPECT_FALSE(b >= a);
}

TEST(Index, ReadAccess)
{
	MyString str("Index");
	EXPECT_EQ(str[0], 'I');
	EXPECT_EQ(str[4], 'x');
}

TEST(Index, WriteAccess)
{
	MyString str("Write");
	str[0] = 'B';
	str[4] = 'd';
	EXPECT_STREQ(str.GetStringData(), "Britd");
	EXPECT_EQ(str.GetStringData()[str.GetLength()], '\0');
}

TEST(OStream, OutputToStream)
{
	MyString str("StreamOut");
	std::ostringstream oss;
	oss << str;
	EXPECT_EQ(oss.str(), "StreamOut");
}

TEST(IStream, InputFromStream)
{
	MyString str;
	std::istringstream iss("HelloInput");
	iss >> str;
	EXPECT_STREQ(str.GetStringData(), "HelloInput");
	EXPECT_EQ(str.GetLength(), 10u);
	EXPECT_EQ(str.GetStringData()[str.GetLength()], '\0');
}
