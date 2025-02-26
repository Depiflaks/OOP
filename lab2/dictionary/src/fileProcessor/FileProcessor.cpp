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
	if (!file.is_open())
		throw std::runtime_error("File could not be opened");
	readType data;
	file >> data;
	return data;
}

template <typename readType>
void FileProcessor<readType>::WriteData(const readType& data) const
{
	assert(!m_fileName.empty());
	std::ifstream file(m_fileName, std::ios::trunc);
	if (!file.is_open())
		throw std::runtime_error("File could not be opened");
	file << data;
}

template <typename readType>
bool FileProcessor<readType>::isFileNameEmpty() const
{
	return m_fileName.empty();
}

template <typename readType>
void FileProcessor<readType>::setFileName(std::string)
{
	m_fileName = std::move(std::string(m_fileName));
}