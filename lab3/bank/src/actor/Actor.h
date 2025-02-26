//
// Created by smmm on 19.03.2025.
//

#ifndef ACTOR_H
#define ACTOR_H

#include "../bank/Bank.h"

#include <optional>

class Actor
{
public:
	explicit Actor(Bank& bank, Money cash);

	// публичные методы:
	// 1) узнать баланс на счёте
	[[nodiscard]] Money GetAccountBalance() const;

	// 2) узнать баланс в нале
	[[nodiscard]] Money GetCashBalance() const;

	// 3) узнать текущий id счёта в банке
	[[nodiscard]] std::optional<AccountId> GetAccountId() const;

	// 4) перевести другому актору на счёт
	void TransferMoney(Actor& dstActor, Money amount);

	// 5) передать деньги другому актору наличкой
	void HandOverMoney(Actor& dstActor, Money amount);

	// 6) вытрясти деньги у другого актора (наличка)
	void ExtortMoney(Actor& dstActor, Money amount);

	// 7) Пополнить собственный баланс
	void DepositMoney(Money amount);

	// 8) Вывести из собственного счёта
	void WithdrawMoney(Money amount);

	// 9) открыть Счёт
	void OpenAccount();

	// 10) закрыть счёт
	void CloseAccount();

private:
	// параметры:
	// - количество денег в нале
	Money m_cashBalance;
	// - количество денег на счету
	Money m_accountBalance;
	// - номер текущего счёта
	std::optional<AccountId> m_accountId;
	// - ссылка на банк
	Bank& m_bank;

	// приватные методы
	// 1) проверить, есть ли у пользователя счёт в банке
	void CheckActorHaveAccount(AccountId account) const;
	// 2) проверить, достаточно ли у пользователя налички для того, чтобы поделиться
	void CheckActorHaveEnoughCash(AccountId account, Money amount) const;
};

#endif // ACTOR_H
