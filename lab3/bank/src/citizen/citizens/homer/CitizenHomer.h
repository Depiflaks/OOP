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
	void PlanExpenses() override;
	void PlanExpenses(Money margeAmount, Money bartAmount, Money lisaAmount, Money electricityAmount);

private:
	Money m_amountToMarge{ 0 };
	Money m_amountToLisa{ 0 };
	Money m_amountToBart{ 0 };
	Money m_amountForElectricity{ 0 };

	void Execute() override;
	void TransferMoneyToMarge() const;
	void PayForElectricity() const;
	void GiveMoneyToChildren();
};

#endif // CITIZEN_HOMER_H
