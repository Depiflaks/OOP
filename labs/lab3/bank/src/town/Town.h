//
// Created by smmm on 20.03.2025.
//

#ifndef TOWN_H
#define TOWN_H

#include "../bank/Bank.h"
#include "../random/random.h"
#include "citizenRegistry/CitizenRegistry.h"

#include <format>
#include <sstream>

class CitizenRegistry;

static constexpr Money k_minExpenseAmount{ 1 };
static constexpr Money k_maxExpenseAmount{ 100 };

inline Money GetRandomExpenseAmount()
{
	return GetRandomNumber(k_minExpenseAmount, k_maxExpenseAmount);
}

class EconomicIntegrityException : public std::runtime_error
{
public:
	using runtime_error::runtime_error;
	~EconomicIntegrityException() override = default;
};

class CashImbalanceException final : public EconomicIntegrityException
{
public:
	explicit CashImbalanceException(const Money& expected, const Money& fact)
		: EconomicIntegrityException([&] {
			std::ostringstream oss;
			oss << "Cash Imbalance: expected: " << expected << ", fact: " << fact;
			return oss.str();
		}())
	{
	}
};

class AccountImbalanceException final : public EconomicIntegrityException
{
public:
	explicit AccountImbalanceException(const Money& expected, const Money& fact)
		: EconomicIntegrityException([&] {
			std::ostringstream oss;
			oss << "Deposit Money Imbalance: expected: " << expected << ", fact: " << fact;
			return oss.str();
		}())
	{
	}
};

class Town
{
public:
	explicit Town(Money startAmount);
	void ExecuteSimulation(size_t stepCount);

private:
	Money m_startAmount{ 0 };
	Bank m_bank;
	CitizenRegistry m_registry;

	void CheckTotalAmount();
};

#endif // TOWN_H
