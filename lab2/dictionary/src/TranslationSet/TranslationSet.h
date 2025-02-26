//
// Created by smmm on 12.03.2025.
//

#ifndef TRANSLATIONSET_H
#define TRANSLATIONSET_H
#include <set>
#include <string>

class TranslationSet {
	static std::string ParseTranslationSetToString(const std::set<std::string>& translations);
	static std::set<std::string> FormatStringToTranslationSet(const std::string& value);
};



#endif //TRANSLATIONSET_H
