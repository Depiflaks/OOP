//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_MR_BURNS_H
#define CITIZEN_MR_BURNS_H


#include "../../../actor/Actor.h"
#include "../../ICitizen.h"
#include "../../description/CitizenDescription.h"

class CitizenMrBurns final : public ICitizen
	, protected Actor
	, protected CitizenDescription
{
public:
	CitizenMrBurns(Bank& bank, CitizenMap& citizens, Money cash);
	void ExecuteWithErrorHandling() override;
	void PlanExpenses() override;
	void PlanExpenses(Money homerAmount, Money smithersAmount);

private:
	Money m_amountToHomer{ 0 };
	Money m_amountToSmithers{ 0 };

	void Execute() override;
	void GiveSalaryToHomer() const;
	void GiveSalaryToSmithers() const;
};


#endif //CITIZEN_MR_BURNS_H
