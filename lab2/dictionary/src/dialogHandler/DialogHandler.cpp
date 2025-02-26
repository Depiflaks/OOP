//
// Created by smmm on 12.03.2025.
//

#include "DialogHandler.h"
#include "../dictionary/Dictionary.h"
#include "../fileProcessor/FileProcessor.h"

#include <assert.h>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <ranges>
#include <regex>
#include <stdexcept>

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
	ProcessWord(message);
}

void DialogHandler::ProcessWord(const std::string& word)
{
	const auto maybeTranslations = m_dictionary.Get(word);
	if (maybeTranslations != std::nullopt)
	{
		const auto stringValue = FormatTranslationSetToString(*maybeTranslations);
		std::cout << stringValue << "\n";
	}
	else
	{
		m_lastWord = word;
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
	m_dictionary.Store(m_lastWord, FormatStringToTranslationSet(message));
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

std::string DialogHandler::FormatTranslationSetToString(const valueType& value)
{
	return std::accumulate(
		std::begin(value),
		std::end(value),
		std::string{},
		[](const auto& a, const auto& b) {
			return a + wordSeparator + b;
		});
}

valueType DialogHandler::FormatStringToTranslationSet(const keyType& value)
{
	auto values = std::ranges::views::split(value, ',');
	return valueType{ values.begin(), values.end() };
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

void DialogHandler::PrintUnknownWord() const
{
	std::cout << "Unknown word \"" << m_lastWord << "\". Enter translation or empty string to refuse.";
}
