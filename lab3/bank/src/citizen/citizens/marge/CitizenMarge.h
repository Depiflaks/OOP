//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_MARGE_H
#define CITIZEN_MARGE_H

#include "../../../actor/Actor.h"
#include "../../ICitizen.h"
#include "../../description/CitizenDescription.h"
#include "../../description/data/CitizensData.h"

class CitizenMarge final : public ICitizen
	, protected Actor
	, protected CitizenDescription
{
public:
	CitizenMarge(Bank& bank, CitizensData& citizens, Money cash);
	void ExecuteWithErrorHandling() override;
	void PlanExpenses() override;
	void PlanExpenses(Money apuAmount);

private:
	Money m_amountToApu{ 0 };

	void Execute() override;
	void BuyGroceriesFromApu() const;
};


#endif //CITIZEN_MARGE_H
