//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

CitizenBart::CitizenBart(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::bartSimpson, contacts)
{
	OpenAccount();
	DepositMoney(cash);

	AddAction([this] { BuyCandyFromApu(); });
}

void CitizenBart::BuyCandyFromApu()
{
	LogAboutPerformingAction("buying candy from Apu");
	IContactList& contactList = GetContactList();
}