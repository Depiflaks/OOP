//
// Created by smmm on 03.03.2025.
//
#include <iostream>
#include <map>
#include <string>
#include <string_view>

const std::map<std::string, std::string> rule{
    {"quot", "\""},
    {"apos", "\'"},
    {"lt", "<"},
    {"qt", ">"},
    {"amp", "&"},
};

std::string HtmlDecode(const std::string& html)
{
	const std::map<std::string, std::string> entities{
		{ "quot", "\"" },
		{ "apos", "'" },
		{ "lt", "<" },
		{ "gt", ">" },
		{ "amp", "&" }
	};

	std::string decoded;
	size_t pos = 0;
	const size_t length = html.length();

	while (pos < length)
	{
		if (html[pos] == '&')
		{
			constexpr size_t maxEntityLength = 4;
			const size_t entityStart = pos + 1;
			size_t remainingLength = length - entityStart;
			const size_t searchLength = std::min(maxEntityLength + 1, remainingLength);
			std::string_view searchArea(html.data() + entityStart, searchLength);

			if (const size_t semicolonPos = searchArea.find(';'); semicolonPos != std::string_view::npos)
			{
				std::string entity = html.substr(entityStart, semicolonPos);
				auto it = entities.find(entity);
				if (it != entities.end())
				{
					decoded += it->second;
					pos = entityStart + semicolonPos + 1;
					continue;
				}
			}
			decoded += '&';
			++pos;
		}
		else
		{
			decoded += html[pos];
			++pos;
		}
	}

	return decoded;
}

int main()
{
	std::string line;
	while (std::getline(std::cin, line))
	{
		std::cout << HtmlDecode(line) << '\n';
	}
	return 0;
}
