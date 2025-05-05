//
// Created by smmm on 19.03.2025.
//

#ifndef CITIZEN_H
#define CITIZEN_H

#include "../actor/Actor.h"
#include "description/contactList/IContactList.h"
#include "description/name/CitizenName.h"

#include <functional>

class IContactList;

class Citizen : public Actor
{
public:
	explicit Citizen(Bank& bank, Money cash, CitizenName name, IContactList& contacts);

	void PerformRandomActionWithErrorHandling() const;
	static void LogAboutPerformingAction(std::string_view actionDescription);

	template <typename T>
	void AddAction(T&& action)
	{
		m_actions.emplace_back(std::forward<T>(action));
	}

	void PerformRandomAction() const;

	[[nodiscard]] CitizenName GetName() const;
	[[nodiscard]] IContactList& GetContactList() const;

private:
	CitizenName m_name;
	std::vector<ActionType> m_actions{};
	IContactList& m_contacts;
};

#endif // CITIZEN_H
