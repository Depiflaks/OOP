//
// Created by smmm on 19.03.2025.
//

#ifndef SCENARIO_H
#define SCENARIO_H

#include "../town/Town.h"

class ICitizen
{
public:
	virtual void ExecuteWithErrorHandling();
	virtual ~ICitizen() = default;

protected:
	explicit ICitizen() = default;

private:
	virtual void Execute() = 0;
};

#endif // SCENARIO_H
