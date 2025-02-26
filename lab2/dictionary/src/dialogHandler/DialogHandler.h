//
// Created by smmm on 12.03.2025.
//

#ifndef DIALOGHANDLER_H
#define DIALOGHANDLER_H
#include <string>

enum class DialogState
{
	waitForWordOrExitCommand = 1,
	waitForTranslation = 2,
	waitForSaveConfirmation = 3,
	waitForFileName = 4,
	exit = 0
};

class DialogHandler
{
public:
	DialogState HandleMessage(std::string& message);

private:
	DialogState m_state{ DialogState::waitForWordOrExitCommand };
	std::string m_lastWord;

	void ProcessWordOrExitCommand(const std::string& message);
	void ProcessTranslation(const std::string& message);
	void ProcessSaveConfirmation(const std::string& message);
	void ProcessFileName(const std::string& message);
};

#endif // DIALOGHANDLER_H
