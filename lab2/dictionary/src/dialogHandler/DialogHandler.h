//
// Created by smmm on 12.03.2025.
//

#ifndef DIALOGHANDLER_H
#define DIALOGHANDLER_H
#include "../dictionary/Dictionary.h"
#include "../fileProcessor/FileProcessor.h"

#include <iostream>
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

private:
	Dictionary m_dictionary;
	FileProcessor<dictionaryType> m_fileProcessor;

	DialogState m_state{ DialogState::waitForWordOrCommand };
	std::string m_lastWord;
	constexpr std::string_view k_exitCommand{ "..." };

	void ProcessWordOrCommand(const std::string& message);
	void ProcessTranslation(const std::string& message);
	void ProcessSaveConfirmation(const std::string& message);
	void ProcessFileName(const std::string& message);

	static std::string ConvertDictValueToString(const valueType& value);
	static valueType ConvertStringToDictValue(const std::string& value);

	static void DialogHandler::PrintSaveConfirmationPrompt()
	{
		std::cout << "The dictionary has been modified. Enter Y or y to save before exiting.\n";
	}

	static void DialogHandler::PrintWordIgnored(const std::string& word)
	{
		std::cout << "The word \"" << word << "\" has been ignored.\n";
	}

	static void DialogHandler::PrintSaveCancelled()
	{
		std::cout << "Save operation cancelled. Continuing work with the dictionary.\n";
	}

	void DialogHandler::PrintUnknownWord() const
	{
		std::cout << "Unknown word \"" << m_lastWord << "\". Enter translation or empty string to refuse.";
	}

	static void DialogHandler::PrintDictValue(const auto value)
	{
		std::cout << value << "\n";
	}
};

#endif // DIALOGHANDLER_H
