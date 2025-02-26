//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_MR_BURNS_H
#define CITIZEN_MR_BURNS_H


#include "../../../actor/Actor.h"
#include "../../ICitizen.h"
#include "../../description/CitizenDescription.h"
#include "../../description/data/CitizensData.h"

class CitizenMrBurns final : public ICitizen
	, protected Actor
	, protected CitizenDescription
{
public:
	CitizenMrBurns(Bank& bank, CitizensData& citizens, Money cash);
	void ExecuteWithErrorHandling() override;
	void PlanExpenses() override;
	void PlanExpenses(Money homerAmount, Money smithersAmount, bool shouldUpdateSmithersId);

private:
	Money m_amountToHomer{ 0 };
	Money m_amountToSmithers{ 0 };
	AccountId m_smithersId{ 0 };
	bool m_shouldUpdateSmithersId{ false };

	void Execute() override;
	void GiveSalaryToHomer() const;
	void UpdateSmithersAccount();
	void GiveSalaryToSmithers() const;
};


#endif //CITIZEN_MR_BURNS_H
