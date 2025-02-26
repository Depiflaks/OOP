//
// Created by smmm on 12.03.2025.
//

#include "FileProcessor.h"

#include <cassert>
#include <fstream>
#include <optional>
#include <stdexcept>
#include <utility>

FileProcessor::FileProcessor(std::string fileName)
	: m_fileName(std::move(fileName))
{
}

DictionaryType FileProcessor::ReadData() const
{
	assert(!m_fileName.empty());
	std::ifstream file(m_fileName);
	AssertFileCouldBeOpened(file);
	DictionaryType data;
	file >> data;
	AssertFileNotEmpty(file);
	AssertExpectedFileData(file);
	return data;
}

void FileProcessor::WriteData(const DictionaryType& data) const
{
	assert(!m_fileName.empty());
	std::ifstream file(m_fileName, std::ios::trunc);
	AssertFileCouldBeOpened(file);
	file << data;
}

bool FileProcessor::IsFileNameEmpty() const
{
	return m_fileName.empty();
}

void FileProcessor::SetFileName(std::string)
{
	m_fileName = std::move(std::string(m_fileName));
}

void FileProcessor::AssertFileCouldBeOpened(std::ifstream& file)
{
	if (!file.is_open())
		throw std::runtime_error("File could not be opened");
}

void FileProcessor::AssertFileNotEmpty(const std::ifstream& file)
{
	if (file.eof())
		throw std::runtime_error("File is empty");
}

void FileProcessor::AssertExpectedFileData(const std::ifstream& file)
{
	if (file.fail())
		throw std::runtime_error("Invalid format of file data");
}