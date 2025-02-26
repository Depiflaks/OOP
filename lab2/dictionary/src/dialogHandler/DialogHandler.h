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
	DialogState HandleMessage(std::string& message) const;

private:
	DialogState m_state{ DialogState::waitForWordOrExitCommand };

	static void ProcessWordOrExitCommand(std::string& message);
	static void ProcessTranslation(std::string& message);
	static void ProcessSaveConfirmation(std::string& message);
	static void ProcessFileName(std::string& message);
};

#endif // DIALOGHANDLER_H
