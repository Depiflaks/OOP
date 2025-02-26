//
// Created by smmm on 19.03.2025.
//

#ifndef SCENARIO_H
#define SCENARIO_H
#include <map>

#include "../actor/Actor.h"
#include "../bank/Bank.h"
#include "../citizenName/CitizenName.h"

class ICitizen
{
public:
	virtual void ExecuteWithErrorHandling() = 0;
	virtual ~ICitizen() = default;

protected:
	explicit ICitizen() = default;

private:
	void Execute(Bank& bank);
	void Rollback();
};

#endif // SCENARIO_H
