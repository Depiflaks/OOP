//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

#include <Town.h>

CitizenLisa::CitizenLisa(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::lisaSimpson, contacts)
{
	OpenAccount();
	DepositMoney(cash);

	AddAction([this] { BuyCandyFromApu(); });
}
void CitizenBart::BuyCandyFromApu()
{
	LogAboutPerformingAction("buying candy from Apu");

	IContactList& contactList = GetContactList();

	auto apu = contactList.GetCitizen(CitizenName::apu);
	const Money amountToCandy = GetRandomExpenseAmount();
	HandOverMoney(apu, amountToCandy);
}
