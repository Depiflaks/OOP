//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_APU_H
#define CITIZEN_APU_H

#include "../../Citizen.h"

class CitizenApu final : public Citizen
{
public:
	CitizenApu(Bank& bank, IContactList& contacts, Money cash);
	void PerformRandomAction() override;

private:
	void PayForElectricity() const;
	void DepositCashMoney();

	std::vector<ActionType> m_actions{};
};

#endif // CITIZEN_APU_H
