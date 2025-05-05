//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_BART_AND_LISA_H
#define CITIZEN_BART_AND_LISA_H


#include "../../../actor/Actor.h"
#include "../../Citizen.h"
#include "../../description/contactList/IContactList.h"

class CitizenBartAndLisa final : public Citizen
{
public:
	CitizenBartAndLisa(Bank& bank, IContactList& contacts, Money cash);

private:
	void BuyCandyFromApu();
};


#endif //CITIZEN_BART_AND_LISA_H
