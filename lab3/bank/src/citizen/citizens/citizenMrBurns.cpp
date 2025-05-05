//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

CitizenMrBurns::CitizenMrBurns(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::mrBurns, contacts)
{
	OpenAccount();
	DepositMoney(cash);

	AddAction([this] { GiveSalaryToHomer(); });
	AddAction([this] { UpdateSmithersAccount(); });
	AddAction([this] { GiveSalaryToSmithers(); });
}

void CitizenMrBurns::GiveSalaryToHomer() const
{
	LogAboutPerformingAction("giving salary to Homer");
	IContactList& contactList = GetContactList();
}

void CitizenMrBurns::UpdateSmithersAccount()
{
	LogAboutPerformingAction("updating Smithers' account");
	IContactList& contactList = GetContactList();
}

void CitizenMrBurns::GiveSalaryToSmithers() const
{
	LogAboutPerformingAction("giving salary to Smithers");
	IContactList& contactList = GetContactList();
}