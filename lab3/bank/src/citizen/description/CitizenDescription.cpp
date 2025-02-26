//
// Created by smmm on 27.03.2025.
//

#include "CitizenDescription.h"

CitizenDescription::CitizenDescription(const CitizenName name, CitizenMap& citizens)
	: m_name(name)
	, m_citizens(citizens)
{
}

Actor& CitizenDescription::FindCitizen(const CitizenName citizen) const
{
    CheckCitizenExist(citizen);

    ICitizen* baseCitizen = m_citizens.at(citizen).get();
	const auto actor = dynamic_cast<Actor*>(baseCitizen);
    return *actor;
}
}

void CitizenDescription::CheckCitizenExist(const CitizenName citizen) const
{
	if (!m_citizens.contains(citizen))
		throw CitizenNotFoundException{ "citizen " + getName(citizen) + "not found" };
}
