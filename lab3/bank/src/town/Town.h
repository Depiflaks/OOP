//
// Created by smmm on 20.03.2025.
//

#ifndef TOWN_H
#define TOWN_H

#include "../bank/Bank.h"
#include "citizenRegistry/CitizenRegistry.h"

class EconomicIntegrityException final : public std::runtime_error
{
public:
	explicit EconomicIntegrityException()
		: std::runtime_error{ "error: economic integrity is compromised" }
	{
	}
};

class Town
{
public:
	explicit Town(Money startAmount);
	void ExecuteSimulation(size_t stepCount);
	static Money GetRandomExpenseAmount();

private:
	Money m_startAmount{ 0 };
	Bank m_bank;
	CitizenRegistry m_registry;

	void CheckTotalAmount();
	static constexpr Money k_minExpenseAmount{ 1 };
	static constexpr Money k_maxExpenseAmount{ 1 };
};

#endif // TOWN_H
