//
// Created by smmm on 27.03.2025.
//
#include "Citizen.h"

#include "../actor/Actor.h"
#include "../bank/Bank.h"
#include "../random/random.h"
#include "description/name/CitizenName.h"

#include <iostream>

Citizen::Citizen(Bank& bank, const Money cash, const CitizenName name, IContactList& contacts)
	: Actor(bank, cash)
	, m_name(name)
	, m_contacts(contacts)
{
}

void Citizen::PerformRandomActionWithErrorHandling()
{
	std::cout << "Executing " << ::ConvertToString(m_name) << " scenario\n";
	try
	{
		PerformRandomAction();
	}
	catch (BankOperationException& exception)
	{
		std::cout << "error while executing bank operation: " << exception.what();
	}
	catch (ActorInteractionException& exception)
	{
		std::cout << "error while executing actor operation: " << exception.what();
	}
	catch (std::exception& exception)
	{
		std::cout << "unexpected error: " << exception.what();
	}
}

void Citizen::LogAboutPerformingAction(const std::string_view actionName) const
{
	std::cout << ConvertToString(m_name) << " performing " << actionName << ".\n";
	;
}

std::function<void()> Citizen::ChooseRandomAction(const std::vector<std::function<void()>>& actions)
{
	return ChooseRandom<std::function<void()>>(actions);
}

CitizenName Citizen::GetName() const
{
	return m_name;
}

IContactList& Citizen::GetContactList() const
{
	return m_contacts;
}