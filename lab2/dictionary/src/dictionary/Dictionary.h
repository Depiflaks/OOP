//
// Created by smmm on 12.03.2025.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <map>
#include <optional>
#include <set>
#include <string>

using keyType = std::string;
using valueType = std::set<keyType>;
using dictionaryType = std::map<keyType, valueType>;

class Dictionary
{
public:
	explicit Dictionary(dictionaryType dictionary);
	explicit Dictionary();
	void Dictionary::Store(const keyType& key, const valueType& translations, bool withMirrorRecording = true);
	std::optional<valueType> Get(const keyType& key);

private:
	dictionaryType m_dictionary{};
};

#endif // DICTIONARY_H
