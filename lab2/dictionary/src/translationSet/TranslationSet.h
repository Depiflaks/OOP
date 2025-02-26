//
// Created by smmm on 12.03.2025.
//

#ifndef TRANSLATIONSET_H
#define TRANSLATIONSET_H
#include <set>
#include <string>

constexpr std::string wordSeparator = ", ";

class TranslationSet {
public:
	static std::string FormatTranslationSet(const std::set<std::string>& translations);
	static std::set<std::string> ParseStringToTranslationSet(const std::string& value);
};


#endif //TRANSLATIONSET_H
