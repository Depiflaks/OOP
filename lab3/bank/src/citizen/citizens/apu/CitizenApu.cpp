//
// Created by smmm on 27.03.2025.
//

#include "CitizenApu.h"


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
	IContactList& contactList = GetContactList();
	const Money amountToElectricity = Town::GetRandomExpenseAmount();
	const auto mrBurns = contactList.GetCitizen(CitizenName::mrBurns);
	TransferMoney(mrBurns, amountToElectricity);
}

void CitizenApu::DepositCashMoney()
{
	if (const Money cash = GetCashBalance(); cash > 0)
		DepositMoney(cash);
}
