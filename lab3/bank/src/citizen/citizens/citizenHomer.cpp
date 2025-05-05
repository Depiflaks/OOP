//
// Created by smmm on 05.05.2025.
//
#include "citizens.h"

#include <Town.h>

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

	const auto marge = contactList.GetCitizen(CitizenName::margeSimpson);
	const Money amountToMarge = GetRandomExpenseAmount();

	TransferMoney(marge, amountToMarge);
}

void CitizenHomer::PayForElectricity() const
{
	LogAboutPerformingAction("paying for electricity");
	IContactList& contactList = GetContactList();

	const auto burns = contactList.GetCitizen(CitizenName::mrBurns);
	const Money amountForElectricity = GetRandomExpenseAmount();

	TransferMoney(burns, amountForElectricity);
}

void CitizenHomer::GiveMoneyToChildren()
{
	LogAboutPerformingAction("giving money to children");
	IContactList& contactList = GetContactList();

	auto bart = contactList.GetCitizen(CitizenName::bartSimpson);
	auto lisa = contactList.GetCitizen(CitizenName::lisaSimpson);
	const Money amountForChildren = GetRandomExpenseAmount();

	WithdrawMoney(amountForChildren);

	HandOverMoney(bart, amountForChildren / 2);
	HandOverMoney(lisa, amountForChildren / 2);
}