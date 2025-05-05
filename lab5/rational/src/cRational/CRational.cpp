//
// Created by smmm on 06.05.2025.
//

#include "CRational.h"

#include <iostream>
#include <numeric>
#include <ostream>

CRational::CRational(const int value)
	: m_numerator(value)
{
}

CRational::CRational(const int numerator, const int denominator)
	: m_numerator(numerator)
{
	m_denominator = denominator;
	ProcessDenominator();
	Normalize();
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

std::pair<int, CRational> CRational::ToCompoundFraction() const
{
	int wholePart = m_numerator / m_denominator;
	const int remainder = m_numerator % m_denominator;
	CRational fractionalPart(remainder, m_denominator);
	return { wholePart, fractionalPart };
}

CRational CRational::operator+() const
{
	return *this;
}

CRational CRational::operator-() const
{
	return { -m_numerator, m_denominator };
}

CRational CRational::operator+(const CRational& other) const
{
	const int denominator = GetCommonDenominator(*this, other);
	const int newNum = ToCommonDenominator(denominator) + other.ToCommonDenominator(denominator);
	return { newNum, denominator };
}

CRational& CRational::operator+=(const CRational& other)
{
	*this = *this + other;
	return *this;
}

CRational CRational::operator-(const CRational& other) const
{
	const int denominator = GetCommonDenominator(*this, other);
	const int newNum = ToCommonDenominator(denominator) - other.ToCommonDenominator(denominator);
	return { newNum, denominator };
}

CRational& CRational::operator-=(const CRational& other)
{
	*this = *this - other;
	return *this;
}

bool CRational::operator==(const CRational& other) const
{
	const int denominator = GetCommonDenominator(*this, other);
	return ToCommonDenominator(denominator) == other.ToCommonDenominator(denominator);
}

bool CRational::operator!=(const CRational& other) const
{
	return !(*this == other);
}

bool CRational::operator<(const CRational& other) const
{
	const int denominator = GetCommonDenominator(*this, other);
	return ToCommonDenominator(denominator) < other.ToCommonDenominator(denominator);
}

bool CRational::operator>(const CRational& other) const
{
	const int denominator = GetCommonDenominator(*this, other);
	return ToCommonDenominator(denominator) > other.ToCommonDenominator(denominator);
}

bool CRational::operator<=(const CRational& other) const { return !(*this > other); }
bool CRational::operator>=(const CRational& other) const { return !(*this < other); }

CRational CRational::operator*(const CRational& other) const
{
	return { m_numerator * other.m_numerator, m_denominator * other.m_denominator };
}

CRational& CRational::operator*=(const CRational& other)
{
	*this = *this * other;
	return *this;
}

CRational CRational::operator/(const CRational& other) const
{
	return { m_numerator * other.m_denominator, m_denominator * other.m_numerator };
}

CRational& CRational::operator/=(const CRational& other)
{
	*this = *this / other;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const CRational& rational)
{
	os << rational.m_numerator << "/" << rational.m_denominator;
	return os;
}

std::istream& operator>>(std::istream& in, CRational& value)
{
	int numerator = 0;
	int denominator = 1;
	char slash = 0;

	in >> std::ws >> numerator >> std::ws >> slash;

	if (slash != '/')
	{
		in.setstate(std::ios::failbit);
		return in;
	}
	in >> std::ws >> denominator;
	value = CRational(numerator, denominator);
	return in;
}

void CRational::ProcessDenominator()
{
	if (m_denominator == 0)
	{
		m_denominator = 1;
		throw ZeroDenominatorException();
	}
	if (m_denominator < 0)
	{
		m_denominator *= -1;
		m_numerator *= -1;
	}
}

int CRational::ToCommonDenominator(const int commonDenominator) const
{
	return m_numerator * (commonDenominator / m_denominator);
}

void CRational::Normalize()
{
	const int gcd = std::gcd(m_numerator, m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

int CRational::GetCommonDenominator(const CRational& a, const CRational& b)
{
	const int commonDenominator = std::lcm(a.m_denominator, b.m_denominator);
	return commonDenominator;
}
