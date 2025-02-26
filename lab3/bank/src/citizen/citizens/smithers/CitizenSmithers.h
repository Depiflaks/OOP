//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_SMITHERS_H
#define CITIZEN_SMITHERS_H

#include "../../../actor/Actor.h"
#include "../../ICitizen.h"
#include "../../description/CitizenDescription.h"
#include "../mrBurns/CitizenMrBurns.h"

class CitizenSmithers final : public ICitizen
    , protected Actor
    , protected CitizenDescription
{
public:
    CitizenSmithers(Bank& bank, CitizenMap& citizens, CitizenMrBurns& mrBurns, Money cash);
    void ExecuteWithErrorHandling() override;
    void PlanExpenses() override;
    void PlanExpenses(Money abuAmount, bool shouldNotifyingBoss);

private:
    Money m_amountToAbu = 0;
    bool m_shouldNotifyingBoss = true;
	CitizenMrBurns& m_mrBurns;

    void Execute() override;
    void BuyGroceries() const;
    void ChangeAccount();
	void NotifyAboutNewAccount() const;
};


#endif //CITIZEN_SMITHERS_H
