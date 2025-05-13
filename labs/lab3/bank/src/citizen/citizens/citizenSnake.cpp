//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

#include <Town.h>

CitizenSnake::CitizenSnake(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::snake, contacts)
{
	OpenAccount();
	DepositMoney(cash);

	AddAction([this] { HackHomerAccount(); });
	AddAction([this] { BuyGroceriesFromApu(); });
}

void CitizenSnake::HackHomerAccount() const
{
	LogAboutPerformingAction("hacking Homer's account");
	IContactList& contactList = GetContactList();
	const auto homer = contactList.GetCitizen(CitizenName::homerSimpson);
	const Money hackAmount = GetRandomExpenseAmount();

	homer.TransferMoney(*this, hackAmount);
}

void CitizenSnake::BuyGroceriesFromApu() const
{
	LogAboutPerformingAction("buying groceries from Apu");
	IContactList& contactList = GetContactList();

	const auto apu = contactList.GetCitizen(CitizenName::apu);
	const Money amountForGroceries = GetRandomExpenseAmount();

	TransferMoney(apu, amountForGroceries);
}