//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_HOMER_H
#define CITIZEN_HOMER_H

#include "../../../actor/Actor.h"
#include "../../Citizen.h"
#include "../../description/CitizenDescription.h"
#include "../../description/contactList/IContactList.h"

class CitizenHomer final : public Citizen
	, protected Actor
	, protected CitizenDescription
{
public:
	CitizenHomer(Bank& bank, CitizensData& citizens, Money cash);
	void ExecuteWithErrorHandling() override;
	void PlanExpenses() override;
	void PlanExpenses(Money margeAmount, Money bartAmount, Money lisaAmount, Money electricityAmount);

private:
	Money m_amountToMarge{ 0 };
	Money m_amountToLisa{ 0 };
	Money m_amountToBart{ 0 };
	Money m_amountForElectricity{ 0 };

	void PerformRandomAction() override;
	void TransferMoneyToMarge() const;
	void PayForElectricity() const;
	void GiveMoneyToChildren();
};

#endif // CITIZEN_HOMER_H
