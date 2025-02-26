//
// Created by smmm on 27.03.2025.
//

#include "CitizenNelson.h"

#include <iostream>
#include <random>

CitizenNelson::CitizenNelson(Bank& bank, CitizensData& citizens, const Money cash)
	: Actor(bank, cash)
	, CitizenDescription(CitizenName::nelson, citizens)
{
}

void CitizenNelson::ExecuteWithErrorHandling()
{
	std::cout << "Executing " << getName(m_name) << " scenario\n";
	ICitizen::ExecuteWithErrorHandling();
}

void CitizenNelson::PlanExpenses()
{
}

void CitizenNelson::PlanExpenses(const Money stolenAmount)
{
	m_stolenAmount = stolenAmount;
}

void CitizenNelson::Execute()
{
	StealFromBart();
	BuyCigarettesFromApu();
}

void CitizenNelson::StealFromBart()
{
	auto bart = FindCitizen(CitizenName::bartAndLisaSimpson);
	ExtortMoney(bart, m_stolenAmount);
}

void CitizenNelson::BuyCigarettesFromApu()
{
	auto apu = FindCitizen(CitizenName::apu);
	HandOverMoney(apu, m_stolenAmount);
}