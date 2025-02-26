//
// Created by smmm on 12.03.2025.
//

#ifndef FILEPROVIDER_H
#define FILEPROVIDER_H
#include "../dictionary/Dictionary.h"
#include <string>

class DictionaryReader
{
public:
	explicit DictionaryReader(std::optional<std::string> fileName);
	void ReadData(Dictionary& dict) const;
	void WriteData(Dictionary& dict) const;
	[[nodiscard]] bool IsFileNameEmpty() const;
	void SetFileName(const std::string&);

private:
	std::optional<std::string> m_fileName;

	static void LoadFromStream(std::istream& input, Dictionary& dict); void SaveToStream(std::ofstream& output, const Dictionary& dict) const; static void AssertFileCouldBeOpened(std::ifstream& file); static void AssertFileNotEmpty(const std::ifstream& file);
	static void AssertExpectedFileData(const std::ifstream& file);
};

#endif // FILEPROVIDER_H
