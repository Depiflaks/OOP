//
// Created by smmm on 12.03.2025.
//

#include "DictionaryReader.h"

#include "../translationSet/TranslationSet.h"

#include <cassert>
#include <fstream>
#include <optional>
#include <stdexcept>
#include <utility>

DictionaryReader::DictionaryReader(std::optional<std::string> fileName)
	: m_fileName(std::move(fileName))
{
}

void DictionaryReader::ReadData(Dictionary& dict) const
{
	assert(m_fileName != std::nullopt);
	std::ifstream file(*m_fileName);
	// AssertFileCouldBeOpened(file);
	LoadFromStream(file, dict);
	// AssertFileNotEmpty(file);
}

void DictionaryReader::WriteData(Dictionary& dict) const
{
	assert(m_fileName != std::nullopt);
	std::ofstream file(*m_fileName, std::ios::trunc);
	SaveToStream(file, dict);
}

void DictionaryReader::LoadFromStream(std::istream& input, Dictionary& dict)
{
	std::string line;
	while (std::getline(input, line))
	{
		if (line.empty() || line[0] == '#')
			continue;

		const size_t delimiterPos = line.find('=');
		if (delimiterPos == std::string::npos)
			continue;

		const std::string key = line.substr(0, delimiterPos);
		const std::string valuesStr = line.substr(delimiterPos + 1);

		auto translations = TranslationSet::ParseStringToTranslationSet(valuesStr);
		dict.Store(key, translations);
	}
}

void DictionaryReader::SaveToStream(std::ofstream& output, const Dictionary& dict) const
{
	const DictionaryType& data = dict.GetDictionary();

	for (const auto& [key, translations] : data)
	{
		output << key << '='
			   << TranslationSet::FormatTranslationSet(translations)
			   << '\n';
	}
}

bool DictionaryReader::IsFileNameEmpty() const
{
	return m_fileName == std::nullopt;
}

void DictionaryReader::SetFileName(const std::string& fileName)
{
	m_fileName = fileName;
}

void DictionaryReader::AssertFileCouldBeOpened(std::ifstream& file)
{
	if (!file.is_open())
		throw std::runtime_error("File could not be opened");
}

void DictionaryReader::AssertFileNotEmpty(const std::ifstream& file)
{
	if (file.eof())
		throw std::runtime_error("File is empty");
}

void DictionaryReader::AssertExpectedFileData(const std::ifstream& file)
{
	if (file.fail())
		throw std::runtime_error("Invalid format of file data");
}