//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_SNAKE_H
#define CITIZEN_SNAKE_H

#include "../../../actor/Actor.h"
#include "../../ICitizen.h"
#include "../../description/CitizenDescription.h"

class CitizenSnake final : public ICitizen
	, protected Actor
	, protected CitizenDescription
{
public:
	CitizenSnake(Bank& bank, CitizenMap& citizens, Money cash);
	void ExecuteWithErrorHandling() override;
	void PlanExpenses() override;
	void PlanExpenses(Money hackedAmount, Money apuAmount);

private:
	Money m_hackedAmount{ 0 };
	Money m_apuAmount{ 0 };

	void Execute() override;
	void HackHomerAccount() const;
	void BuyGroceriesFromApu() const;
};

#endif // CITIZEN_SNAKE_H
