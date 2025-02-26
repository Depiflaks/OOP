//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_HOMER_H
#define CITIZEN_HOMER_H
#include "../../Citizen.h"

class CitizenHomer final : public ICitizen
	, protected Actor
{
public:
	CitizenHomer(Bank& bank, Money cash);
	void ExecuteWithErrorHandling() override;

};

#endif // CITIZEN_HOMER_H
