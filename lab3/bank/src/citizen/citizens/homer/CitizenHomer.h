//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_HOMER_H
#define CITIZEN_HOMER_H
#include "../../../actor/Actor.h"
#include "../../ICitizen.h"
#include "../../description/CitizenDescription.h"

class CitizenHomer final : public ICitizen
	, protected Actor
	, protected CitizenDescription
{
public:
	CitizenHomer(Bank& bank, CitizenMap& citizens, Money cash);
	void ExecuteWithErrorHandling() override;

private:
	void Execute() override;
	void TransferMoneyToMarge(Money amount) const;
	void PayForElectricity(Money amount) const;
	void GiveMoneyToChildren(Money bartAmount, Money lisaAmount);
};

#endif // CITIZEN_HOMER_H
