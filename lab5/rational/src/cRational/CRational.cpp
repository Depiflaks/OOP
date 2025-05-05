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
	CheckDenominator();
	m_denominator = denominator;
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
	const int newNum = m_numerator * (denominator / m_denominator) + other.m_numerator * (denominator / other.m_denominator);
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
	const int newNum = m_numerator * (denominator / m_denominator) - other.m_numerator * (denominator / other.m_denominator);
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
	return m_numerator * (denominator / m_denominator) == other.m_numerator * (denominator / other.m_denominator);
}

bool CRational::operator!=(const CRational& other) const { return !(*this == other); }

bool CRational::operator<(const CRational& other) const
{
	const int denominator = GetCommonDenominator(*this, other);
	return m_numerator * (denominator / m_denominator) < other.m_numerator * (denominator / other.m_denominator);
}

bool CRational::operator>(const CRational& other) const
{
	const int denominator = GetCommonDenominator(*this, other);
	return m_numerator * (denominator / m_denominator) > other.m_numerator * (denominator / other.m_denominator);
}

bool CRational::operator<=(const CRational& other) const { return !(*this > other); }
bool CRational::operator>=(const CRational& other) const { return !(*this < other); }

std::ostream& operator<<(std::ostream& os, const CRational& rational)
{
	os << rational.m_numerator << "/" << rational.m_denominator;
	return os;
}

void CRational::CheckDenominator() const
{
	if (m_denominator == 0)
		throw ZeroDenominatorException();
	if (m_denominator < 0)
		throw NegativeDenominatorException();
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
