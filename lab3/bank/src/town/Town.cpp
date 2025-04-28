//
// Created by smmm on 20.03.2025.
//

#include "Town.h"

#include "../citizen/citizens/apu/CitizenApu.h"
#include "../citizen/citizens/bartAndLisa/CitizenBartAndLisa.h"
#include "../citizen/citizens/homer/CitizenHomer.h"
#include "../citizen/citizens/marge/CitizenMarge.h"
#include "../citizen/citizens/mrBurns/CitizenMrBurns.h"
#include "../citizen/citizens/nelson/CitizenNelson.h"
#include "../citizen/citizens/smithers/CitizenSmithers.h"
#include "../citizen/citizens/snake/CitizenSnake.h"

#include <iostream>

Town::Town(const Money startAmount)
	: m_startAmount(startAmount)
	, m_bank(Bank(startAmount))
{
	// поровну разделяем все деньги между владельцами
}

void Town::ExecuteSimulation(const size_t stepCount)
{
	int currentActorInd = 0;
	for (size_t step = 0; step < stepCount; ++step)
	{
		currentActorInd = step % m_citizenOrder.size();
		auto& currentActor = m_citizens[m_citizenOrder[currentActorInd]];
		std::cout << "Step: " << step << '\n';
		ExecuteSimulationStep(currentActor);
	}
}

void Town::InitializeTheSpendingPlan()
{
	m_citizens[CitizenName::homerSimpson]->PlanExpenses();
}

void Town::ExecuteSimulationStep(const std::unique_ptr<Citizen>& citizen)
{
	citizen->ExecuteWithErrorHandling();
}

void Town::CheckTotalAmount()
{
	Money cashAmount{ 0 };
	Money accountAmount{ 0 };

}