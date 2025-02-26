//
// Created by smmm on 27.03.2025.
//

#include "CitizenSmithers.h"

#include "../mrBurns/CitizenMrBurns.h"

#include <iostream>

CitizenSmithers::CitizenSmithers(Bank& bank, CitizenMap& citizens, const Money cash)
	: Actor(bank, cash)
	, CitizenDescription(CitizenName::waylonSmithers, citizens)
{
	OpenAccount();
	DepositMoney(cash);
}

void CitizenSmithers::ExecuteWithErrorHandling()
{
	std::cout << "Executing " << getName(m_name) << " scenario\n";
	ICitizen::ExecuteWithErrorHandling();
}

void CitizenSmithers::PlanExpenses()
{
}

void CitizenSmithers::PlanExpenses(const Money abuAmount, const bool shouldNotifyingBoss)
{
	m_amountToAbu = abuAmount;
	m_shouldNotifyingBoss = shouldNotifyingBoss;
}

void CitizenSmithers::Execute()
{
	ChangeAccount();
	BuyGroceries();
}

void CitizenSmithers::ChangeAccount()
{
	CloseAccount();
	OpenAccount();
}

void CitizenSmithers::BuyGroceries() const
{
	const auto apu = FindCitizen(CitizenName::apu);
	TransferMoney(apu, m_amountToAbu);
}