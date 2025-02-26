//
// Created by smmm on 27.03.2025.
//

#include "CitizenSnake.h"

#include <iostream>

CitizenSnake::CitizenSnake(Bank& bank, CitizensData& citizens, const Money cash)
	: Actor(bank, cash)
	, CitizenDescription(CitizenName::snake, citizens)
{
	OpenAccount();
	DepositMoney(cash);
}

void CitizenSnake::ExecuteWithErrorHandling()
{
	std::cout << "Executing " << getName(m_name) << " scenario\n";
	ICitizen::ExecuteWithErrorHandling();
}

void CitizenSnake::PlanExpenses()
{
}

void CitizenSnake::PlanExpenses(const Money hackedAmount, const Money apuAmount)
{
	m_hackedAmount = hackedAmount;
	m_apuAmount = apuAmount;
}

void CitizenSnake::Execute()
{
	HackHomerAccount();
	BuyGroceriesFromApu();
}

void CitizenSnake::HackHomerAccount() const
{
	const auto homer = FindCitizen(CitizenName::homerSimpson);
	homer.TransferMoney(*this, m_hackedAmount);
}

void CitizenSnake::BuyGroceriesFromApu() const
{
	const auto apu = FindCitizen(CitizenName::apu);
	TransferMoney(apu, m_hackedAmount);
}