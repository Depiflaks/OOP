//
// Created by smmm on 12.03.2025.
//

#include "Dictionary.h"

#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <utility>
#include <cctype>

Dictionary::Dictionary(DictionaryType dictionary)
	: m_dictionary(std::move(dictionary))
{
}

Dictionary::Dictionary()
	: m_dictionary(DictionaryType{})
{
}

void Dictionary::Store(
	const std::string& key,
	const std::set<std::string>& translations)
{
	const auto lowerKey = ToLower(key);
	const auto lowerTranslations = ToLowerSet(translations);
	InsertWords(lowerKey, lowerTranslations);
	for (const auto& translation : lowerTranslations)
		InsertWords(translation, std::set{ lowerKey });
}

void Dictionary::InsertWords(const std::string& key, const std::set<std::string>& translations)
{
	AssertEmptyKey(key);
	AssertEmptyTranslationSet(translations);
	AssertTranslationContainsEmptyLines(translations);
	const auto it = m_dictionary.find(key);
	if (it == m_dictionary.end())
		m_dictionary[key] = {};
	m_dictionary[key].insert(translations.begin(), translations.end());
}

std::string Dictionary::ToLower(const std::string& str) {
    std::string result;
    result.reserve(str.size());

    for (const unsigned char c : str) {
        result.push_back(std::tolower(c));
    }
    return result;
}

std::set<std::string> Dictionary::ToLowerSet(const std::set<std::string>& input) {
    std::set<std::string> result;

    for (const auto& str : input) {
        result.insert(ToLower(str));
    }

    return result;
}

std::optional<std::set<std::string>> Dictionary::Find(const std::string& key)
{
	const auto lowerKey = ToLower(key);
	AssertEmptyKey(lowerKey);
	const auto it = m_dictionary.find(lowerKey);
	if (it == m_dictionary.end())
		return std::nullopt;
	return it->second;
}

DictionaryType Dictionary::GetDictionary() const
{
	return m_dictionary;
}

void Dictionary::AssertEmptyKey(const std::string& key)
{
	if (key.empty())
		throw std::invalid_argument("Key must not be empty");
}

void Dictionary::AssertEmptyTranslationSet(const std::set<std::string>& translations)
{
	if (translations.empty())
		throw std::invalid_argument("Translation set is empty");
}

void Dictionary::AssertTranslationContainsEmptyLines(const std::set<std::string>& translations)
{
	if (std::find(translations.begin(), translations.end(), "") != translations.end())
		throw std::invalid_argument("Translation set contains empty line");
}