//
// Created by smmm on 27.03.2025.
//

#include "CitizenMrBurns.h"

#include <iostream>

CitizenMrBurns::CitizenMrBurns(Bank& bank, CitizensData& citizens, const Money cash)
	: Actor(bank, cash)
	, CitizenDescription(CitizenName::mrBurns, citizens)
{
	OpenAccount();
	DepositMoney(cash);
}

void CitizenMrBurns::ExecuteWithErrorHandling()
{
	std::cout << "Executing " << getName(m_name) << " scenario\n";
	ICitizen::ExecuteWithErrorHandling();
}

void CitizenMrBurns::PlanExpenses()
{
}

void CitizenMrBurns::PlanExpenses(
	const Money homerAmount,
	const Money smithersAmount,
	const bool shouldUpdateSmithersId)
{
	m_amountToHomer = homerAmount;
	m_amountToSmithers = smithersAmount;
	m_shouldUpdateSmithersId = shouldUpdateSmithersId;
}

void CitizenMrBurns::Execute()
{
	GiveSalaryToHomer();
	if (m_shouldUpdateSmithersId)
		UpdateSmithersAccount();
	GiveSalaryToSmithers();
}

void CitizenMrBurns::GiveSalaryToHomer() const
{
	const auto homer = FindCitizen(CitizenName::homerSimpson);
	TransferMoney(homer, m_amountToHomer);
}

void CitizenMrBurns::UpdateSmithersAccount()
{
	const auto smithers = FindCitizen(CitizenName::waylonSmithers);
	m_smithersId = *smithers.GetAccountId();
}

void CitizenMrBurns::GiveSalaryToSmithers() const
{
	const auto smithers = FindCitizen(CitizenName::waylonSmithers);
	TransferMoney(smithers, m_amountToHomer);
}
