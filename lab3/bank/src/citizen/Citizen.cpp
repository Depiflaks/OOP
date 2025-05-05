//
// Created by smmm on 27.03.2025.
//
#include "Citizen.h"

#include "../actor/Actor.h"
#include "../bank/Bank.h"
#include "../random/random.h"
#include "description/name/CitizenName.h"

#include <CitizenRegistry.h>
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
		std::cout << "Error while executing bank operation: " << exception.what() << "\n";
	}
	catch (ActorInteractionException& exception)
	{
		std::cout << "Error while executing actor operation: " << exception.what() << "\n";
	}
	catch (ContactNotFoundException& exception)
	{
		std::cout << exception.what() << "\n";
	}
	catch (std::exception& exception)
	{
		std::cout << "Unexpected error: " << exception.what() << "\n";
	}
}

void Citizen::LogAboutPerformingAction(const std::string_view actionDescription)
{
	std::cout << "Performing: " << actionDescription << "...\n";
}

void Citizen::PerformRandomAction() const
{
	const auto action = ChooseRandom<ActionType>(m_actions);
	action();
}

CitizenName Citizen::GetName() const
{
	return m_name;
}

IContactList& Citizen::GetContactList() const
{
	return m_contacts;
}