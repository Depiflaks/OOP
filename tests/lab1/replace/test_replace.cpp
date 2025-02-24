//
// Created by smmm on 26.02.2025.
//

#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "test_replace.h"

const std::string EXECUTABLE = "/main";

std::string executeCommand(const std::string &command) {
	std::ostringstream result;
	FILE *pipe = popen(command.c_str(), "r");
	if (!pipe) return "ERROR";
	char buffer[128];
	while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
		result << buffer;
	}
	pclose(pipe);
	return result.str();
}

// Test: help flag
TEST(ReplaceTest, HelpMessage) {
	std::string command = EXECUTABLE + " -h";
	std::string output = executeCommand(command);

	EXPECT_TRUE(output.find("Usage") != std::string::npos);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}