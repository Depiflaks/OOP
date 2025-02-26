//
// Created by smmm on 12.03.2025.
//

#include "Dictionary.h"

#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <utility>

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
	const std::set<std::string>& translations,
	const bool withReverseRecording)
{
	AssertEmptyKey(key);
	AssertEmptyTranslationSet(translations);
	AssertTranslationContainsEmptyLines(translations);
	const auto it = m_dictionary.find(key);
	if (it == m_dictionary.end())
		m_dictionary[key] = {};
	m_dictionary[key].insert(translations.begin(), translations.end());
	if (withReverseRecording)
		StoreReverseTranslation(key, translations);
}

void Dictionary::StoreReverseTranslation(const std::string& key, const std::set<std::string>& translations)
{
	for (const auto& translation : translations)
	{
		Store(translation, std::set{ key }, false);
	}
}

std::optional<std::set<std::string>> Dictionary::Find(const std::string& key)
{
	AssertEmptyKey(key);
	const auto it = m_dictionary.find(key);
	if (it == m_dictionary.end())
		return std::nullopt;
	return it->second;
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

DictionaryType Dictionary::GetDictionary() const
{
	return m_dictionary;
}