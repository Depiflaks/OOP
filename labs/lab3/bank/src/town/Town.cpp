//
// Created by smmm on 20.03.2025.
//

#include "Town.h"

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
		Citizen& citizen = m_registry.GetRandomCitizen();
		citizen.PerformRandomActionWithErrorHandling();
		CheckTotalAmount();
	}
}

void Town::CheckTotalAmount()
{
	const Money bankCashAmount{ m_bank.GetCash() };
	Money citizensCashAmount{ 0 };
	Money citizenAccountAmount{ 0 };

	for (const auto& [name, citizen] : m_registry.GetCitizens())
	{
		citizensCashAmount += citizen->GetCashBalance();
		if (citizen->GetAccountId() != std::nullopt)
			citizenAccountAmount += citizen->GetAccountBalance();
	}
	if (bankCashAmount != citizensCashAmount)
		throw CashImbalanceException(bankCashAmount, citizensCashAmount);
	if (m_startAmount - citizensCashAmount != citizenAccountAmount)
		throw AccountImbalanceException(m_startAmount - citizensCashAmount, citizenAccountAmount);
}