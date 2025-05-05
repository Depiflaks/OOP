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
#include "../random/random.h"

#include <iostream>

Town::Town(const Money startAmount)
	: m_startAmount(startAmount)
	, m_bank(Bank{ startAmount })
	, m_registry(m_bank)
{
}

void Town::ExecuteSimulation(const size_t stepCount)
{
	for (size_t step = 0; step < stepCount; ++step)
	{
		ICitizen& citizen = m_registry.GetRandomCitizen();
		citizen.PerformRandomActionWithErrorHandling();
		CheckTotalAmount();
	}
}

void Town::CheckTotalAmount()
{
	const Money bankCashAmount{ m_bank.GetCash() };
	Money citizensCashAmount{ 0 };
	Money citizenAccountAmount{ 0 };

	for (auto citizen : m_registry.GetCitizens())
	{
		citizensCashAmount += citizen.second->GetCashBalance();
		if (citizen.second->GetAccountId() != std::nullopt)
			citizenAccountAmount += citizen.second->GetAccountBalance();
	}
	if (bankCashAmount != citizensCashAmount)
		throw EconomicIntegrityException();
	if (m_startAmount - citizensCashAmount != citizenAccountAmount)
		throw EconomicIntegrityException();
}