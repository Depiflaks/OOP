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
	RadixConversionData(int sourceRadix, int destRadix, const std::string& value);

	[[nodiscard]] int GetSourceRadix() const;
	[[nodiscard]] int GetDestRadix() const;
	[[nodiscard]] std::string GetOriginalValue() const;
	[[nodiscard]] int GetDecimalValue() const;
	[[nodiscard]] int GetStartChar() const;
	[[nodiscard]] bool IsNegative() const;

	void SetSourceRadix(int radix);

	void SetDestRadix(int radix);

	void SetOriginalValue(const std::string& value);

	void SetDecimalValue(const int value);

private:
	int m_sourceRadix{};
	int m_destRadix{};
	std::string m_originalValue{};
	int m_decimalValue{};
	bool m_isNegative{ false };
	int m_startChar{ 0 };

	static bool IsOriginalValueNegative(const std::string& value);

	static void CheckRadixRange(int radix);

	static void CheckNotEmpty(const std::string& value);

	static void CheckHaveDigitAfterSign(const std::string& value);
};

#endif // RADIXCONVERSIONDATA_H
