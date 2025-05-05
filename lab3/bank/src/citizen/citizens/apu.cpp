//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

#include <Town.h>

CitizenApu::CitizenApu(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::apu, contacts)
{
	OpenAccount();
	DepositMoney(cash);

	AddAction([this] { PayForElectricity(); });
	AddAction([this] { DepositCashMoney(); });
}

void CitizenApu::PayForElectricity() const
{
	LogAboutPerformingAction("paying for electricity");

	IContactList& contactList = GetContactList();
	const Money amountToElectricity = GetRandomExpenseAmount();
	const auto mrBurns = contactList.GetCitizen(CitizenName::mrBurns);
	TransferMoney(mrBurns, amountToElectricity);
}

void CitizenApu::DepositCashMoney()
{
	LogAboutPerformingAction("depositing cash money");
	if (const Money cash = GetCashBalance(); cash > 0)
		DepositMoney(cash);
}

