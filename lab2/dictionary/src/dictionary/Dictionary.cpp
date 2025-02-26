//
// Created by smmm on 12.03.2025.
//

#include "Dictionary.h"

#include <utility>

Dictionary::Dictionary(dictionaryType dictionary)
	: m_dictionary(std::move(dictionary))
{
}

Dictionary::Dictionary()
	: m_dictionary(dictionaryType{})
{
}

void Dictionary::Store(const keyType& key, const std::string& word)
{
	const auto it = m_dictionary.find(key);
	if (it == m_dictionary.end())
		m_dictionary[key] = { word };
	else
		m_dictionary[key].insert(word);
}

std::optional<valueType> Dictionary::Get(const keyType& key)
{
	const auto it = m_dictionary.find(key);
	if (it == m_dictionary.end())
		return std::nullopt;
	else
		return it->second;
}