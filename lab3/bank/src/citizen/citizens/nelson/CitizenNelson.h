//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_NELSON_H
#define CITIZEN_NELSON_H

#include "../../../actor/Actor.h"
#include "../../Citizen.h"
#include "../../description/CitizenDescription.h"
#include "../../description/contactList/IContactList.h"

class CitizenNelson final : public Citizen
    , protected Actor
    , protected CitizenDescription
{
public:
    CitizenNelson(Bank& bank, CitizensData& citizens, Money cash);
    void ExecuteWithErrorHandling() override;
    void PlanExpenses() override;
    void PlanExpenses(Money stolenAmount);

private:
    Money m_stolenAmount = 0;

    void PerformRandomAction() override;
    void StealFromBart();
    void BuyCigarettesFromApu();
};



#endif //CITIZEN_NELSON_H
