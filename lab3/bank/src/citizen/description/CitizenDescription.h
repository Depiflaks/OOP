//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_DESCRIPTION_H
#define CITIZEN_DESCRIPTION_H

#include "map/citizenMap.h"
#include "name/CitizenName.h"

class CitizenDescription
{
public:
	explicit CitizenDescription::CitizenDescription(CitizenName name, CitizenMap& citizens);

protected:
	const CitizenName m_name{ CitizenName::homerSimpson };
	CitizenMap& m_citizens;

	[[nodiscard]] Actor& FindCitizen(CitizenName citizen) const;

private:
	void CheckCitizenExist(CitizenName citizen) const;
};

#endif // CITIZEN_DESCRIPTION_H
