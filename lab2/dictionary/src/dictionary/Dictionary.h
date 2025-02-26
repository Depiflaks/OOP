//
// Created by smmm on 12.03.2025.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <map>
#include <optional>
#include <set>
#include <string>

using DictionaryType = std::map<std::string, std::set<std::string>>;

class Dictionary
{
public:
	explicit Dictionary(DictionaryType dictionary);
	explicit Dictionary();
	void Store(const std::string& key, const std::set<std::string>& translations, bool withMirrorRecording = true);
	std::optional<std::set<std::string>> Get(const std::string& key);

private:
	DictionaryType m_dictionary{};
};

#endif // DICTIONARY_H
