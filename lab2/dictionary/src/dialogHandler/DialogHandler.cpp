//
// Created by smmm on 12.03.2025.
//

#include "DialogHandler.h"

#include <stdexcept>

DialogState DialogHandler::HandleMessage(std::string& message) const
{
	switch (m_state)
	{
	case DialogState::waitForWordOrExitCommand:
		ProcessWordOrExitCommand(message);
		break;
	case DialogState::waitForTranslation:
		ProcessTranslation(message);
		break;
	case DialogState::waitForSaveConfirmation:
		ProcessSaveConfirmation(message);
		break;
	case DialogState::waitForFileName:
		ProcessFileName(message);
		break;
	default:
		throw std::logic_error("Invalid state");
	}
	return m_state;
}

void DialogHandler::ProcessWordOrExitCommand(std::string& message)
{

}

void DialogHandler::ProcessFileName(std::string& message)
{
}

void DialogHandler::ProcessSaveConfirmation(std::string& message)
{
}

void DialogHandler::ProcessTranslation(std::string& message)
{
}
