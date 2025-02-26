//
// Created by smmm on 27.03.2025.
//

#include "CitizenHomer.h"

#include <iostream>

CitizenHomer::CitizenHomer(Bank& bank, CitizenMap& citizens, const Money cash)
	: Actor(bank, cash)
	, CitizenDescription(CitizenName::homerSimpson, citizens)
{
	OpenAccount();
	DepositMoney(cash);
}

void CitizenHomer::ExecuteWithErrorHandling()
{
	std::cout << "Executing " << getName(m_name) << " scenario\n";
	ICitizen::ExecuteWithErrorHandling();
}

void CitizenHomer::PlanExpenses()
{
}

void CitizenHomer::PlanExpenses(
	const Money margeAmount,
	const Money bartAmount,
	const Money lisaAmount,
	const Money electricityAmount)
{
	m_amountToMarge = margeAmount;
	m_amountForElectricity = electricityAmount;
	m_amountToBart = bartAmount;
	m_amountToLisa = lisaAmount;
}

void CitizenHomer::Execute()
{
	TransferMoneyToMarge();
	PayForElectricity();
	GiveMoneyToChildren();
}

void CitizenHomer::TransferMoneyToMarge() const
{
	const Actor marge = FindCitizen(CitizenName::margeSimpson);
	TransferMoney(marge, m_amountToMarge);
}

void CitizenHomer::PayForElectricity() const
{
	const Actor mrBurns = FindCitizen(CitizenName::mrBurns);
	TransferMoney(mrBurns, m_amountForElectricity);
}

void CitizenHomer::GiveMoneyToChildren()
{
	Actor bart = FindCitizen(CitizenName::bartSimpson);
	Actor lisa = FindCitizen(CitizenName::lisaSimpson);
	WithdrawMoney(m_amountToBart + m_amountToLisa);
	HandOverMoney(bart, m_amountToBart);
	HandOverMoney(lisa, m_amountToLisa);
}