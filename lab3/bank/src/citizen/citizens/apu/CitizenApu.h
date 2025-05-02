//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_APU_H
#define CITIZEN_APU_H

#include "../../Citizen.h"
#include "../../description/contactList/ContactList.h"

class CitizenApu final : public Citizen
{
public:
	CitizenApu(Bank& bank, IContactList& contacts, Money cash);

	void PlanExpenses() override;
	void PlanExpenses(Money electricityAmount);

private:
	Money m_amountToElectricity{ 0 };

	void Execute() override;
	void PayForElectricity() const;
	void DepositCashMoney();
};

#endif // CITIZEN_APU_H
