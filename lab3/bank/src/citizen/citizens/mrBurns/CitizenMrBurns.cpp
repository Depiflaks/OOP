//
// Created by smmm on 27.03.2025.
//

#include "CitizenMrBurns.h"

#include <iostream>

CitizenMrBurns::CitizenMrBurns(Bank& bank, CitizenMap& citizens, const Money cash)
	: Actor(bank, cash)
	, CitizenDescription(CitizenName::mrBurns, citizens)
{
	OpenAccount();
}

void CitizenMrBurns::ExecuteWithErrorHandling()
{
	std::cout << "Executing " << getName(m_name) << " scenario\n";
	ICitizen::ExecuteWithErrorHandling();
}

void CitizenMrBurns::PlanExpenses()
{
}

void CitizenMrBurns::PlanExpenses(const Money homerAmount, const Money smithersAmount)
{
	m_amountToHomer = homerAmount;
	m_amountToSmithers = smithersAmount;
}

void CitizenMrBurns::ChangeSmithersAccount(const AccountId newSmithersId)
{
	m_smithersId = newSmithersId;
}

void CitizenMrBurns::Execute()
{
	GiveSalaryToHomer();
}

void CitizenMrBurns::GiveSalaryToHomer() const
{
	const auto homer = FindCitizen(CitizenName::homerSimpson);
	TransferMoney(homer, m_amountToHomer);
}

void CitizenMrBurns::GiveSalaryToSmithers() const
{
	const auto smithers = FindCitizen(CitizenName::waylonSmithers);
	TransferMoney(smithers, m_amountToHomer);
}
