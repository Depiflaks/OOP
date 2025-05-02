//
// Created by smmm on 27.03.2025.
//

#include "CitizenBartAndLisa.h"

#include <iostream>

CitizenBartAndLisa::CitizenBartAndLisa(Bank& bank, IContactList& citizens, const Money cash)
	: Actor(bank, cash)
	, CitizenDescription(CitizenName::bartSimpson, citizens)
{
}

void CitizenBartAndLisa::ExecuteWithErrorHandling()
{
	std::cout << "Executing " << getName(m_name) << " scenario\n";
	Citizen::PerformRandomActionWithErrorHandling();
}

void CitizenBartAndLisa::PlanExpenses()
{
}

void CitizenBartAndLisa::PlanExpenses(
	const Money apuAmountFromBart,
	const Money apuAmountFromLisa)
{
	m_amountToApuFromBart = apuAmountFromBart;
	m_amountToApuFromLisa = apuAmountFromLisa;
}

void CitizenBartAndLisa::PerformRandomAction()
{
	BuyCandyFromApu();
}

void CitizenBartAndLisa::BuyCandyFromApu()
{
	Actor apu = FindCitizen(CitizenName::apu);
	HandOverMoney(apu, m_amountToApuFromBart);
	HandOverMoney(apu, m_amountToApuFromLisa);
}
