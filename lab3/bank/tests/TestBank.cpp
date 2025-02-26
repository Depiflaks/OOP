//
// Created by smmm on 19.03.2025.
//

#include "../src/bank/Bank.h"
#include "gtest/gtest.h"
#include <vector>

Money calculateTotalMoney(const Bank& bank, const std::vector<AccountId>& accounts)
{
	Money total = bank.GetCash();
	for (const AccountId acc : accounts)
	{
		total += bank.GetAccountBalance(acc);
	}
	return total;
}

class BankTest : public ::testing::Test
{
protected:
	void SetUp() override { bank = new Bank(1000); }
	void TearDown() override { delete bank; }
	Bank* bank{};
};

TEST_F(BankTest, DepositAndInvariantCheck)
{
	AccountId acc1 = bank->OpenAccount();
	AccountId acc2 = bank->OpenAccount();
	std::vector<AccountId> accounts = { acc1, acc2 };
	Money initialTotal = calculateTotalMoney(*bank, accounts);
	Money depositAmount = 200;
	bank->DepositMoney(acc1, depositAmount);
	EXPECT_EQ(bank->GetAccountBalance(acc1), depositAmount);
	EXPECT_EQ(bank->GetCash(), 1000 - depositAmount);
	Money newTotal = calculateTotalMoney(*bank, accounts);
	EXPECT_EQ(newTotal, initialTotal);
}

TEST_F(BankTest, WithdrawAndInvariantCheck)
{
	AccountId acc = bank->OpenAccount();
	bank->DepositMoney(acc, 300);
	std::vector<AccountId> accounts = { acc };
	Money initialTotal = calculateTotalMoney(*bank, accounts);
	bank->WithdrawMoney(acc, 100);
	EXPECT_EQ(bank->GetAccountBalance(acc), 300 - 100);
	EXPECT_EQ(bank->GetCash(), (1000 - 300) + 100);
	Money newTotal = calculateTotalMoney(*bank, accounts);
	EXPECT_EQ(newTotal, initialTotal);
}

TEST_F(BankTest, SendMoneySuccessAndInvariantCheck)
{
	AccountId accFrom = bank->OpenAccount();
	AccountId accTo = bank->OpenAccount();
	std::vector<AccountId> accounts = { accFrom, accTo };
	bank->DepositMoney(accFrom, 400);
	Money initialTotal = calculateTotalMoney(*bank, accounts);
	bank->SendMoney(accFrom, accTo, 150);
	EXPECT_EQ(bank->GetAccountBalance(accFrom), 400 - 150);
	EXPECT_EQ(bank->GetAccountBalance(accTo), 150);
	Money newTotal = calculateTotalMoney(*bank, accounts);
	EXPECT_EQ(newTotal, initialTotal);
}

TEST_F(BankTest, TrySendMoneyInsufficientFunds)
{
	AccountId accFrom = bank->OpenAccount();
	AccountId accTo = bank->OpenAccount();
	std::vector<AccountId> accounts = { accFrom, accTo };
	bank->DepositMoney(accFrom, 50);
	Money initialTotal = calculateTotalMoney(*bank, accounts);
	bool result = bank->TrySendMoney(accFrom, accTo, 100);
	EXPECT_FALSE(result);
	EXPECT_EQ(bank->GetAccountBalance(accFrom), 50);
	EXPECT_EQ(bank->GetAccountBalance(accTo), 0);
	Money newTotal = calculateTotalMoney(*bank, accounts);
	EXPECT_EQ(newTotal, initialTotal);
}

TEST_F(BankTest, NegativeTransferAmountThrows)
{
	AccountId accFrom = bank->OpenAccount();
	AccountId accTo = bank->OpenAccount();
	EXPECT_THROW(bank->SendMoney(accFrom, accTo, -10), NegativeTransferAmountException);
}

TEST_F(BankTest, GetAccountBalanceNonExistentAccountThrows)
{
	EXPECT_THROW(bank->GetAccountBalance(9999), AccountExistenceException);
}

TEST_F(BankTest, DepositMoneyNonExistentAccountThrows)
{
	EXPECT_THROW(bank->DepositMoney(9999, 100), AccountExistenceException);
}

TEST_F(BankTest, WithdrawMoneyInsufficientFunds)
{
	AccountId acc = bank->OpenAccount();
	bank->DepositMoney(acc, 100);
	std::vector<AccountId> accounts = { acc };
	Money initialTotal = calculateTotalMoney(*bank, accounts);
	EXPECT_THROW(bank->WithdrawMoney(acc, 200), NotEnoughMoneyException);
	Money newTotal = calculateTotalMoney(*bank, accounts);
	EXPECT_EQ(newTotal, initialTotal);
}

TEST_F(BankTest, TryWithdrawMoneyInsufficientFunds)
{
	AccountId acc = bank->OpenAccount();
	bank->DepositMoney(acc, 80);
	std::vector<AccountId> accounts = { acc };
	Money initialTotal = calculateTotalMoney(*bank, accounts);
	bool result = bank->TryWithdrawMoney(acc, 150);
	EXPECT_FALSE(result);
	EXPECT_EQ(bank->GetAccountBalance(acc), 80);
	Money newTotal = calculateTotalMoney(*bank, accounts);
	EXPECT_EQ(newTotal, initialTotal);
}

TEST_F(BankTest, CloseAccountTransfersFundsToCash)
{
	AccountId acc = bank->OpenAccount();
	bank->DepositMoney(acc, 250);
	Money cashBeforeClose = bank->GetCash();
	Money balance = bank->GetAccountBalance(acc);
	Money closedAmount = bank->CloseAccount(acc);
	EXPECT_EQ(closedAmount, balance);
	EXPECT_EQ(bank->GetCash(), cashBeforeClose + balance);
	EXPECT_THROW(bank->GetAccountBalance(acc), AccountExistenceException);
}

TEST_F(BankTest, DepositMoreThanCashThrows)
{
	AccountId acc = bank->OpenAccount();
	EXPECT_THROW(bank->DepositMoney(acc, 2000), NotEnoughMoneyException);
}

TEST_F(BankTest, NegativeWithdrawThrows)
{
	AccountId acc = bank->OpenAccount();
	EXPECT_THROW(bank->WithdrawMoney(acc, -50), NegativeTransferAmountException);
}

TEST_F(BankTest, NegativeDepositThrows)
{
	AccountId acc = bank->OpenAccount();
	EXPECT_THROW(bank->DepositMoney(acc, -50), NegativeTransferAmountException);
}

TEST_F(BankTest, TransferToClosedAccountThrows)
{
	AccountId accFrom = bank->OpenAccount();
	AccountId accTo = bank->OpenAccount();
	bank->DepositMoney(accFrom, 100);
	[[maybe_unused]] Money resultMoney = bank->CloseAccount(accTo);
	EXPECT_THROW(bank->SendMoney(accFrom, accTo, 50), AccountExistenceException);
}

TEST_F(BankTest, TransferFromClosedAccountThrows)
{
	AccountId accFrom = bank->OpenAccount();
	AccountId accTo = bank->OpenAccount();
	bank->DepositMoney(accFrom, 100);
	[[maybe_unused]] Money resultMoney = bank->CloseAccount(accFrom);
	EXPECT_THROW(bank->SendMoney(accFrom, accTo, 50), AccountExistenceException);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
