//
// Created by smmm on 12.03.2025.
//

#include "Dictionary.h"

#include <utility>

Dictionary::Dictionary(DictionaryType dictionary)
	: m_dictionary(std::move(dictionary))
{
}

Dictionary::Dictionary()
	: m_dictionary(DictionaryType{})
{
}

void Dictionary::Store(const std::string& key, const std::set<std::string>& translations, bool withMirrorRecording)
{
	const auto it = m_dictionary.find(key);
	if (it == m_dictionary.end())
		m_dictionary[key] = {};
	m_dictionary[key].insert(translations.begin(), translations.end());
	if (!withMirrorRecording)
		return;
	for (const auto& translation : translations)
	{
		Store(translation, std::set{ key }, false);
	}
}

std::optional<std::set<std::string>> Dictionary::Get(const std::string& key)
{
	const auto it = m_dictionary.find(key);
	if (it == m_dictionary.end())
		return std::nullopt;
	else
		return it->second;
}

DictionaryType Dictionary::GetDictionary() const
{
	return m_dictionary;
}