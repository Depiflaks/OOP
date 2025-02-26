//
// Created by smmm on 12.03.2025.
//

#ifndef TRANSLATIONSET_H
#define TRANSLATIONSET_H
#include <set>
#include <string>
#include <vector>

constexpr std::string_view wordSeparator = ", ";

struct TranslationSet
{
	static std::string FormatTranslationSet(const std::set<std::string>& translations);
	static std::string JoinSetToString(const std::set<std::string>& strings, const std::string& delimiter);
	static std::vector<std::string> Split(const std::string& str, std::string_view delimiter);
	static std::set<std::string> ParseStringToTranslationSet(const std::string& value);
};

#endif // TRANSLATIONSET_H
