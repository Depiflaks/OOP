//
// Created by smmm on 15.03.2025.
//

#include "Bank.h"

Bank::Bank(const Money cash)
{
	m_cash = cash;
	m_lastAccountId = 0;
}

void Bank::SendMoney(const AccountId srcAccountId, const AccountId dstAccountId, const Money amount)
{
	AssertAccountExist(srcAccountId);
	AssertAccountExist(dstAccountId);
	AssertTransferAmountPositive(amount);
	if (m_accountBalances.at(srcAccountId) < amount)
		throw NotEnoughMoneyException();
	m_accountBalances[srcAccountId] -= amount;
	m_accountBalances[dstAccountId] += amount;
}

bool Bank::TrySendMoney(const AccountId srcAccountId, const AccountId dstAccountId, const Money amount)
{
	try
	{
		SendMoney(srcAccountId, dstAccountId, amount);
		return true;
	}
	catch (NotEnoughMoneyException& e)
	{
		return false;
	}
	catch (BankOperationError& e)
	{
		throw;
	}
}

Money Bank::GetCash() const
{
	return m_cash;
}

Money Bank::GetAccountBalance(const AccountId accountId) const
{
	AssertAccountExist(accountId);
	return m_accountBalances.at(accountId);
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
	while (m_accountBalances.contains(m_lastAccountId))
		m_lastAccountId++;
	const AccountId newAccount = m_lastAccountId;
	m_accountBalances[newAccount] = 0;
	return newAccount;
}

Money Bank::CloseAccount(const AccountId accountId)
{
	AssertAccountExist(accountId);
	const Money balance = m_accountBalances[accountId];
	m_cash += balance;
	m_accountBalances.erase(accountId);
	return balance;
}

void Bank::AssertTransferAmountPositive(const Money amount)
{
	if (amount < 0)
		throw NegativeTransferAmountException();
}

void Bank::AssertAccountExist(const AccountId account_id) const
{
	if (!m_accountBalances.contains(account_id))
		throw AccountExistenceException("Account not exist");
}

void Bank::AssertAccountDontExist(const AccountId account_id) const
{
	if (m_accountBalances.contains(account_id))
		throw AccountExistenceException("Account already exist");
}

void Bank::AssertEnoughMoneyInCash(const Money amount) const
{
	if (m_cash < amount)
		throw BankOperationError("Not enough money in Cash");
}