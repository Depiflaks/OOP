//
// Created by smmm on 19.03.2025.
//

#include "Actor.h"

Actor::Actor(Bank& bank, const Money cash)
	: m_cashBalance(cash)
	, m_accountBalance(0)
	, m_accountId(std::nullopt)
	, m_bank(bank)
{
}

Money Actor::GetAccountBalance() const
{
}

Money Actor::GetCashBalance() const
{
}

std::optional<AccountId> Actor::GetAccountId() const
{
}

void Actor::TransferMoney(Actor& dstActor, Money amount)
{
}

void Actor::HandOverMoney(Actor& dstActor, Money amount)
{
}

void Actor::ExtortMoney(Actor& dstActor, Money amount)
{
}

void Actor::DepositMoney(Money amount)
{
}

void Actor::WithdrawMoney(Money amount)
{
}

void Actor::OpenAccount()
{
}

void Actor::CloseAccount()
{
}

void Actor::CheckActorHaveAccount(AccountId account) const
{
}

void Actor::CheckActorHaveEnoughCash(AccountId account, Money amount) const
{
}
