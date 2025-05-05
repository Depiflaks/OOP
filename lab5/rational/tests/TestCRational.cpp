//
// Created by smmm on 06.05.2025.
//
#include <cRational/CRational.h>
#include <gtest/gtest.h>


// Constructor Tests:

TEST(ConstructorTest, ZeroDenominator)
{
	EXPECT_THROW(CRational(1, 0), ZeroDenominatorException);
}

TEST(ConstructorTest, NegativeDenominator)
{
	EXPECT_EQ(CRational(1, -1), CRational(-1, 1));
	EXPECT_EQ(CRational(-1, -1), CRational(1, 1));
}

TEST(ConstructorTest, Normalization) {
	const CRational r(2, 4);
    EXPECT_EQ(r.GetNumerator(), 1);
    EXPECT_EQ(r.GetDenominator(), 2);
}

// Unary operators
TEST(OperatorOverloading, UnaryPlus) {
    CRational a(3, 4);
    EXPECT_EQ(+a, CRational(3, 4));
}

TEST(OperatorOverloading, UnaryMinus) {
    CRational a(3, 4);
    EXPECT_EQ(-a, CRational(-3, 4));
}

// Binary arithmetic
TEST(OperatorOverloading, BinaryPlus) {
    CRational a(1, 2);
    CRational b(1, 3);
    EXPECT_EQ(a + b, CRational(5, 6));
}

TEST(OperatorOverloading, BinaryMinus) {
    CRational a(1, 2);
    CRational b(1, 3);
    EXPECT_EQ(a - b, CRational(1, 6));
}

// Compound assignment
TEST(OperatorOverloading, PlusAssignment) {
    CRational a(1, 2);
    a += CRational(1, 3);
    EXPECT_EQ(a, CRational(5, 6));
}

TEST(OperatorOverloading, MinusAssignment) {
    CRational a(1, 2);
    a -= CRational(1, 3);
    EXPECT_EQ(a, CRational(1, 6));
}

// // Multiplication and division
// TEST(OperatorOverloading, Multiplication) {
//     CRational a(1, 2);
//     CRational b(2, 3);
//     EXPECT_EQ(a * b, CRational(1, 3));
// }
//
// TEST(OperatorOverloading, Division) {
//     CRational a(1, 2);
//     CRational b(2, 3);
//     EXPECT_EQ(a / b, CRational(3, 4));
// }
//
// TEST(OperatorOverloading, MultiplyAssignment) {
//     CRational a(1, 2);
//     a *= CRational(2, 3);
//     EXPECT_EQ(a, CRational(1, 3));
// }
//
// TEST(OperatorOverloading, DivideAssignment) {
//     CRational a(1, 2);
//     a /= CRational(2, 3);
//     EXPECT_EQ(a, CRational(3, 4));
// }

// Comparison operators
TEST(OperatorOverloading, Equality) {
    CRational a(1, 2);
    CRational b(2, 4);
    CRational c(1, 3);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

TEST(OperatorOverloading, Inequality) {
    CRational a(1, 2);
    CRational b(1, 3);
    EXPECT_TRUE(a != b);
}

TEST(OperatorOverloading, LessThan) {
    CRational a(1, 2);
    CRational b(1, 3);
    EXPECT_TRUE(b < a);
}

TEST(OperatorOverloading, GreaterThan) {
    CRational a(1, 2);
    CRational b(1, 3);
    EXPECT_TRUE(a > b);
}

TEST(OperatorOverloading, LessOrEqual) {
    CRational a(1, 2);
    CRational b(1, 2);
    CRational c(1, 3);
    EXPECT_TRUE(c <= a);
    EXPECT_TRUE(a <= b);
}

TEST(OperatorOverloading, GreaterOrEqual) {
    CRational a(1, 2);
    CRational b(1, 2);
    CRational c(1, 3);
    EXPECT_TRUE(a >= c);
    EXPECT_TRUE(a >= b);
}

// I/O operators
TEST(OperatorOverloading, OutputStream) {
    CRational a(3, 4);
    std::ostringstream oss;
    oss << a;
    EXPECT_EQ(oss.str(), "3/4");
}
//
// TEST(OperatorOverloading, InputStream) {
//     CRational a;
//     std::istringstream iss("5/6");
//     iss >> a;
//     EXPECT_EQ(a, CRational(5, 6));
// }

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}