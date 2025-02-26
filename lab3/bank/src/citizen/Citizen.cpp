//
// Created by smmm on 27.03.2025.
//
#include "Citizen.h"

#include "../actor/Actor.h"
#include "../bank/Bank.h"

#include <iostream>

Citizen::Citizen(const CitizenName name, CitizenMap& citizens)
	: m_name(name)
	, m_citizens(citizens)
{
}

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

Citizen Citizen::FindCitizen(CitizenName citizen)
{
	CheckCitizenExist(citizen);
	return m_citizens[citizen];
}

void Citizen::CheckCitizenExist(CitizenName citizen)
{
	if (!m_citizens.contains(citizen))
		throw CitizenNotFoundException{ "citizen " + getName(citizen) + "not found" };
}