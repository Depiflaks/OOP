//
// Created by smmm on 12.03.2025.
//

#include "DialogHandler.h"
#include "../dictionary/Dictionary.h"
#include "../fileProcessor/FileProcessor.h"
#include <iostream>
#include <regex>
#include <stdexcept>

DialogHandler::DialogHandler(const std::string& fileName)
	: m_fileProcessor(FileProcessor<dictionaryType>{ fileName })
{
}

DialogState DialogHandler::HandleMessage(const std::string& message)
{
	switch (m_state)
	{
	case DialogState::waitForWordOrCommand:
		ProcessWordOrCommand(message);
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

void DialogHandler::ProcessWordOrCommand(const std::string& message)
{
	if (message.empty())
		return;
	if (message == k_exitCommand)
	{
		PrintSaveConfirmationPrompt();
		m_state = DialogState::waitForSaveConfirmation;
		return;
	}
	m_lastWord = message;
	if ()
	// todo: проверить, есть ли сообщение в словаре
}

void DialogHandler::ProcessTranslation(const std::string& message)
{
	if (message.empty())
	{
		PrintWordIgnored(message);
		return;
	}
	// todo: сделать запись в словарь
	m_state = DialogState::waitForWordOrCommand;
}

void DialogHandler::ProcessSaveConfirmation(const std::string& message)
{
	if (!message.empty() && std::tolower(message[0]) == 'y')
	{
		// todo: проверка на то, указан ли файл.
	}
	else
	{
		m_state = DialogState::waitForWordOrCommand;
	}
}

void DialogHandler::ProcessFileName(const std::string& message)
{
	if (message.empty())
	{
		PrintSaveCancelled();
		m_state = DialogState::waitForWordOrCommand;
		return;
	}
	// todo: сохранить файл с соответствующим названием
	m_state = DialogState::exit;
}

void DialogHandler::PrintSaveConfirmationPrompt()
{
	std::cout << "The dictionary has been modified. Enter Y or y to save before exiting.\n";
}

void DialogHandler::PrintWordIgnored(const std::string& word)
{
	std::cout << "The word \"" << word << "\" has been ignored.\n";
}

void DialogHandler::PrintSaveCancelled()
{
	std::cout << "Save operation cancelled. Continuing work with the dictionary.\n";
}