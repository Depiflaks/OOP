//
// Created by smmm on 12.03.2025.
//

#include "DictionaryReader.h"

#include <cassert>
#include <fstream>
#include <optional>
#include <stdexcept>
#include <utility>

DictionaryReader::DictionaryReader(std::optional<std::string> fileName)
	: m_fileName(std::move(fileName))
{
}

DictionaryType DictionaryReader::ReadData() const
{
	assert(m_fileName != std::nullopt);
	std::ifstream file(*m_fileName);
	AssertFileCouldBeOpened(file);
	DictionaryType data;
	// file >> data;
	AssertFileNotEmpty(file);
	AssertExpectedFileData(file);
	return data;
}

void DictionaryReader::WriteData(const DictionaryType& data) const
{
	assert(m_fileName != std::nullopt);
	std::ifstream file(*m_fileName, std::ios::trunc);
	AssertFileCouldBeOpened(file);
	// file << data;
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