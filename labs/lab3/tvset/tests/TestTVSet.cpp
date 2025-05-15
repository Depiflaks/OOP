//
// Created by smmm on 15.05.2025.
//

#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "TVSet.h"
#include "exception/TVSetError.h"

class TVSetTest : public ::testing::Test {
protected:
    TVSet tv;
    std::stringstream buffer;
    std::streambuf* oldCout = nullptr;

    void SetUp() override {
        oldCout = std::cout.rdbuf(buffer.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(oldCout);
    }

    std::string GetOutput() {
        return buffer.str();
    }

    void ClearOutput() {
        buffer.str("");
        buffer.clear();
    }
};

TEST_F(TVSetTest, TVIsOffByDefault) {
    tv.Info();
    EXPECT_NE(GetOutput().find("TV is turned off"), std::string::npos);
}

TEST_F(TVSetTest, TurnOnPrintsStatus) {
    tv.TurnOn();
    EXPECT_NE(GetOutput().find("TV is turned on"), std::string::npos);
}

TEST_F(TVSetTest, TurnOffPrintsStatus) {
    tv.TurnOn();
    ClearOutput();
    tv.TurnOff();
    EXPECT_NE(GetOutput().find("TV is turned off"), std::string::npos);
}

TEST_F(TVSetTest, SelectChannelWhenTVIsOffPrintsPowerStatus) {
    tv.SelectChannel(5);
    EXPECT_NE(GetOutput().find("TV is turned off"), std::string::npos);
}

TEST_F(TVSetTest, SelectChannelWhenTVIsOnChangesChannelAndPrints) {
    tv.TurnOn();
    ClearOutput();
    tv.SelectChannel(7);
    std::string out = GetOutput();
    EXPECT_NE(out.find("Channel switched to: 7"), std::string::npos);
}

TEST_F(TVSetTest, InfoWhenTVOnPrintsChannelTwice) {
    tv.TurnOn();
    ClearOutput();
    tv.Info();
    std::string out = GetOutput();
    int count = std::count(out.begin(), out.end(), '\n');
    EXPECT_EQ(count, 2);
}

TEST_F(TVSetTest, InfoWhenTVOffPrintsChannelOnce) {
    tv.TurnOff();
    ClearOutput();
    tv.Info();
    std::string out = GetOutput();
    int count = std::count(out.begin(), out.end(), '\n');
    EXPECT_EQ(count, 1);
}

TEST_F(TVSetTest, SelectInvalidChannelThrows) {
    tv.TurnOn();
    EXPECT_THROW(tv.SelectChannel(0), ChannelOutOfRangeError);
    EXPECT_THROW(tv.SelectChannel(101), ChannelOutOfRangeError);
}
