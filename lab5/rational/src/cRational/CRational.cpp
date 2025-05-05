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
