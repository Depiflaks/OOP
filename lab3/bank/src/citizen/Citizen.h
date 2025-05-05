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
	static void LogAboutPerformingAction(std::string_view actionDescription);

	template <typename T>
	void AddAction(T&& action)
	{
		m_actions.emplace_back(std::forward<T>(action));
	}

	void PerformRandomAction() const;

	[[nodiscard]] CitizenName GetName() override;
	[[nodiscard]] IContactList& GetContactList() const;

private:
	explicit Citizen(Bank& bank, Money cash, CitizenName name, IContactList& contacts);

	[[nodiscard]] Money GetAccountBalance() override;
	[[nodiscard]] Money GetCashBalance() override;
	[[nodiscard]] std::optional<AccountId> GetAccountId() override;

	CitizenName m_name;
	std::vector<ActionType> m_actions{};
	IContactList& m_contacts;
};

#endif // SCENARIO_H
