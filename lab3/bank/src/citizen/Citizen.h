//
// Created by smmm on 19.03.2025.
//

#ifndef SCENARIO_H
#define SCENARIO_H

#include "../town/Town.h"

class CitizenNotFoundException final : public std::out_of_range
{
public:
	using std::out_of_range::out_of_range;
	~CitizenNotFoundException()() override = default;
};

class ICitizen
{
public:
	virtual void ExecuteWithErrorHandling();
	virtual ~ICitizen() = default;

protected:
	const CitizenName m_name{ CitizenName::homerSimpson };
	CitizenMap& m_citizens{};

	explicit ICitizen() = default;

private:
	virtual void Execute() = 0;
	void CheckCitizenExist(CitizenName citizen);
};

#endif // SCENARIO_H
