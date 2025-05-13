//
// Created by smmm on 12.03.2025.
//

#ifndef DIALOGHANDLER_H
#define DIALOGHANDLER_H
#include "../dictionary/Dictionary.h"
#include "../dictionaryReader/DictionaryReader.h"
#include "../translationSet/TranslationSet.h"

#include <iostream>
#include <numeric>
#include <ranges>
#include <string>

enum class DialogState
{
	waitForWordOrCommand,
	waitForTranslation,
	waitForSaveConfirmation,
	waitForFileName,
	exit
};

class DialogHandler
{
public:
	explicit DialogHandler(const std::optional<std::string>& fileName);
	DialogState HandleMessage(const std::string& message);

private:
	Dictionary m_dictionary;
	DictionaryReader m_dictionaryReader;

	DialogState m_state{ DialogState::waitForWordOrCommand };
	std::string m_keyWord;
	bool m_hasDictionaryChanged{ false };
	static constexpr std::string_view k_exitCommand{ "..." };
	static constexpr char k_saveConfirmationChar = 'y';

	void ProcessWordOrCommand(const std::string& message);
	void ProcessExitCommand();
	void ProcessWord(const std::string& word);
	void PrintWordSaved(const std::string& message) const;
	void ProcessTranslation(const std::string& message);
	void ProcessSaveConfirmation(const std::string& message);
	void ProcessFileName(const std::string& message);
	void SaveDictionary();

	static void PrintSaveConfirmationPrompt();
	static void PrintWordIgnored(const std::string& word);
	static void PrintSaveCancelled();
	static void PrintWaitingForFileNamePrompt();
	void PrintUnknownWord() const;
};

#endif // DIALOGHANDLER_H
