//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_SMITHERS_H
#define CITIZEN_SMITHERS_H

#include "../../../actor/Actor.h"
#include "../../Citizen.h"
#include "../../description/CitizenDescription.h"
#include "../../description/contactList/ContactList.h"

class CitizenSmithers final : public Citizen
    , protected Actor
    , protected CitizenDescription
{
public:
    CitizenSmithers(Bank& bank, CitizensRegistry& citizens, Money cash);
    void ExecuteWithErrorHandling() override;
    void PlanExpenses() override;
    void PlanExpenses(Money abuAmount, bool shouldNotifyingBoss);

private:
    Money m_amountToAbu = 0;
    bool m_shouldNotifyingBoss = true;

    void Execute() override;
    void BuyGroceries() const;
    void ChangeAccount();
};


#endif //CITIZEN_SMITHERS_H
