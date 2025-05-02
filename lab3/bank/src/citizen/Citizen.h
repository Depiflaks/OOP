//
// Created by smmm on 19.03.2025.
//

#ifndef SCENARIO_H
#define SCENARIO_H

#include "../actor/Actor.h"
#include "../town/Town.h"
#include "description/contactList/IContactList.h"
#include "description/name/CitizenName.h"

class CitizenNotFoundException final : public std::out_of_range
{
public:
	using std::out_of_range::out_of_range;
	~CitizenNotFoundException() override = default;
};

class Citizen : public Actor
{
public:
	void ExecuteWithErrorHandling();
	virtual void PlanExpenses() = 0;
	virtual ~Citizen() = default;

	[[nodiscard]] CitizenName GetName() const;
	[[nodiscard]] IContactList& GetContactList() const;

private:
	explicit Citizen(Bank& bank, Money cash, CitizenName name, IContactList& contacts);
	virtual void Execute() = 0;

	CitizenName m_name;
	IContactList& m_contacts;
};

#endif // SCENARIO_H
