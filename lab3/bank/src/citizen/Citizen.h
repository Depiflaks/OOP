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
	~CitizenNotFoundException()() override = default;
};

class Citizen
{
public:
	explicit Citizen(CitizenName name, CitizenMap& citizens);
	virtual void ExecuteWithErrorHandling();
	virtual ~Citizen() = default;

protected:

	explicit Citizen() = default;
	Citizen FindCitizen(CitizenName citizen);

private:
	void Execute();
	static void CheckCitizenExist(CitizenName citizen);
};

#endif // SCENARIO_H
