//
// Created by smmm on 12.03.2025.
//

#ifndef FILEPROVIDER_H
#define FILEPROVIDER_H
#include <string>

template <typename readType>
class FileProcessor
{
public:
	explicit FileProcessor(std::string fileName);
	readType ReadData() const;
	void WriteData(const readType& data) const;
	bool IsFileNameEmpty() const;
	void SetFileName(std::string);

private:
	std::string m_fileName;

	static void AssertFileCouldBeOpened(std::ifstream& file);
	static void AssertFileNotEmpty(const std::ifstream& file);
	static void AssertExpectedFileData(const std::ifstream& file);
};

#endif // FILEPROVIDER_H
