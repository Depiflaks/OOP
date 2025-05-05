//
// Created by smmm on 06.05.2025.
//

#ifndef CRATIONAL_H
#define CRATIONAL_H
#include <exception>
#include <numeric>
#include <stdexcept>

class ZeroDenominatorException final : public std::invalid_argument
{
public:
	ZeroDenominatorException()
		: std::invalid_argument("denominator cannot be zero")
	{
	}
};

class CRational
{
public:
	// Конструирует рациональное число, равное нулю (0/1)
	CRational() = default;

	// Конструирует рациональное число, равное value (value/1)
	explicit CRational(int value);

	// Конструирует рациональное число, равное numerator/denominator
	// Рациональное число должно храниться в нормализованном виде:
	// знаменатель положительный (числитель может быть отрицательным)
	// числитель и знаменатель не имеют общих делителей (6/8 => 3/4 и т.п.)
	// Если знаменатель равен нулю, должно конструироваться рациональное число, равное нулю,
	// либо должно быть выброшено исключение std::invalid_argument.
	CRational(int numerator, int denominator);

	// Возвращает числитель
	[[nodiscard]] int GetNumerator() const;

	// Возвращает знаменатель (натуральное число)
	[[nodiscard]] int GetDenominator() const;

	// Возвращает отношение числителя и знаменателя в виде числа double
	[[nodiscard]] double ToDouble() const;
	[[nodiscard]] std::pair<int, CRational> ToCompoundFraction() const;

	CRational operator+() const;
	CRational operator-() const;
	CRational operator+(const CRational& other) const;
	CRational& operator+=(const CRational& other);
	CRational operator-(const CRational& other) const;
	CRational& operator-=(const CRational& other);

	CRational operator*(const CRational& other) const;
	CRational& operator*=(const CRational& other);
	CRational operator/(const CRational& other) const;
	CRational& operator/=(const CRational& other);

	bool operator>(const CRational& other) const;
	bool operator<(const CRational& other) const;
	bool operator<=(const CRational& other) const;
	bool operator>=(const CRational& other) const;
	bool operator==(const CRational& other) const;
	bool operator!=(const CRational& other) const;

	friend std::ostream& operator<<(std::ostream& os, const CRational& rational);
	friend std::istream& operator>>(std::istream& in, CRational& value);

private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

	void ProcessDenominator();
	void Normalize();
	[[nodiscard]] int ToCommonDenominator(int commonDenominator) const;

	static int GetCommonDenominator(const CRational& a, const CRational& b);
};

#endif // CRATIONAL_H
