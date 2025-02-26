//
// Created by smmm on 19.03.2025.
//

#ifndef ACTOR_H
#define ACTOR_H

#include "../bank/Bank.h"

#include <optional>

class ActorInteractionException : std::runtime_error
{
public:
	using runtime_error::runtime_error;
};

class ActorNotHaveAccountException final : ActorInteractionException
{
public:
	explicit ActorNotHaveAccountException()
		: ActorInteractionException("Actor doesn't have bank account")
	{
	}
};

class ActorNotHaveEnoughCashException final : ActorInteractionException
{
public:
	explicit ActorNotHaveEnoughCashException()
		: ActorInteractionException("Actor doesn't have enough cash to perform operation")
	{
	}
};

class Actor
{
public:
	explicit Actor(Bank& bank, Money cash);

	// Публичные методы:
	// Узнать баланс на счёте
	[[nodiscard]] Money GetAccountBalance() const;

	// Узнать баланс в нале
	[[nodiscard]] Money GetCashBalance() const;

	// Узнать текущий id счёта в банке
	[[nodiscard]] std::optional<AccountId> GetAccountId() const;

	// Перевести другому актору на счёт
	void TransferMoney(const Actor& dstActor, Money amount) const;

	// Передать деньги другому актору наличкой
	void HandOverMoney(Actor& dstActor, Money amount);

	// Вытрясти деньги у другого актора (наличка)
	void ExtortMoney(Actor& dstActor, Money amount);

	// Пополнить собственный баланс
	void DepositMoney(Money amount);

	// Вывести из собственного счёта
	void WithdrawMoney(Money amount);

	// Приготовить деньги к передаче другому актору
	void PrepareMoneyForTransfer(Money amount);

	// Открыть Счёт
	void OpenAccount();

	// Закрыть счёт
	void CloseAccount();

private:
	// Параметры:
	// Количество денег в нале
	Money m_cashBalance;
	// Номер текущего счёта
	std::optional<AccountId> m_accountId;
	// Ссылка на банк
	Bank& m_bank;

	// Приватные методы
	// Проверить, есть ли у пользователя счёт в банке
	static void CheckActorHaveAccount(const Actor& actor);
	// Проверить, достаточно ли у пользователя налички для того, чтобы поделиться
	static void CheckActorHaveEnoughCash(const Actor& actor, Money amount);
};

#endif // ACTOR_H
