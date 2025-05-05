//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZENS_REGISTRY_H
#define CITIZENS_REGISTRY_H

#include "../../Citizen.h"

class IContactList
{
public:
	IContactList() = default;
	virtual ~IContactList() = default;

	virtual ICitizen& GetRandomCitizen() = 0;
	virtual ICitizen& GetCitizen(CitizenName name) = 0;
};

#endif // CITIZENS_REGISTRY_H
