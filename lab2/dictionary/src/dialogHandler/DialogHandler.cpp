//
// Created by smmm on 12.03.2025.
//

#include "DialogHandler.h"

#include <iostream>
#include <stdexcept>

DialogState DialogHandler::HandleMessage(std::string& message)
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

void DialogHandler::ProcessWordOrExitCommand(const std::string& message)
{
	if (message.empty())
		return;
	if (message == "...")
	{
		std::cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.";
		m_state = DialogState::waitForSaveConfirmation;
		return;
	}
	m_lastWord = message;
	// todo: проверить, есть ли сообщение в словаре
}

void DialogHandler::ProcessTranslation(const std::string& message)
{
	if (message.empty())
	{
		std::cout << "Слово \"" << m_lastWord << "\" проигнорировано.";
		return;
	}
	// todo: сделать запись в словарь
	m_state = DialogState::waitForWordOrExitCommand;
}

void DialogHandler::ProcessSaveConfirmation(const std::string& message)
{
	if (!message.empty() && std::tolower(message[0]) == 'y')
	{
		// todo: проверка на то, указан ли файл.
	} else
	{
		m_state = DialogState::waitForWordOrExitCommand;
	}
}

void DialogHandler::ProcessFileName(const std::string& message)
{
	if (message.empty())
	{
		std::cout << "Операция сохранения отменена. Продолжаение работы со словарём";
		m_state = DialogState::waitForWordOrExitCommand;
		return;
	}
	// todo: сохранить файл с соответствующим названием
	m_state = DialogState::exit;
}
