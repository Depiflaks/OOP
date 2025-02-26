//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_BART_AND_LISA_H
#define CITIZEN_BART_AND_LISA_H


#include "../../../actor/Actor.h"
#include "../../ICitizen.h"
#include "../../description/CitizenDescription.h"

class CitizenBartAndLisa final : public ICitizen
	, protected Actor
	, protected CitizenDescription
{
public:
	CitizenBartAndLisa(Bank& bank, CitizenMap& citizens, Money cash);
	void ExecuteWithErrorHandling() override;
	void PlanExpenses() override;
	void PlanExpenses(Money apuAmountFromBart, Money apuAmountFromLisa);

private:
	Money m_amountToApuFromBart{ 0 };
	Money m_amountToApuFromLisa{ 0 };

	void Execute() override;
	void TransferMoneyToApu();
};


#endif //CITIZEN_BART_AND_LISA_H
