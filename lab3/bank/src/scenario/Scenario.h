//
// Created by smmm on 19.03.2025.
//

#ifndef SCENARIO_H
#define SCENARIO_H
#include <map>

#include "../actor/Actor.h"
#include "../bank/Bank.h"
#include "../characterName/CharacterName.h"

using ActorsMap = std::map<CharacterName, Actor>;

class IScenario
{
public:
	virtual void ExecuteWithErrorHandling() = 0;
	virtual ~IScenario() = default;

protected:
	explicit IScenario() = default;

private:
	void Execute(Bank& bank);
	void Rollback();
};

#endif // SCENARIO_H
