//
// Created by smmm on 12.03.2025.
//

#include "DialogHandler.h"
#include "../dictionary/Dictionary.h"
#include "../fileProcessor/FileProcessor.h"
#include <iostream>
#include <numeric>
#include <regex>
#include <stdexcept>
#include <iomanip>
#include <ranges>

DialogHandler::DialogHandler(const std::string& fileName)
	: m_fileProcessor(FileProcessor<dictionaryType>{ fileName })
{
	if (m_fileProcessor.IsFileNameEmpty())
	{
		m_dictionary = Dictionary();
	}
	else
	{
		const auto data = m_fileProcessor.ReadData();
		m_dictionary = Dictionary(data);
	}
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
	if (const auto value = m_dictionary.Get(message); value != std::nullopt)
	{
		auto stringValue = ConvertDictValueToString(value.value());
		PrintDictValue(stringValue);
	}
	else
	{
		m_lastWord = message;
		PrintUnknownWord();
		m_state = DialogState::waitForTranslation;
	}
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
		if (m_fileProcessor.IsFileNameEmpty())
		{
		}
	}
	else
	{
		m_state = DialogState::exit;
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

std::string DialogHandler::ConvertDictValueToString(const valueType& value)
{
	return std::accumulate(
		std::begin(value),
		std::end(value),
		std::string{},
		[](const auto& a, const auto& b) {
			return a + ", " + b;
		});
}

valueType DialogHandler::ConvertStringToDictValue(const std::string& value)
{
	auto values = std::ranges::views::split(value, ',');
	return valueType{values.begin(), values.end()};
}