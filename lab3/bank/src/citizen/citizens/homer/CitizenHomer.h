//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_HOMER_H
#define CITIZEN_HOMER_H
#include "../../../actor/Actor.h"
#include "../../Citizen.h"

class CitizenHomer final : public ICitizen
	, protected Actor
{
public:
	CitizenHomer(Bank& bank, CitizenMap& citizens, Money cash);
	void ExecuteWithErrorHandling() override;

private:
	void Execute() override;
	void TransferMoneyToMarge(Money amount);
	void PayForElectricity(Money amount);
	void GiveMoneyToChildren(Money bartAmount, Money lisaAmount);
};

#endif // CITIZEN_HOMER_H
