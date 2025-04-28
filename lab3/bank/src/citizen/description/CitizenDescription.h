//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_DESCRIPTION_H
#define CITIZEN_DESCRIPTION_H

#include "data/ContactList.h"
#include "name/CitizenName.h"

class CitizenDescription
{
public:
	explicit CitizenDescription::CitizenDescription(CitizenName name, ContactList& citizens);

	const CitizenName getName();
	const ContactList& getContactList();

protected:
	const CitizenName m_name{ CitizenName::homerSimpson };
	ContactList& m_contacts;
};

#endif // CITIZEN_DESCRIPTION_H
