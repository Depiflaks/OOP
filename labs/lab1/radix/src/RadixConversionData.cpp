//
// Created by smmm on 29.05.2025.
//

#include "RadixConversionData.h"

RadixConversionData::RadixConversionData(int sourceRadix, int destRadix, const std::string& value)
{
	SetSourceRadix(sourceRadix);
	SetDestRadix(destRadix);
	SetOriginalValue(value);
}

int RadixConversionData::GetSourceRadix() const { return m_sourceRadix; }

int RadixConversionData::GetDestRadix() const { return m_destRadix; }

std::string RadixConversionData::GetOriginalValue() const { return m_originalValue; }

int RadixConversionData::GetDecimalValue() const { return m_decimalValue; }

int RadixConversionData::GetStartChar() const { return m_startChar; }

bool RadixConversionData::IsNegative() const { return m_isNegative; }

void RadixConversionData::SetSourceRadix(int radix)
{
	CheckRadixRange(radix);
	m_sourceRadix = radix;
}

void RadixConversionData::SetDestRadix(int radix)
{
	CheckRadixRange(radix);
	m_destRadix = radix;
}

void RadixConversionData::SetOriginalValue(const std::string& value)
{
	CheckNotEmpty(value);
	CheckHaveDigitAfterSign(value);
	m_originalValue = value;
	m_isNegative = IsOriginalValueNegative(value);
	m_startChar = value[0] == '+' || value[0] == '-';
}

void RadixConversionData::SetDecimalValue(const int value) { m_decimalValue = value; }

bool RadixConversionData::IsOriginalValueNegative(const std::string& value)
{
	return value[0] == '-';
}

void RadixConversionData::CheckRadixRange(int radix)
{
	if (radix < 2 || radix > 36)
		throw std::invalid_argument("Invalid radix");
}

void RadixConversionData::CheckNotEmpty(const std::string& value)
{
	if (value.empty())
		throw std::invalid_argument("Empty string");
}

void RadixConversionData::CheckHaveDigitAfterSign(const std::string& value)
{
	if ((value[0] == '-' || value[0] == '+') && value.size() == 1)
		throw std::invalid_argument("Missing digits after sign");
}
