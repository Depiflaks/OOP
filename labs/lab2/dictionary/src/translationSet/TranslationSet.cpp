//
// Created by smmm on 12.03.2025.
//

#include "TranslationSet.h"

#include <numeric>
#include <ranges>
#include <vector>

std::string TranslationSet::FormatTranslationSet(const std::set<std::string>& translations)
{
	return JoinSetToString(translations, std::string(wordSeparator));
}

std::string TranslationSet::JoinSetToString(const std::set<std::string>& strings, const std::string& delimiter) {
    std::string result;
	if (auto it = strings.begin(); it != strings.end()) {
        result = *it;
        ++it;
        for (; it != strings.end(); ++it) {
            result += delimiter + *it;
        }
    }
    return result;
}

std::set<std::string> TranslationSet::ParseStringToTranslationSet(const std::string& value)
{
	auto translations = Split(value, wordSeparator);
	return std::set<std::string>{ translations.begin(), translations.end() };
}

std::vector<std::string> TranslationSet::Split(const std::string& str, const std::string_view delimiter) {
    std::vector<std::string> result;
    std::string_view sv(str);
    size_t pos = 0;
    const size_t delim_len = delimiter.length();

    while(pos < sv.length()) {
		const size_t found = sv.find(delimiter, pos);
        if(found == std::string_view::npos) {
            result.emplace_back(sv.substr(pos));
            break;
        }
        result.emplace_back(sv.substr(pos, found - pos));
        pos = found + delim_len;
    }

    return result;
}