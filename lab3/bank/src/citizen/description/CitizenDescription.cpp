//
// Created by smmm on 27.03.2025.
//

#include "CitizenDescription.h"

CitizenDescription::CitizenDescription(const CitizenName name, CitizenMap& citizens)
	: m_name(name)
	, m_citizens(citizens)
{
}

Actor CitizenDescription::FindCitizen(const CitizenName citizen) const
{
	CheckCitizenExist(citizen);
	return m_citizens[citizen];
}

void CitizenDescription::CheckCitizenExist(const CitizenName citizen) const
{
	if (!m_citizens.contains(citizen))
		throw CitizenNotFoundException{ "citizen " + getName(citizen) + "not found" };
}
