//
// Created by smmm on 27.03.2025.
//
#include "Citizen.h"

#include "../actor/Actor.h"
#include "../bank/Bank.h"
#include "description/name/CitizenName.h"

#include <iostream>

void Citizen::ExecuteWithErrorHandling()
{
	std::cout << "Executing " << ::GetName(m_name) << " scenario\n";
	try
	{
		Execute();
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

Citizen::Citizen(Bank& bank, const Money cash, const CitizenName name, IContactList& contacts)
	: Actor(bank, cash)
	, m_name(name)
	, m_contacts(contacts)
{
}

CitizenName Citizen::GetName() const
{
	return m_name;
}

IContactList& Citizen::GetContactList() const
{
	return m_contacts;
}