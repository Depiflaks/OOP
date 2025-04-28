//
// Created by smmm on 27.03.2025.
//
#include "Citizen.h"

#include "../actor/Actor.h"
#include "../bank/Bank.h"
#include "description/name/CitizenName.h"

#include <iostream>

Citizen::Citizen(const CitizenName& name, )
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