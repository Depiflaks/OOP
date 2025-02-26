//
// Created by smmm on 15.03.2025.
//

#include "Bank.h"

Bank::Bank(const Money cash)
{
	m_cash = cash;
	m_lastAccountId = 0;
}

void Bank::SendMoney(AccountId srcAccountId, AccountId dstAccountId, Money amount)
{
}

bool Bank::TrySendMoney(AccountId srcAccountId, AccountId dstAccountId, Money amount)
{
}

Money Bank::GetCash() const
{
	return m_cash;
}

Money Bank::GetAccountBalance(AccountId accountId) const
{
}

void Bank::WithdrawMoney(AccountId account, Money amount)
{
}

bool Bank::TryWithdrawMoney(AccountId account, Money amount)
{
}

void Bank::DepositMoney(AccountId account, Money amount)
{
}

AccountId Bank::OpenAccount()
{
	if (m_accountBalances.count(AccountId{ 1 }) == 0)
	{
	}
}

Money Bank::CloseAccount(AccountId accountId)
{
}

void Bank::AssertTransferAmountPositive(const Money amount)
{
	if (amount < 0)
		throw NegativeTransferAmountException();
}