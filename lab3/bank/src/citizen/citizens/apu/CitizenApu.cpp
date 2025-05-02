//
// Created by smmm on 27.03.2025.
//

#include "CitizenApu.h"

#include <iostream>

CitizenApu::CitizenApu(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::apu, contacts)
{
	OpenAccount();
	DepositMoney(cash);
}


void CitizenApu::PerformRandomAction()
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
