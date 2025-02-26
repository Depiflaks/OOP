//
// Created by smmm on 27.03.2025.
//

#include "CitizenApu.h"

#include <iostream>

CitizenApu::CitizenApu(Bank& bank, CitizenMap& citizens, const Money cash)
	: Actor(bank, cash)
	, CitizenDescription(CitizenName::apu, citizens)
{
	OpenAccount();
}

void CitizenApu::ExecuteWithErrorHandling()
{
	std::cout << "Executing " << getName(m_name) << " scenario\n";
	ICitizen::ExecuteWithErrorHandling();
}

void CitizenApu::PlanExpenses()
{
}

void CitizenApu::PlanExpenses(const Money electricityAmount)
{
	m_amountToElectricity = electricityAmount;
}

void CitizenApu::Execute()
{
	PayForElectricity();
}

void CitizenApu::PayForElectricity() const
{
	const auto mrBurns = FindCitizen(CitizenName::mrBurns);
	TransferMoney(mrBurns, m_amountToElectricity);
}

void CitizenApu::DepositCashMoney()
{
	if (const Money cash = GetCashBalance(); cash > 0)
		DepositMoney(cash);
}
