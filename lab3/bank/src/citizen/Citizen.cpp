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

Citizen::Citizen(Bank& bank, const Money cash, const CitizenName name, ContactList& contacts)
	: Actor(bank, cash)
	, m_name(name)
	, m_contacts(contacts)
{
}

CitizenName Citizen::GetName() const
{
	return m_name;
}

ContactList& Citizen::GetContactList() const
{
	return m_contacts;
}