//
// Created by smmm on 15.03.2025.
//

#include "Bank.h"

#include <limits>

Bank::Bank(const Money cash)
{
	CheckTransferAmountPositive(cash);
	m_cash = cash;
	m_lastAccountId = 0;
}

void Bank::SendMoney(const AccountId srcAccountId, const AccountId dstAccountId, const Money amount)
{
	CheckAccountExist(srcAccountId);
	CheckAccountExist(dstAccountId);
	CheckTransferAmountPositive(amount);
	CheckEnoughMoneyOnExistingAccount(srcAccountId, amount);
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
	catch (const NotEnoughMoneyException& e)
	{
		return false;
	}
}

Money Bank::GetCash() const
{
	return m_cash;
}

Money Bank::GetAccountBalance(const AccountId accountId) const
{
	CheckAccountExist(accountId);
	return m_accountBalances.at(accountId);
}

void Bank::WithdrawMoney(const AccountId account, const Money amount)
{
	CheckAccountExist(account);
	CheckTransferAmountPositive(amount);
	CheckEnoughMoneyOnExistingAccount(account, amount);
	m_accountBalances[account] -= amount;
	m_cash += amount;
}

bool Bank::TryWithdrawMoney(const AccountId account, const Money amount)
{
	try
	{
		WithdrawMoney(account, amount);
		return true;
	}
	catch (const NotEnoughMoneyException& e)
	{
		return false;
	}
}

void Bank::DepositMoney(const AccountId account, const Money amount)
{
	CheckAccountExist(account);
	CheckTransferAmountPositive(amount);
	CheckEnoughMoneyInCash(amount);
	m_cash -= amount;
	m_accountBalances[account] += amount;
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
	CheckAccountExist(accountId);
	const Money balance = m_accountBalances[accountId];
	m_cash += balance;
	m_accountBalances.erase(accountId);
	return balance;
}

void Bank::CheckTransferAmountPositive(const Money amount)
{
	if (amount < 0)
		throw NegativeTransferAmountException();
}

void Bank::CheckAccountExist(const AccountId account_id) const
{
	if (!m_accountBalances.contains(account_id))
		throw AccountExistenceException("Account not exist");
}

void Bank::CheckAccountDontExist(const AccountId account_id) const
{
	if (m_accountBalances.contains(account_id))
		throw AccountExistenceException("Account already exist");
}

void Bank::CheckEnoughMoneyInCash(const Money amount) const
{
	if (m_cash < amount)
		throw NotEnoughMoneyException();
}

void Bank::CheckEnoughMoneyOnExistingAccount(const AccountId srcAccountId, const Money amount) const
{
	if (m_accountBalances.at(srcAccountId) < amount)
		throw NotEnoughMoneyException();
}
