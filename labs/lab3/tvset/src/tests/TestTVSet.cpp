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
    EXPECT_NE(GetOutput().find("Channel is: 0"), std::string::npos);
}

TEST_F(TVSetTest, TurnOnEnablesTV) {
    tv.TurnOn();
    tv.Info();
    std::string out = GetOutput();
    EXPECT_NE(out.find("Channel is: 0"), std::string::npos);
}

TEST_F(TVSetTest, TurnOffDisablesTV) {
    tv.TurnOn();
    tv.TurnOff();
    tv.Info();
    EXPECT_NE(GetOutput().find("Channel is: 0"), std::string::npos);
}

TEST_F(TVSetTest, SelectChannelWhenTVIsOffDoesNothing) {
    tv.SelectChannel(5);
    tv.Info();
    EXPECT_EQ(GetOutput().find("Channel is: 5"), std::string::npos);
}

TEST_F(TVSetTest, SelectChannelWhenTVIsOnChangesChannel) {
    tv.TurnOn();
    tv.SelectChannel(5);
    tv.Info();
    std::string out = GetOutput();
    EXPECT_NE(out.find("Channel is: 5"), std::string::npos);
}

TEST_F(TVSetTest, SelectInvalidChannelThrows) {
    tv.TurnOn();
    EXPECT_THROW(tv.SelectChannel(0), ChannelOutOfRangeError);
    EXPECT_THROW(tv.SelectChannel(101), ChannelOutOfRangeError);
}

TEST_F(TVSetTest, SelectValidChannelDoesNotThrow) {
    tv.TurnOn();
    EXPECT_NO_THROW(tv.SelectChannel(1));
    EXPECT_NO_THROW(tv.SelectChannel(100));
}
