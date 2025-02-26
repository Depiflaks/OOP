//
// Created by smmm on 15.03.2025.
//

#include "Bank.h"

Bank::Bank(Money cash)
{
}
void Bank::SendMoney(AccountId srcAccountId, AccountId dstAccountId, Money amount)
{
}
bool Bank::TrySendMoney(AccountId srcAccountId, AccountId dstAccountId, Money amount)
{
}
Money Bank::GetCash() const
{
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
}
Money Bank::CloseAccount(AccountId accountId)
{
}