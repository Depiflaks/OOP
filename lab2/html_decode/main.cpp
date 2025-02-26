//
// Created by smmm on 03.03.2025.
//
#include "src/replace.h"
#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::string> rule{
	{ "quot", "\"" },
	{ "apos", "\'" },
	{ "lt", "<" },
	{ "qt", ">" },
	{ "amp", "&" },
};

int main()
{
	ReplaceInStream(rule, std::cin, std::cout);
	return 0;
}
