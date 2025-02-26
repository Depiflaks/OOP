//
// Created by smmm on 12.03.2025.
//

#ifndef DIALOGHANDLER_H
#define DIALOGHANDLER_H
#include "../dictionary/Dictionary.h"
#include "../fileProcessor/FileProcessor.h"

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

constexpr std::string wordSeparator = ", ";

class DialogHandler
{
public:
	explicit DialogHandler(const std::string& fileName);
	DialogState HandleMessage(const std::string& message);
	void ProcessWord(const std::string& word);

private:
	Dictionary m_dictionary;
	FileProcessor<DictionaryType> m_fileProcessor;

	DialogState m_state{ DialogState::waitForWordOrCommand };
	std::string m_lastWord;
	static constexpr std::string_view k_exitCommand{ "..." };

	void ProcessWordOrCommand(const std::string& message);
	void ProcessTranslation(const std::string& message);
	void ProcessSaveConfirmation(const std::string& message);
	void ProcessFileName(const std::string& message);

	static std::string FormatTranslationSetToString(const std::set<std::string>& translations);
	static std::set<std::string> FormatStringToTranslationSet(const std::string& value);

	static void PrintSaveConfirmationPrompt();
	static void PrintWordIgnored(const std::string& word);
	static void PrintSaveCancelled();
	void PrintUnknownWord() const;
};

#endif // DIALOGHANDLER_H
