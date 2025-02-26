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

private:
	std::string m_fileName;
};

#endif // FILEPROVIDER_H
