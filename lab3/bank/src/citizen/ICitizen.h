//
// Created by smmm on 19.03.2025.
//

#ifndef SCENARIO_H
#define SCENARIO_H

#include "../actor/Actor.h"
#include "../town/Town.h"

class CitizenNotFoundException final : public std::out_of_range
{
public:
	using std::out_of_range::out_of_range;
	~CitizenNotFoundException() override = default;
};

class ICitizen
{
public:
	virtual void ExecuteWithErrorHandling();
	virtual void PlanExpenses() = 0;
	virtual ~ICitizen() = default;

	// todo: избавиться от protected методов геттерами
protected:
	explicit ICitizen() = default;
	virtual void Execute() = 0;
};

#endif // SCENARIO_H
