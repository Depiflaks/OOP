//
// Created by smmm on 29.05.2025.
//

#ifndef RADIXCONVERSIONDATA_H
#define RADIXCONVERSIONDATA_H
#include <stdexcept>
#include <string>

class RadixConversionData
{
public:
	RadixConversionData(int sourceRadix, int destRadix, const std::string& value)
	{
		SetSourceRadix(sourceRadix);
		SetDestRadix(destRadix);
		SetOriginalValue(value);
	}

	[[nodiscard]] int GetSourceRadix() const { return m_sourceRadix; }
	[[nodiscard]] int GetDestRadix() const { return m_destRadix; }
	[[nodiscard]] std::string GetOriginalValue() const { return m_originalValue; }
	[[nodiscard]] int GetDecimalValue() const { return m_decimalValue; }
	[[nodiscard]] int GetStartChar() const { return m_startChar; }
	[[nodiscard]] bool IsNegative() const { return m_isNegative; }

	void SetSourceRadix(int radix)
	{
		CheckRadixRange(radix);
		m_sourceRadix = radix;
	}

	void SetDestRadix(int radix)
	{
		CheckRadixRange(radix);
		m_destRadix = radix;
	}

	void SetOriginalValue(const std::string& value)
	{
		CheckNotEmpty(value);
		CheckHaveDigitAfterSign(value);
		m_originalValue = value;
		m_isNegative = IsOriginalValueNegative(value);
		m_startChar = value[0] == '+' || value[0] == '-';
	}

	void SetDecimalValue(const int value) { m_decimalValue = value; }

private:
	int m_sourceRadix{};
	int m_destRadix{};
	std::string m_originalValue{};
	int m_decimalValue{};
	bool m_isNegative{ false };
	int m_startChar{ 0 };

	static bool IsOriginalValueNegative(const std::string& value)
	{
		return value[0] == '-';
	}

	static void CheckRadixRange(int radix)
	{
		if (radix < 2 || radix > 36)
			throw std::invalid_argument("Invalid radix");
	}

	static void CheckNotEmpty(const std::string& value)
	{
		if (value.empty())
			throw std::invalid_argument("Empty string");
	}

	static void CheckHaveDigitAfterSign(const std::string& value)
	{
		if ((value[0] == '-' || value[0] == '+') && value.size() == 1)
			throw std::invalid_argument("Missing digits after sign");
	}
};

#endif //RADIXCONVERSIONDATA_H
