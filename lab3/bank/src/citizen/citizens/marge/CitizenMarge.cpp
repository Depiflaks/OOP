//
// Created by smmm on 27.03.2025.
//

#include "CitizenMarge.h"

#include <iostream>

CitizenMarge::CitizenMarge(Bank& bank, ContactList& citizens, const Money cash)
	: Actor(bank, cash)
	, CitizenDescription(CitizenName::margeSimpson, citizens)
{
	OpenAccount();
	DepositMoney(cash);
}

void CitizenMarge::ExecuteWithErrorHandling()
{
	std::cout << "Executing " << getName(m_name) << " scenario\n";
	Citizen::ExecuteWithErrorHandling();
}

void CitizenMarge::PlanExpenses()
{
}

void CitizenMarge::PlanExpenses(const Money apuAmount)
{
	m_amountToApu = apuAmount;
}

void CitizenMarge::Execute()
{
	BuyGroceriesFromApu();
}

void CitizenMarge::BuyGroceriesFromApu() const
{
	const auto apu = FindCitizen(CitizenName::apu);
	TransferMoney(apu, m_amountToApu);
}