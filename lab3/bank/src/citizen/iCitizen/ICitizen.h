//
// Created by smmm on 05.05.2025.
//

#ifndef ICITIZEN_H
#define ICITIZEN_H
#include "../../bank/Bank.h"
#include "../description/name/CitizenName.h"

#include <optional>

class ICitizen
{
public:
	virtual ~ICitizen() = default;
	virtual void PerformRandomActionWithErrorHandling() = 0;
	virtual CitizenName GetName() = 0;

	[[nodiscard]] virtual Money GetAccountBalance() = 0;
	[[nodiscard]] virtual Money GetCashBalance() = 0;
	[[nodiscard]] virtual std::optional<AccountId> GetAccountId() = 0;

private:
	explicit ICitizen() = default;
};

#endif // ICITIZEN_H
