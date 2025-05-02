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

private:
	void PerformRandomAction() override;
	void PayForElectricity() const;
	void DepositCashMoney();
};

#endif // CITIZEN_APU_H
