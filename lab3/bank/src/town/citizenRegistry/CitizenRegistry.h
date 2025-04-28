//
// Created by smmm on 29.04.2025.
//

#ifndef CITIZEN_REGISTRY_H
#define CITIZEN_REGISTRY_H
#include "../../citizen/description/contactList/ContactList.h"

class CitizenRegistry : public ContactList
{
public:
	explicit CitizenRegistry() = default;

	using ContactList::SetHomer;
	using ContactList::SetMarge;
	using ContactList::SetBartAndLisa;
	using ContactList::SetApu;
	using ContactList::SetMrBurns;
	using ContactList::SetNelson;
	using ContactList::SetSnake;
	using ContactList::SetSmithers;
};

#endif // CITIZEN_REGISTRY_H
