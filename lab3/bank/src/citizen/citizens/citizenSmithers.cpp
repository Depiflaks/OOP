//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

#include <Town.h>

CitizenSmithers::CitizenSmithers(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::waylonSmithers, contacts)
{
	OpenAccount();
	DepositMoney(cash);

	AddAction([this] { BuyGroceries(); });
	AddAction([this] { ChangeAccount(); });
}

void CitizenSmithers::BuyGroceries() const
{
	LogAboutPerformingAction("buying groceries");
	IContactList& contactList = GetContactList();

	const auto apu = contactList.GetCitizen(CitizenName::apu);
	const Money amountForGroceries = GetRandomExpenseAmount();

	TransferMoney(apu, amountForGroceries);
}

void CitizenSmithers::ChangeAccount()
{
	LogAboutPerformingAction("changing account");
	CloseAccount();
	OpenAccount();
}