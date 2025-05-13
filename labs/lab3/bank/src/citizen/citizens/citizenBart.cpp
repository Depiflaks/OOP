//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

#include <Town.h>

CitizenBart::CitizenBart(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::bartSimpson, contacts)
{
	AddAction([this] { BuyCandyFromApu(); });
}

void CitizenBart::BuyCandyFromApu()
{
	LogAboutPerformingAction("buying candy from Apu");

	IContactList& contactList = GetContactList();
	const Money amountToCandy = GetRandomExpenseAmount();
	auto apu = contactList.GetCitizen(CitizenName::apu);
	HandOverMoney(apu, amountToCandy);
}