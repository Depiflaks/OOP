//
// Created by smmm on 19.03.2025.
//

#include "Actor.h"

Actor::Actor(Bank& bank, const Money cash)
	: m_cashBalance(cash)
	, m_accountId(std::nullopt)
	, m_bank(bank)
{
}

Money Actor::GetAccountBalance() const
{
	CheckActorHaveAccount(*this);
	return m_bank.GetAccountBalance(*m_accountId);
}

Money Actor::GetCashBalance() const
{
	return m_cashBalance;
}

Money Actor::TakePreparedMoney()
{
	const Money money = m_preparedCashToTransfer;
	m_preparedCashToTransfer = 0;
	return money;
}

std::optional<AccountId> Actor::GetAccountId() const
{
	return m_accountId;
}

void Actor::TransferMoney(const Actor& dstActor, const Money amount) const
{
	CheckActorHaveAccount(*this);
	CheckActorHaveAccount(dstActor);
	m_bank.SendMoney(*GetAccountId(), *dstActor.GetAccountId(), amount);
}

void Actor::HandOverMoney(Actor& dstActor, const Money amount)
{
	PrepareMoneyForTransfer(amount);
	dstActor.ReceivePreparedCash(*this);
}

void Actor::ExtortMoney(Actor& dstActor, const Money amount)
{
	dstActor.PrepareMoneyForTransfer(amount);
	ReceivePreparedCash(dstActor);
}

void Actor::ReceivePreparedCash(Actor& dstActor)
{
	const Money money = dstActor.TakePreparedMoney();
	m_cashBalance += money;
}

void Actor::DepositMoney(const Money amount)
{
	CheckActorHaveAccount(*this);
	CheckActorHaveEnoughCash(*this, amount);
	m_bank.DepositMoney(*GetAccountId(), amount);
	m_cashBalance -= amount;
}

void Actor::WithdrawMoney(const Money amount)
{
	CheckActorHaveAccount(*this);
	m_bank.WithdrawMoney(*GetAccountId(), amount);
	m_cashBalance += amount;
}

void Actor::PrepareMoneyForTransfer(const Money amount)
{
	CheckActorHaveEnoughCash(*this, amount);
	m_preparedCashToTransfer += amount;
	m_cashBalance -= amount;
}

void Actor::OpenAccount()
{
	AccountId account = m_bank.OpenAccount();
	m_accountId = account;
}

void Actor::CloseAccount()
{
	CheckActorHaveAccount(*this);
	const Money amount = m_bank.CloseAccount(*m_accountId);
	m_cashBalance += amount;
	m_accountId = std::nullopt;
}

void Actor::CheckActorHaveAccount(const Actor& actor)
{
	if (actor.GetAccountId() == std::nullopt)
		throw ActorNotHaveAccountException();
}

void Actor::CheckActorHaveEnoughCash(const Actor& actor, const Money amount)
{
	if (actor.GetCashBalance() < amount)
		throw ActorNotHaveEnoughCashException();
}
