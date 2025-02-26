//
// Created by smmm on 03.03.2025.
//

#include "replace.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>

constexpr char htmlEntityStart = '&';
constexpr char htmlEntityEnd = ';';

void ReplaceInStream(std::map<std::string, std::string>& rule, std::istream& inStream, std::ostream& outStream)
{
	std::string line;
	while (std::getline(inStream, line))
	{
		ReplaceInLine(rule, line);
		outStream << line << "\n";
	}
}

void ReplaceInLine(const std::map<std::string, std::string>& rule, std::string& line)
{
	std::string result;
	size_t lastPos = 0, entityStart;

	while ((entityStart = line.find(htmlEntityStart, lastPos)) != std::string::npos)
	{
		result.append(line, lastPos, entityStart - lastPos);
		const size_t entityEnd = line.find(htmlEntityEnd, entityStart + 1);

		if (entityEnd == std::string::npos)
			break;

		std::string_view entityName(line.data() + entityStart + 1, entityEnd - entityStart - 1);

		if (auto it = rule.find(std::string(entityName)); it != rule.end())
			result.append(it->second);
		else
			result.append(line, entityStart, entityEnd - entityStart + 1);

		lastPos = entityEnd + 1;
	}

	result.append(line, lastPos, line.size() - lastPos);
	line = std::move(result);
}
