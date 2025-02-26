//
// Created by smmm on 12.03.2025.
//

#include "FileProcessor.h"

#include <fstream>
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
	std::ifstream file(m_fileName, std::ios::trunc);
	if (!file.is_open())
		throw std::runtime_error("File could not be opened");
	file << data;
}