//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

CitizenSmithers::CitizenSmithers(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::smithers, contacts)
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
}

void CitizenSmithers::ChangeAccount()
{
	LogAboutPerformingAction("changing account");
	IContactList& contactList = GetContactList();
}