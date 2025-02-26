//
// Created by smmm on 03.03.2025.
//

#include "HtmlDecode.h"

#include <algorithm>
#include <fstream>
#include <map>
#include <memory>

constexpr char htmlEntityStartChar = '&';
constexpr char htmlEntityEndChar = ';';

std::map<std::string, std::string> rule{
	{ "quot", "\"" },
	{ "apos", "\'" },
	{ "lt", "<" },
	{ "gt", ">" },
	{ "amp", "&" },
};

size_t calculateMaxHtmlEntitySize();

void DecodeHtml(std::istream& inStream, std::ostream& outStream)
{
	std::string line;
	while (std::getline(inStream, line))
	{
		DecodeHtmlLine(line);
		outStream << line << "\n";
	}
}

void DecodeHtmlLine(std::string& line)
{
	const size_t maxHtmlEntitySize = calculateMaxHtmlEntitySize();
	std::string result;
	size_t cursor = 0;
	size_t entityStart = 0;

	while ((entityStart = line.find(htmlEntityStartChar, cursor)) != std::string::npos)
	{
		result.append(line, cursor, entityStart - cursor);
		const size_t entityEnd = line.find(htmlEntityEndChar, entityStart + 1);

		if (entityEnd == std::string::npos)
		{
			cursor = entityStart;
			break;
		}
		if (entityEnd - entityStart > maxHtmlEntitySize)
		{
			result.append(line, cursor, entityStart - cursor + 1);
			cursor = entityStart + 1;
			continue;
		}

		std::string_view entityName(line.data() + entityStart + 1, entityEnd - entityStart - 1);

		if (auto it = rule.find(std::string(entityName)); it != rule.end())
			result.append(it->second);
		else
			result.append(line, entityStart, entityEnd - entityStart + 1);

		cursor = entityEnd + 1;
	}

	result.append(line, cursor, line.size() - cursor);

	line = std::move(result);
}

size_t calculateMaxHtmlEntitySize()
{
	const auto [maxHtmlEntityName, _] = *std::max_element(
		rule.begin(), rule.end(), [](const auto& lhs, const auto& rhs) -> bool {
			return lhs.first.size() - rhs.first.size() > 0;
		});
	return maxHtmlEntityName.length() + 2;
}
