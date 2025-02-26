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

	void Store(const std::string& key, const std::set<std::string>& translations);
	std::optional<std::set<std::string>> Find(const std::string& key);

	DictionaryType GetDictionary() const;

private:
	DictionaryType m_dictionary{};
	void InsertWords(const std::string& key, const std::set<std::string>& translations);
	static std::set<std::string> ToLowerSet(const std::set<std::string>& input);
	static std::string ToLower(const std::string& str);

	static void AssertEmptyKey(const std::string& key);
	static void AssertEmptyTranslationSet(const std::set<std::string>& translations);
	static void AssertTranslationContainsEmptyLines(const std::set<std::string>& translations);
};

#endif // DICTIONARY_H
