//
// Created by smmm on 12.03.2025.
//

#include "DialogHandler.h"
#include "../dictionary/Dictionary.h"
#include "../dictionaryReader/DictionaryReader.h"

#include <cassert>
#include <iostream>
#include <ranges>
#include <regex>
#include <stdexcept>

DialogHandler::DialogHandler(const std::optional<std::string>& fileName)
	: m_dictionaryReader(DictionaryReader{ fileName })
{
	if (m_dictionaryReader.IsFileNameEmpty())
	{
		m_dictionary = Dictionary();
	}
	else
	{
		const auto data = m_dictionaryReader.ReadData();
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
		ProcessExitCommand();
		return;
	}
	ProcessWord(message);
}

void DialogHandler::ProcessExitCommand()
{
	if (!m_hasDictionaryChanged)
	{
		m_state = DialogState::exit;
	}
	else
	{
		PrintSaveConfirmationPrompt();
		m_state = DialogState::waitForSaveConfirmation;
	}
}

void DialogHandler::ProcessWord(const std::string& word)
{
	const auto maybeTranslations = m_dictionary.Find(word);
	if (maybeTranslations != std::nullopt)
	{
		const auto stringValue = TranslationSet::FormatTranslationSet(*maybeTranslations);
		std::cout << stringValue << "\n";
		m_state = DialogState::waitForWordOrCommand;
	}
	else
	{
		m_keyWord = word;
		PrintUnknownWord();
		m_state = DialogState::waitForTranslation;
	}
}

void DialogHandler::ProcessTranslation(const std::string& message)
{
	if (message.empty())
	{
		PrintWordIgnored(m_keyWord);
	}
	else
	{
		PrintWordSaved(message);
		m_dictionary.Store(m_keyWord, TranslationSet::ParseStringToTranslationSet(message));
		m_hasDictionaryChanged = true;
	}
	m_state = DialogState::waitForWordOrCommand;
}

void DialogHandler::ProcessSaveConfirmation(const std::string& message)
{
	if (!message.empty() && std::tolower(message[0]) == 'y')
	{
		if (m_dictionaryReader.IsFileNameEmpty())
		{
			PrintWaitingForFileNamePrompt();
			m_state = DialogState::waitForFileName;
		}
		else
			SaveDictionary();
	}
	else
		m_state = DialogState::exit;
}

void DialogHandler::SaveDictionary()
{
	m_dictionaryReader.WriteData(m_dictionary.GetDictionary());
	m_state = DialogState::exit;
}

void DialogHandler::ProcessFileName(const std::string& message)
{
	if (message.empty())
	{
		PrintSaveCancelled();
		m_state = DialogState::exit;
		return;
	}
	m_dictionaryReader.SetFileName(message);
	SaveDictionary();
}

void DialogHandler::PrintWordSaved(const std::string& message) const
{
	std::cout << "Word \"" << m_keyWord << "\" was saved as \"" << message << "\"\n";
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
	std::cout << "Save operation cancelled.\n";
}

void DialogHandler::PrintUnknownWord() const
{
	std::cout << "Unknown word \"" << m_keyWord << "\". Enter translation or empty string to refuse.\n";
}

void DialogHandler::PrintWaitingForFileNamePrompt()
{
	std::cout << "Enter file name or empty line to cancel saving \n";
}
