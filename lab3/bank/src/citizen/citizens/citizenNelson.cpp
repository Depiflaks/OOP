//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

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
}

void CitizenNelson::BuyCigarettesFromApu()
{
	LogAboutPerformingAction("buying cigarettes from Apu");
	IContactList& contactList = GetContactList();
}