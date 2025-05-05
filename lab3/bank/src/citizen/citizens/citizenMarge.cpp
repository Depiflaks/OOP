//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

#include <Town.h>

CitizenMarge::CitizenMarge(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::margeSimpson, contacts)
{
	OpenAccount();
	DepositMoney(cash);

	AddAction([this] { BuyGroceriesFromApu(); });
}

void CitizenMarge::BuyGroceriesFromApu() const
{
	LogAboutPerformingAction("buying groceries from Apu");
	IContactList& contactList = GetContactList();
	const auto apu = contactList.GetCitizen(CitizenName::apu);
	const Money amountToGroceries = GetRandomExpenseAmount();

	TransferMoney(apu, amountToGroceries);
}
