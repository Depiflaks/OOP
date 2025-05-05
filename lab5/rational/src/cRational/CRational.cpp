//
// Created by smmm on 06.05.2025.
//

#include "CRational.h"

#include <numeric>

CRational::CRational(const int value)
	: m_numerator(value)
{
}

CRational::CRational(const int numerator, const int denominator)
	: m_numerator(numerator)
{
	CheckDenominator();
	m_denominator = denominator;
	Reduce();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
}

CRational CRational::operator+(const CRational& other) const
{
	auto [a, b] = ToCommonDenominator(*this, other);
	return { a.m_numerator + b.m_numerator, a.m_denominator };
}

CRational& CRational::operator+=(const CRational& other)
{
	*this = *this + other;
	return *this;
}

CRational CRational::operator-(const CRational& other) const
{
	auto [a, b] = ToCommonDenominator(*this, other);
	return { a.m_numerator - b.m_numerator, a.m_denominator };
}

CRational& CRational::operator-=(const CRational& other)
{
	*this = *this - other;
	return *this;
}

bool CRational::operator>(const CRational& other) const
{
	auto [a, b] = ToCommonDenominator(*this, other);
	return a.m_numerator > b.m_numerator;
}

bool CRational::operator<(const CRational& other) const
{
	auto [a, b] = ToCommonDenominator(*this, other);
	return a.m_numerator < b.m_numerator;
}

bool CRational::operator<=(const CRational& other) const
{
	return !(*this > other);
}

bool CRational::operator>=(const CRational& other) const
{
	return !(*this < other);
}

bool CRational::operator==(const CRational& other) const
{
	return m_numerator == other.m_numerator && m_denominator == other.m_denominator;
}

bool CRational::operator!=(const CRational& other) const
{
	return !(*this == other);
}

void CRational::CheckDenominator() const
{
	if (m_denominator == 0)
		throw ZeroDenominatorException();
	if (m_denominator < 0)
		throw NegativeDenominatorException();
}

void CRational::Reduce()
{
	const int gcd = std::gcd(m_numerator, m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

std::pair<CRational, CRational> CRational::ToCommonDenominator(const CRational& a, const CRational& b)
{
	const int commonDenominator = std::lcm(a.m_denominator, b.m_denominator);

	CRational aNormalized(
		a.m_numerator * (commonDenominator / a.m_denominator),
		commonDenominator);

	CRational bNormalized(
		b.m_numerator * (commonDenominator / b.m_denominator),
		commonDenominator);

	return { aNormalized, bNormalized };
}
