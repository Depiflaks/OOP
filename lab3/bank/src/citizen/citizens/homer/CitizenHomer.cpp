//
// Created by smmm on 27.03.2025.
//

#include "CitizenHomer.h"

#include <iostream>

CitizenHomer::CitizenHomer(Bank& bank, CitizenMap& citizens, Money cash)
	: Actor(bank, cash)
	, m_citizens(citizens)
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

void CitizenHomer::TransferMoneyToMarge(Money amount)
{

}

void CitizenHomer::PayForElectricity(Money amount)
{
}

void CitizenHomer::GiveMoneyToChildren(Money bartAmount, Money lisaAmount)
{
}