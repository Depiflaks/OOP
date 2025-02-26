//
// Created by smmm on 03.03.2025.
//

#include "replace.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>

const char htmlEntityStart = '&';
const char htmlEntityEnd = ';';

const std::map<std::string, std::string> rule{
    {"quot", "\""},
    {"apos", "\'"},
    {"lt", "<"},
    {"qt", ">"},
    {"amp", "&"},
};

void ReplaceInStream(const ReplaceConfig& config, std::istream& inStream, std::ostream& outStream)
{
	std::string line;
	bool hasContent = false;

	while (std::getline(inStream, line))
	{
		hasContent = true;
		if (!config.search.empty())
			ReplaceInLine(config, line);
		outStream << line << "\n";
	}

	if (!hasContent)
		outStream << "\n";
}

void ReplaceInLine(const ReplaceConfig& config, std::string& line)
{
	std::string result;
	size_t pos = 0, last_pos = 0;

	while ((pos = line.find(htmlEntityStart, last_pos)) != std::string::npos)
	{
		result.append(line, last_pos, pos - last_pos);
		result.append(config.replace);
		last_pos = pos + config.search.length();
	}

	result.append(line, last_pos, line.size() - last_pos);
	line = std::move(result);
}
