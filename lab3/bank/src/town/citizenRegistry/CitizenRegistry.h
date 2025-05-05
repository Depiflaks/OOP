//
// Created by smmm on 29.04.2025.
//

#ifndef CITIZEN_REGISTRY_H
#define CITIZEN_REGISTRY_H

#include "../../citizen/description/contactList/IContactList.h"

#include <memory>

class ContactNotFoundException final : public std::runtime_error
{
public:
	explicit ContactNotFoundException(const CitizenName name)
		: std::runtime_error{ "Contact of citizen: " + ConvertToString(name) + " not found" }
	{
	}
};

class CitizenRegistry final : public IContactList
{
public:
	explicit CitizenRegistry(Bank& bank);

	ICitizen& GetCitizen(CitizenName name) override;
	ICitizen& GetRandomCitizen() override;

private:
	std::map<CitizenName, std::unique_ptr<ICitizen>> m_citizens;

	void CheckCitizenExist(CitizenName name) const;
};

#endif // CITIZEN_REGISTRY_H
