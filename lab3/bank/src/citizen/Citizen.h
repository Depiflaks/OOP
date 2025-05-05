//
// Created by smmm on 19.03.2025.
//

#ifndef SCENARIO_H
#define SCENARIO_H

#include "../actor/Actor.h"
#include "../town/Town.h"
#include "description/contactList/IContactList.h"
#include "description/name/CitizenName.h"
#include "iCitizen/ICitizen.h"

#include <functional>

class CitizenNotFoundException final : public std::out_of_range
{
public:
	using std::out_of_range::out_of_range;
	~CitizenNotFoundException() override = default;
};

class Citizen : public ICitizen
	, public Actor
{
public:
	void PerformRandomActionWithErrorHandling() override;
	void LogAboutPerformingAction(std::string_view actionName) const;

	virtual void PerformRandomAction() = 0;
	static ActionType ChooseRandomAction(const std::vector<ActionType>& actions);

	[[nodiscard]] CitizenName GetName() override;
	[[nodiscard]] IContactList& GetContactList() const;

private:
	explicit Citizen(Bank& bank, Money cash, CitizenName name, IContactList& contacts);

	CitizenName m_name;
	IContactList& m_contacts;
};

#endif // SCENARIO_H
