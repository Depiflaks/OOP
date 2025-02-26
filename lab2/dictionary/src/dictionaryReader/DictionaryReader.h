//
// Created by smmm on 12.03.2025.
//

#ifndef FILEPROVIDER_H
#define FILEPROVIDER_H
#include <string>
#include "../dictionary/Dictionary.h"

class DictionaryReader
{
public:
	explicit DictionaryReader(std::optional<std::string> fileName);
	DictionaryType ReadData() const;
	void WriteData(const DictionaryType& data) const;
	bool IsFileNameEmpty() const;
	void SetFileName(const std::string&);

private:
	std::optional<std::string> m_fileName;

	static void AssertFileCouldBeOpened(std::ifstream& file);
	static void AssertFileNotEmpty(const std::ifstream& file);
	static void AssertExpectedFileData(const std::ifstream& file);
};

#endif // FILEPROVIDER_H
