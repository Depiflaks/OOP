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

TEST(ConstructorTest, BigNormalization) {
	const CRational r(13, 169);
    EXPECT_EQ(r.GetNumerator(), 1);
    EXPECT_EQ(r.GetDenominator(), 13);
}

// Unary operators
TEST(OperatorOverloading, UnaryPlus) {
    const CRational a(3, 4);
    EXPECT_EQ(+a, CRational(3, 4));
}

TEST(OperatorOverloading, UnaryMinus) {
    const CRational a(3, 4);
    EXPECT_EQ(-a, CRational(-3, 4));
}

TEST(OperatorOverloading, BackUnaryMinus) {
    const CRational a(-3, 4);
    EXPECT_EQ(-a, CRational(3, 4));
}

// Binary arithmetic
TEST(OperatorOverloading, BinaryPlus) {
    const CRational a(1, 2);
    const CRational b(1, 3);
    EXPECT_EQ(a + b, CRational(5, 6));
}

TEST(OperatorOverloading, BinaryPlusWithNormalize) {
    const CRational a(1, 6);
    const CRational b(1, 6);
    EXPECT_EQ(a + b, CRational(1, 3));
}

TEST(OperatorOverloading, BinaryMinus) {
    const CRational a(1, 2);
    const CRational b(1, 3);
    EXPECT_EQ(a - b, CRational(1, 6));
}

TEST(OperatorOverloading, BinaryMinusWithNormalize) {
    const CRational a(2, 3);
    const CRational b(1, 6);
    EXPECT_EQ(a - b, CRational(1, 2));
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

// Multiplication and division
TEST(OperatorOverloading, Multiplication) {
    const CRational a(1, 2);
    const CRational b(2, 3);
    EXPECT_EQ(a * b, CRational(1, 3));
}

TEST(OperatorOverloading, Division) {
    const CRational a(1, 2);
    const CRational b(2, 3);
    EXPECT_EQ(a / b, CRational(3, 4));
}

TEST(OperatorOverloading, MultiplyAssignment) {
    CRational a(1, 2);
    a *= CRational(2, 3);
    EXPECT_EQ(a, CRational(1, 3));
}

TEST(OperatorOverloading, DivideAssignment) {
    CRational a(1, 2);
    a /= CRational(2, 3);
    EXPECT_EQ(a, CRational(3, 4));
}

// Comparison operators
TEST(OperatorOverloading, Equality) {
    const CRational a(1, 2);
    const CRational b(2, 4);
    const CRational c(1, 3);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

TEST(OperatorOverloading, Inequality) {
    const CRational a(1, 2);
    const CRational b(1, 3);
    EXPECT_TRUE(a != b);
}

TEST(OperatorOverloading, LessThan) {
    const CRational a(1, 2);
    const CRational b(1, 3);
    EXPECT_TRUE(b < a);
}

TEST(OperatorOverloading, GreaterThan) {
    const CRational a(1, 2);
    const CRational b(1, 3);
    EXPECT_TRUE(a > b);
}

TEST(OperatorOverloading, LessOrEqual) {
    const CRational a(1, 2);
    const CRational b(1, 2);
    const CRational c(1, 3);
    EXPECT_TRUE(c <= a);
    EXPECT_TRUE(a <= b);
}

TEST(OperatorOverloading, GreaterOrEqual) {
    const CRational a(1, 2);
    const CRational b(1, 2);
    const CRational c(1, 3);
    EXPECT_TRUE(a >= c);
    EXPECT_TRUE(a >= b);
}

// I/O operators
TEST(OperatorOverloading, OutputStream) {
	const CRational a(3, 4);
    std::ostringstream oss;
    oss << a;
    EXPECT_EQ(oss.str(), "3/4");
}

TEST(OperatorOverloading, InputStream) {
    CRational a;
    std::istringstream iss("5/6");
    iss >> a;
    EXPECT_EQ(a, CRational(5, 6));
}

TEST(ToCompoundFraction, ZeroWholePart)
{
	const CRational r(3, 4);
    auto [whole, fraction] = r.ToCompoundFraction();

    EXPECT_EQ(whole, 0);
    EXPECT_EQ(fraction, CRational(3, 4));
}

TEST(ToCompoundFraction, PositiveMixed)
{
	const CRational r(9, 4);
    auto [whole, fraction] = r.ToCompoundFraction();

    EXPECT_EQ(whole, 2);
    EXPECT_EQ(fraction, CRational(1, 4));
}

TEST(ToCompoundFraction, NegativeMixed)
{
	const CRational r(-7, 4);
    auto [whole, fraction] = r.ToCompoundFraction();

    EXPECT_EQ(whole, -1);
    EXPECT_EQ(fraction, CRational(-3, 4));
}

TEST(ToCompoundFraction, ZeroFractionalPart)
{
	const CRational r(6, 3);
    auto [whole, fraction] = r.ToCompoundFraction();

    EXPECT_EQ(whole, 2);
    EXPECT_EQ(fraction, CRational(0, 1));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}