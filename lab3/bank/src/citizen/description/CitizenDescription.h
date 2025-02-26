//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_DESCRIPTION_H
#define CITIZEN_DESCRIPTION_H

#include "data/CitizensRegistry.h"
#include "name/CitizenName.h"

class CitizenDescription
{
public:
	explicit CitizenDescription::CitizenDescription(CitizenName name, CitizensRegistry& citizens);

	const CitizenName getName();
	const CitizensRegistry& getData();

protected:
	const CitizenName m_name{ CitizenName::homerSimpson };
	//todo: contact list
	CitizensRegistry& m_citizens;
};

#endif // CITIZEN_DESCRIPTION_H
