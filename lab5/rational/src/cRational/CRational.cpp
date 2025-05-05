//
// Created by smmm on 06.05.2025.
//

#include "CRational.h"

CRational::CRational(const int value)
	: m_numerator(value)
{
}

CRational::CRational(const int numerator, const int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
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