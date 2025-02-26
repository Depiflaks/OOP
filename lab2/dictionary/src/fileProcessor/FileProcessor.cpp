//
// Created by smmm on 12.03.2025.
//

#include "FileProcessor.h"

#include <cassert>
#include <fstream>
#include <optional>
#include <stdexcept>
#include <utility>

template <typename readType>
FileProcessor<readType>::FileProcessor(std::string fileName)
	: m_fileName(std::move(fileName))
{
}

template <typename readType>
readType FileProcessor<readType>::ReadData() const
{
	assert(!m_fileName.empty());
	std::ifstream file(m_fileName);
	AssertFileCouldBeOpened(file);
	readType data;
	file >> data;
	AssertFileNotEmpty(file);
	AssertExpectedFileData(file);
	return data;
}

template <typename readType>
void FileProcessor<readType>::WriteData(const readType& data) const
{
	assert(!m_fileName.empty());
	std::ifstream file(m_fileName, std::ios::trunc);
	AssertFileCouldBeOpened(file);
	file << data;
}

template <typename readType>
bool FileProcessor<readType>::IsFileNameEmpty() const
{
	return m_fileName.empty();
}

template <typename readType>
void FileProcessor<readType>::SetFileName(std::string)
{
	m_fileName = std::move(std::string(m_fileName));
}

template <typename readType>
void FileProcessor<readType>::AssertFileCouldBeOpened(std::ifstream& file)
{
	if (!file.is_open())
		throw std::runtime_error("File could not be opened");
}

template <typename readType>
void FileProcessor<readType>::AssertFileNotEmpty(const std::ifstream& file)
{
	if (file.eof())
		throw std::runtime_error("File is empty");
}

template <typename readType>
void FileProcessor<readType>::AssertExpectedFileData(const std::ifstream& file)
{
	if (file.fail())
		throw std::runtime_error("Invalid format of file data");
}