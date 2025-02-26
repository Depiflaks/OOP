//
// Created by smmm on 20.03.2025.
//

#ifndef TOWN_H
#define TOWN_H
#include "../bank/Bank.h"

class Town
{
public:
	explicit Town(Money startAmount);
	void ExecuteSimulation(int stepCount);

private:
	Money m_startAmount{ 0 };

	void ExecuteSimulationStep();
};

#endif // TOWN_H
