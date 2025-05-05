//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

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
}

void CitizenSnake::BuyGroceriesFromApu() const
{
	LogAboutPerformingAction("buying groceries from Apu");
	IContactList& contactList = GetContactList();
}