//
// Created by smmm on 19.03.2025.
//

#ifndef SCENARIO_H
#define SCENARIO_H

#include "../actor/Actor.h"
#include "../town/Town.h"
#include "description/contactList/IContactList.h"
#include "description/name/CitizenName.h"

#include <functional>

class CitizenNotFoundException final : public std::out_of_range
{
public:
	using std::out_of_range::out_of_range;
	~CitizenNotFoundException() override = default;
};

class Citizen : public Actor
{
public:
	void PerformRandomActionWithErrorHandling();
	virtual ~Citizen() = default;

	void LogAboutPerformingAction(std::string_view actionName) const;
	[[nodiscard]] CitizenName GetName() const;
	[[nodiscard]] IContactList& GetContactList() const;

private:
	explicit Citizen(Bank& bank, Money cash, CitizenName name, IContactList& contacts);
	virtual void PerformRandomAction() = 0;
	static std::function<void()> ChooseRandomAction(const std::vector<std::function<void()>>& actions);

	CitizenName m_name;
	IContactList& m_contacts;
};

#endif // SCENARIO_H
