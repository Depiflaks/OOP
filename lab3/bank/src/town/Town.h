//
// Created by smmm on 20.03.2025.
//

#ifndef TOWN_H
#define TOWN_H
#include "../bank/Bank.h"
#include "../citizen/description/map/CitizensData.h"

#include <vector>

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
	void InitializeTheSpendingPlan();

private:
	Money m_startAmount{ 0 };
	CitizensData m_citizens;
	Bank m_bank;
	std::vector<CitizenName> m_citizenOrder{
		CitizenName::homerSimpson,
		CitizenName::margeSimpson,
		CitizenName::bartAndLisaSimpson,
		CitizenName::apu,
		CitizenName::mrBurns,
		CitizenName::nelson,
		CitizenName::snake,
		CitizenName::waylonSmithers,
	};

	static static void ExecuteSimulationStep(const std::unique_ptr<ICitizen>& citizen);
	void CheckTotalAmount();
};

#endif // TOWN_H
