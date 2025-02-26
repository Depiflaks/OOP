//
// Created by smmm on 12.03.2025.
//

#include "TranslationSet.h"

#include <numeric>
#include <ranges>

std::string TranslationSet::FormatTranslationSet(const std::set<std::string>& translations)
{
	return std::accumulate(
		std::begin(translations),
		std::end(translations),
		std::string{},
		[](const auto& a, const auto& b) {
			return a + wordSeparator + b;
		});
}

std::set<std::string> TranslationSet::ParseStringToTranslationSet(const std::string& value)
{
	auto values = std::ranges::views::split(value, ',');
	return std::set<std::string>{ values.begin(), values.end() };
}
