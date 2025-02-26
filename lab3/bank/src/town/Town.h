//
// Created by smmm on 20.03.2025.
//

#ifndef TOWN_H
#define TOWN_H
#include "../bank/Bank.h"
#include "../citizen/description/map/citizenMap.h"

#include <vector>

class Town
{
public:
	explicit Town(Money startAmount);
	void ExecuteSimulation(int stepCount);
	void InitializingTheSpendingPlan();

private:
	Money m_startAmount{ 0 };
	CitizenMap m_citizens;
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

	void ExecuteSimulationStep();
	void CheckTotalAmount();
};

#endif // TOWN_H
