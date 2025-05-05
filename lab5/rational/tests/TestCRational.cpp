//
// Created by smmm on 06.05.2025.
//
#include <gtest/gtest.h>

TEST(MyTestSuite, BasicTest)
{
	EXPECT_EQ(2 + 2, 4);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}