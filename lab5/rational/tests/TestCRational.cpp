//
// Created by smmm on 06.05.2025.
//
#include <cRational/CRational.h>
#include <gtest/gtest.h>


// Constructor Tests:

TEST(ConstructorTest, ZeroDenominator)
{
	EXPECT_THROW(CRational(1, 0), std::invalid_argument);
}

// operator +

TEST(OperatorOverloading, OperatorPlus)
{
	CRational a(1, 2);
	CRational b(1, 2);

}


TEST(MyTestSuite, BasicTest)
{
	EXPECT_EQ(2 + 2, 4);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}