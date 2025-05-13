//
// Created by smmm on 19.03.2025.
//
#include "../src/actor/Actor.h"
#include <gtest/gtest.h>

class ActorTests : public ::testing::Test {
protected:
    Bank bank{150};
    Actor actor{bank, 100};
    Actor otherActor{bank, 50};
};

TEST_F(ActorTests, GetAccountBalance_NoAccount_ThrowsException) {
    EXPECT_THROW(actor.GetAccountBalance(), ActorNotHaveAccountException);
}

TEST_F(ActorTests, GetCashBalance_ReturnsCorrectValue) {
    EXPECT_EQ(actor.GetCashBalance(), 100);
}

TEST_F(ActorTests, OpenAccount_SetsAccountId) {
    actor.OpenAccount();
    EXPECT_TRUE(actor.GetAccountId().has_value());
}

TEST_F(ActorTests, DepositMoney_UpdatesBalances) {
    actor.OpenAccount();
    actor.DepositMoney(50);
    EXPECT_EQ(actor.GetCashBalance(), 50);
    EXPECT_EQ(actor.GetAccountBalance(), 50);
}

TEST_F(ActorTests, WithdrawMoney_UpdatesBalances) {
    actor.OpenAccount();
    actor.DepositMoney(50);
    actor.WithdrawMoney(30);
    EXPECT_EQ(actor.GetCashBalance(), 80);
    EXPECT_EQ(actor.GetAccountBalance(), 20);
}

TEST_F(ActorTests, TransferMoney_ValidTransaction_UpdatesBalances) {
    actor.OpenAccount();
    otherActor.OpenAccount();
    actor.DepositMoney(100);
    actor.TransferMoney(otherActor, 40);
    EXPECT_EQ(actor.GetAccountBalance(), 60);
    EXPECT_EQ(otherActor.GetAccountBalance(), 40);
}

TEST_F(ActorTests, HandOverMoney_ValidTransaction_UpdatesBalances) {
    actor.HandOverMoney(otherActor, 30);
    EXPECT_EQ(actor.GetCashBalance(), 70);
    EXPECT_EQ(otherActor.GetCashBalance(), 80);
}

TEST_F(ActorTests, ExtortMoney_ValidTransaction_UpdatesBalances) {
    otherActor.ExtortMoney(actor, 20);
    EXPECT_EQ(actor.GetCashBalance(), 80);
    EXPECT_EQ(otherActor.GetCashBalance(), 70);
}


TEST_F(ActorTests, CloseAccount_TransfersRemainingBalance) {
    actor.OpenAccount();
    actor.DepositMoney(50);
    actor.CloseAccount();
    EXPECT_EQ(actor.GetCashBalance(), 100);
    EXPECT_FALSE(actor.GetAccountId().has_value());
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
