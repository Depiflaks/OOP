//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

#include <Town.h>

CitizenMrBurns::CitizenMrBurns(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::mrBurns, contacts)
{
	OpenAccount();
	DepositMoney(cash);

	AddAction([this] { GiveSalaryToHomer(); });
	AddAction([this] { GiveSalaryToSmithers(); });
}

void CitizenMrBurns::GiveSalaryToHomer() const
{
	LogAboutPerformingAction("giving salary to Homer");
	IContactList& contactList = GetContactList();
	const auto homer = contactList.GetCitizen(CitizenName::homerSimpson);
	const Money amountToSalary = GetRandomExpenseAmount();

	TransferMoney(homer, amountToSalary);
}

void CitizenMrBurns::GiveSalaryToSmithers() const
{
	LogAboutPerformingAction("giving salary to Smithers");
	IContactList& contactList = GetContactList();
	const auto smithers = contactList.GetCitizen(CitizenName::waylonSmithers);
	const Money amountToSalary = GetRandomExpenseAmount();

	TransferMoney(smithers, amountToSalary);
}