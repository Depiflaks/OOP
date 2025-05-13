//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

#include <Town.h>

CitizenNelson::CitizenNelson(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::nelson, contacts)
{
	OpenAccount();
	DepositMoney(cash);

	AddAction([this] { StealFromBart(); });
	AddAction([this] { BuyCigarettesFromApu(); });
}

void CitizenNelson::StealFromBart()
{
	LogAboutPerformingAction("stealing from Bart");
	IContactList& contactList = GetContactList();

	auto bart = contactList.GetCitizen(CitizenName::bartSimpson);
	const Money amountForStealing = GetRandomExpenseAmount();

	ExtortMoney(bart, amountForStealing);
}

void CitizenNelson::BuyCigarettesFromApu()
{
	LogAboutPerformingAction("buying cigarettes from Apu");
	IContactList& contactList = GetContactList();

	auto apu = contactList.GetCitizen(CitizenName::apu);
	const Money amountForCigarettes = GetRandomExpenseAmount();

	HandOverMoney(apu, amountForCigarettes);
}