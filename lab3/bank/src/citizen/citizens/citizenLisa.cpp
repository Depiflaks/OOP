//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

CitizenLisa::CitizenLisa(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::lisaSimpson, contacts)
{
	OpenAccount();
	DepositMoney(cash);

	AddAction([this] { BuyCandyFromApu(); });
}

void CitizenLisa::BuyCandyFromApu()
{
	LogAboutPerformingAction("buying candy from Apu");
	IContactList& contactList = GetContactList();
}