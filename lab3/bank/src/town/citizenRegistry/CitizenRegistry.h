//
// Created by smmm on 29.04.2025.
//

#ifndef CITIZEN_REGISTRY_H
#define CITIZEN_REGISTRY_H
#include "../../citizen/description/contactList/ContactList.h"

class CitizenRegistry : public ContactList
{
public:
	explicit CitizenRegistry(Bank bank);

private:
	std::map<CitizenName, Citizen&> m_citizens;

	int k_citizenCount{9};
};

#endif // CITIZEN_REGISTRY_H
