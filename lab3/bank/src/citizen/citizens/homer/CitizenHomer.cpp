//
// Created by smmm on 27.03.2025.
//

#include "CitizenHomer.h"

#include <iostream>

CitizenHomer::CitizenHomer(Bank& bank, CitizenMap& citizens, const Money cash)
	: Actor(bank, cash)
	, CitizenDescription(CitizenName::homerSimpson, citizens)
{
}

void CitizenHomer::ExecuteWithErrorHandling()
{
	std::cout << "Executing " << getName(m_name) << " scenario\n";
	ICitizen::ExecuteWithErrorHandling();
}

void CitizenHomer::Execute()
{
	TransferMoneyToMarge(50);
	PayForElectricity(10);
	GiveMoneyToChildren(5, 5);
}

void CitizenHomer::TransferMoneyToMarge(const Money amount) const
{
	const Actor marge = FindCitizen(CitizenName::margeSimpson);
	TransferMoney(marge, amount);
}

void CitizenHomer::PayForElectricity(Money amount) const
{
	const Actor mrBurns = FindCitizen(CitizenName::mrBurns);
	TransferMoney(mrBurns, amount);
}

void CitizenHomer::GiveMoneyToChildren(Money bartAmount, Money lisaAmount)
{
	Actor bart = FindCitizen(CitizenName::bartSimpson);
	Actor lisa = FindCitizen(CitizenName::lisaSimpson);
	WithdrawMoney(bartAmount + lisaAmount);
	HandOverMoney(bart, bartAmount);
	HandOverMoney(lisa, lisaAmount);
}