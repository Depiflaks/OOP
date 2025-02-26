//
// Created by smmm on 12.03.2025.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <map>
#include <optional>
#include <set>
#include <string>

typedef std::string keyType;
typedef std::set<keyType> valueType;
typedef std::map<keyType, valueType> dictionaryType;

class Dictionary
{
public:
	explicit Dictionary(dictionaryType dictionary);
	explicit Dictionary();
	void Store(const keyType& key, const std::string& word);
	std::optional<valueType> Get(const keyType& key);

private:
	dictionaryType m_dictionary{};
};

#endif // DICTIONARY_H
