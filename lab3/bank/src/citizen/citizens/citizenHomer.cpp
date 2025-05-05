//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

CitizenHomer::CitizenHomer(Bank& bank, IContactList& contacts, const Money cash)
	: Citizen(bank, cash, CitizenName::homerSimpson, contacts)
{
	OpenAccount();
	DepositMoney(cash);

	AddAction([this] { TransferMoneyToMarge(); });
	AddAction([this] { PayForElectricity(); });
	AddAction([this] { GiveMoneyToChildren(); });
}

void CitizenHomer::TransferMoneyToMarge() const
{
	LogAboutPerformingAction("transferring money to Marge");
	IContactList& contactList = GetContactList();
}

void CitizenHomer::PayForElectricity() const
{
	LogAboutPerformingAction("paying for electricity");
	IContactList& contactList = GetContactList();
}

void CitizenHomer::GiveMoneyToChildren()
{
	LogAboutPerformingAction("giving money to children");
	IContactList& contactList = GetContactList();
}