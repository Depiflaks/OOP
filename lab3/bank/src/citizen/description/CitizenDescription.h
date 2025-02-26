//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_DESCRIPTION_H
#define CITIZEN_DESCRIPTION_H

#include "data/CitizensData.h"
#include "name/CitizenName.h"

class CitizenDescription
{
public:
	explicit CitizenDescription::CitizenDescription(CitizenName name, CitizensData& citizens);

protected:
	const CitizenName m_name{ CitizenName::homerSimpson };
	CitizensData& m_citizens;
};

#endif // CITIZEN_DESCRIPTION_H
