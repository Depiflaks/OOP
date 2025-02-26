//
// Created by smmm on 12.03.2025.
//

#ifndef DIALOGHANDLER_H
#define DIALOGHANDLER_H
#include <string>

namespace DialogMessages
{
const std::string SaveConfirmationPrompt = "The dictionary has been modified. Enter Y or y to save before exiting.\n";

const std::string WordIgnored = "The word \"{}\" has been ignored.\n";

const std::string SaveCancelled = "Save operation cancelled. Continuing work with the dictionary.\n";
} // namespace DialogMessages

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
	DialogState HandleMessage(const std::string& message);

private:
	DialogState m_state{ DialogState::waitForWordOrCommand };
	std::string m_lastWord;

	void ProcessWordOrExitCommand(const std::string& message);
	void ProcessTranslation(const std::string& message);
	void ProcessSaveConfirmation(const std::string& message);
	void ProcessFileName(const std::string& message);

	static void PrintSaveConfirmationPrompt();
	static void PrintWordIgnored(const std::string& word);
	static void PrintSaveCancelled();
};

#endif // DIALOGHANDLER_H
