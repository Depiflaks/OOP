//
// Created by smmm on 12.03.2025.
//

#ifndef DIALOGHANDLER_H
#define DIALOGHANDLER_H
#include "../dictionary/Dictionary.h"
#include "../fileProcessor/FileProcessor.h"

#include <string>

enum class DialogState
{
	waitForWordOrCommand = 1,
	waitForTranslation = 2,
	waitForSaveConfirmation = 3,
	waitForFileName = 4,
	exit = 0
};

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
	const std::string k_exitCommand{ "..." };

	void ProcessWordOrCommand(const std::string& message);
	void ProcessTranslation(const std::string& message);
	void ProcessSaveConfirmation(const std::string& message);
	void ProcessFileName(const std::string& message);

	static std::string ConvertDictValueToString(const valueType& value);
	static valueType ConvertStringToDictValue(const std::string& value);

	static void PrintSaveConfirmationPrompt();
	static void PrintWordIgnored(const std::string& word);
	static void PrintSaveCancelled();
	void PrintUnknownWord() const;
	static void PrintDictValue(auto& value);
};

#endif // DIALOGHANDLER_H
